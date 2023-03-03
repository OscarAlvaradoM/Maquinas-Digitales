#include "Adafruit_BMP085.h"
#include "BluetoothSerial.h"

//Loguear la info dle sensor barometrico y LDR
#define LED_PIN 33
#define LDR_PIN 35

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

Adafruit_BMP085 bmp; //Objeto bmp

char payload [80]; //payload de lecturas

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32-Oscar"); //Bluetooth device name
  Serial.println("Bluetooth configurado!");

  pinMode(LED_PIN, OUTPUT);
  Serial.begin(115200);
  bmp.begin(0x76);
  //Montarlo. Si falla, manda mensaje de error

}

void loop() {

  //Hacer el payload de lecturas de sensores
  sprintf(payload,"%6.2f,%3.2f,%d",
          bmp.readPressure(),
          bmp.readTemperature(),
          analogRead(LDR_PIN));

  digitalWrite(LED_PIN,HIGH);
  SerialBT.println(payload);
  Serial.println(payload);
  digitalWrite(LED_PIN,LOW);

   delay(1000);  

}