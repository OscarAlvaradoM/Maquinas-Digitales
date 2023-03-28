// Código para que se esté graficando en el graficador serial los valores que obtenemos de 
// temperatura y presión del sensor bmp180.
#include <Adafruit_BMP085.h>

Adafruit_BMP085 bmp;

void setup() {
  // Inicializando el programa
  Serial.begin(115200);
  if (!bmp.begin(0x77)) {
  Serial.println("Could not find a valid BMP085 sensor, check wiring!");
  while (1) {}
  }
}

void loop() {
  // Código para repetir en la placa.
  // Utilizamos un payload
  char payload[40];
  float pressure_float = bmp.readPressure() * 0.001;
  sprintf(payload, "%.2f, %3.2f", pressure_float, bmp.readTemperature());
  Serial.println(payload); // Imprimimos el payload tal como lo construimos arriba
  delay(200);
}
