// Programa que cuando el potenciómetro supere un umbral, el LED se encenderá

#define PIN_LED 33
#define PIN_POT 32
#define PIN_LDR 35

void setup() {
  // Configuración de los pines
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POT, INPUT);
  pinMode(PIN_LDR, INPUT);

  Serial.begin(115200);
}

void loop() {
  // Código para encender y apagar LED respecto a un LDR
  //int estado_pot = analogRead(PIN_POT);
  //Serial.println(estado_pot/16);
  int estado_ldr = analogRead(PIN_LDR);
  analogWrite(PIN_LED, 255 - estado_ldr/16);
  Serial.println(255 - (estado_ldr/16));

  // for (int i=0; i<256;i++){
  //   analogWrite(PIN_LED, i);
  //   delay(10);
  // }

  // for (int i=255; i>=0; i--){
  //   analogWrite(PIN_LED, i);
  //   delay(10);
  // }

  // int estado_pot = analogRead(PIN_POT);
  // analogWrite(PIN_LED, estado_pot/16);

  delay(50);
}
