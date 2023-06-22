#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Oct  8 17:53:06 2022

@author: oscar
"""

# %% Importar bibliotecas
import awswrangler as wr
#import boto3 
import pandas as pd
# Hay un problema ejecutar prophet con la instalación normal. Parece que lo 
# correcto es desactualizar a la versión 0.24 de la paquetería
# ´holidays´. Se puede hacer desde anaconda o con el comando 
# ´conda install -c conda-forge holidays=0.24´
from prophet import Prophet
from datetime import datetime,timedelta

# %% Consultar fuentes en Amazon

#Timestream

days_ago = 8

query = f"""
select time,
	  measure_value::double as preassure_hPa
from atmosfera_axolote.axolote_oscar_qa
where measure_name = 'press_hPa'
	and time between ago({days_ago}d) and now()
order by time desc
""" 
df = wr.timestream.query(query)
# %% Preprocesamiento
#La consulta de timestream está en formato 'wide'
#Hay que cambiarla a formato 'Long'
# df = df.pivot(index='time', 
#                        columns='measure_name', 
#                        values= ['measure_value::double','measure_value::varchar']).dropna(axis = 1, thresh = 10)


# #Deshacermos de las columnas multinivel
# df.columns = df.columns.get_level_values(1)
# df = df.drop(columns=["device_Id","mac_Id"])

# #Formatear columnas con su tipo de dato
# df["ligh_adim"] = pd.to_numeric(df["ligh_adim"],errors = "coerce")
# df["press_hPa"] = pd.to_numeric(df["press_hPa"],errors = "coerce")
# df["temp_C"] = pd.to_numeric(df["temp_C"],errors = "coerce")
# df.index = pd.to_datetime(df.index)


# %% Previsualizar

#variable = "ligh_adim"
today = datetime.today()
some_days_ago = today - timedelta(days = days_ago)
df.plot(y = 1, x = 0, xlim = [some_days_ago, today])#Subsetting para tener información manejable
#Resampling para tener una frecuencia de discretización constante
#Rolling para eliminar transiciones de alta frecuencia
df_subset = df[df.time>(datetime.today()-timedelta(days = 8))]
df_subset.set_index("time", inplace=True)
df_resamp = df_subset.resample('10min').mean().interpolate()
df_rolling = df_resamp.rolling(5).mean()

df_subset.plot(y = 0, use_index = True)
df_resamp.plot(y = 0, use_index = True)
df_rolling.plot(y = 0, use_index=True )
# %%Prophet fit
df_prophet = pd.DataFrame()
df_prophet["y"] = df_rolling.preassure_hPa
df_prophet["ds"] = df_rolling.index.tz_localize(None)

m = Prophet(changepoint_prior_scale=0.001).fit(df_prophet)
# %% Prophet predictions
future = m.make_future_dataframe(periods=12, freq='H')
fcst = m.predict(future)
fig = m.plot(fcst)

# %% Escribiendo a S3
wr.s3.to_parquet(

    df=fcst,

    path='s3://predicciones-prophet-oscar-qa/predictions_prophet_parquet.gzip',
    
    compression = "gzip"

)