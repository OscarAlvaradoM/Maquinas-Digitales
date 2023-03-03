import boto3
import awswrangler as wr

# Para crear el cliente
s3 = boto3.client("s3")

# Enlistando buckets
response = s3.list_buckets()

# Abriendo archivos de S3 (Pasa el link en el chat en el minuto 2:11:36)
df = wr.s3.read_json(path='s3://embebed-cloud-iot-firehose-stream/2022/11/15/20/axolote_iot_devices_embebed_cloud-2-2022-11-15-20-22-53-3008dfc1-257a-41a7-9889-f7e3d7f150a5.gz',
                     compression = 'gzip',
                     lines=True)