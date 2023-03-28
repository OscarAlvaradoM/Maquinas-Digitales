// Programa que cuando presione el botón, el LED se encenderá

#define PIN_LED 33
#define PIN_BOTON 34

void setup() {
  // Configuración de los pines
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BOTON, INPUT);

  Serial.begin(115200);
}

void loop() {
  // Código para encender y apagar LED respecto a un botón
  bool estado_boton = digitalRead(PIN_BOTON);
  Serial.println(estado_boton);
  if (estado_boton){ // Si está presionado el botón
    digitalWrite(PIN_LED, HIGH);
  }
  else { // Si está apagado el botón
    digitalWrite(PIN_LED, LOW);
  }
  delay(100);
}
