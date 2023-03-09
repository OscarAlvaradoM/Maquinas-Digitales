#include "FS.h"
#include "SD.h"
#include "SPI.h"

#include "Adafruit_BMP085.h"

Adafruit_BMP085 bmp;
File readings;
char payload [80];
#define LED_PIN 33
#define PIN_LDR 35

void setup() {
  // Configuración inicial
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIN_LDR, INPUT);
  if(!SD.begin()){
    Serial.println("No se ha podido leer la tarjeta SD");
    return;
  }
  if (!bmp.begin(0x77)) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}

void loop() {
  // El código que se repetira en el ESP32 mientras esté encendido

  // Hacemos el payload de lecturas
  float pressure_float = bmp.readPressure() * 0.001;
  sprintf(payload, "%6.2f, %6.2f , %d",
    pressure_float,
    bmp.readTemperature(),
    analogRead(PIN_LDR));
  // Prendemos un led cada que escribimos algo
  digitalWrite(LED_PIN, HIGH);
    readings = SD.open("/lecturas_sensor.csv", FILE_APPEND);
    readings.println(payload);
    readings.close();
    Serial.println(payload);
  digitalWrite(LED_PIN, LOW);
  delay(500);

}
