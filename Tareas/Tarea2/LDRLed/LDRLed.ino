// Programa que cuando el LDR supere un umbral, el LED se encenderá

#define PIN_LED 33
#define PIN_LDR 35
#define THLRD 300

void setup() {
  // Configuración de los pines
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_LDR, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Código para encender y apagar LED respecto a un LDR
  int estado_ldr = analogRead(PIN_LDR);
  Serial.println(estado_ldr);
  if (estado_ldr < THLRD){ // Si está piluminado el LDR
    digitalWrite(PIN_LED, LOW);
  }
  else { // Si está poco iluminado el LDR
    digitalWrite(PIN_LED, LOW);
  }
  delay(50);
}
