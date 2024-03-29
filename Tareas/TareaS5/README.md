<div align="center"><h1 style="text-align: center;">Tarea 4</h1></div>
<div align="center"><h2 style="text-align: center;">Máquinas Digitales con Laboratorio</h2></div>
<div align="center"><h3 style="text-align: center;">Óscar Alvarado</h3></div>

**Json Parser y SPIFFS**

- Captura de la prueba exitosa del sistema de archivos SPIFFS.

<p style="text-align:center;"><img src="prueba_spiffs.jpg" alt="Prueba SPIFFS" width="50%" height="50%"></p>

- Responder: ¿Para qué queremos un sistema de archivos como SPIFFS? Da un ejemplo de uso.

    Según entiendo, es como una API para poder subir archivos de manera fácil a la memoria de nuestro ESP32. Un ejemplo de uso sería poner archivos como de contraseñas, para que se manden datos a algún servidor sin tener que estar pasando siempre las contraseñas.

- Captura de la extensión "ESP32 Sketch Data upload" instalada en Arduino IDE V1

<p style="text-align:center;"><img src="extension_data_upload.png" alt="ESP32 Sketch Data Upload" width="70%"></p>

- Responder: ¿Por qué no podemos instalar Sketch Data Upload en Arduino IDE V2?

    Según entiendo, no se ha actualizado a la V2 de Arduino IDE, ya que es la versión oficial de manera muy reciente.

- Captura de las lecturas de los sensores imprimiéndose en el monitor serie con formato json, usando el programa "json_serializer"

<p style="text-align:center;"><img src="json_parser.jpg" alt="Imprimiendo lecturas en la terminal serial con formato JSON" width="70%"></p>

- Push con el programa "json_serializer", el cual serialice las lecturas de los sensores en formato json y los imprima en el monitor serie.

<p style="text-align:center;"><img src="push_json_parser.png" alt="Push del código jsonParser_test" width="70%"></p>

**Módulo RF**

- Video en donde se vea que el celular envíe y reciba caracteres desde y hacia el ESP, usando el programa de ejemplo de Bluetooth que usamos en clase. Se tiene que ver simultáneamente el uso de la app "Terminal Bluetooth" y el monitor serial de Arduino.

[![Video Ping Pong Bluetooth](https://img.youtube.com/vi/JdpE_k0nW9o/hqdefault.jpg)](https://youtu.be/JdpE_k0nW9o)

- Captura de pantalla de la recepción de lecturas de los sensores en la Terminal Bluetooth del celular.

<p style="text-align:center;"><img src="lectura_sensores_BT.jpg" alt="Lectura serial de BT en la terminal del celular" width="30%" height="30%"></p>

- Captura de la conexión al WiFi local con ESP32. Debe mostrarse el SSID y la IP asignada al ESP.

<p style="text-align:center;"><img src="conexion_wifi.png" alt="Prueba de conexión wifi con el ESP32" width="70%" height="70%"></p>

- Captura de la prueba de Ping al ESP32 desde la terminal de la PC.

<p style="text-align:center;"><img src="ping_esp32.png" alt="Prueba de conexión wifi con el ESP32 mediante un ping" width="70%" height="50%"></p>

- Captura del archivo "Credentials.h".

<p style="text-align:center;"><img src="archivo_credentials.png" alt="Captura del archivo Credentials.h" width="70%" height="50%"></p>

- Responder: ¿Podemos usar simultáneamente WiFi y Bluetooth con ESP32?

    No, la ESP sólo permite una conexión a la vez.

- Responder: ¿Por qué creamos Credentials.h?

    Para no *hardcodear* nuestros sketches y que las contraseñas que tengamos para ciertas cosas no estén abiertas al público.

- Push con los programas "Bluetooth_logger" y "Conexion_WiFi". Advertencia: Si hay claves hardcodeadas, hay tabla.

<p style="text-align:center;"><img src="capturas_push.png" alt="Capturas del push que se hizo de los archovps de la tarea" width="85%" height="85%"></p>