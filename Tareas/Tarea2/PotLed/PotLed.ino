#define PIN_LED 33
#define PIN_POT 32
#define THPOT 2000

void setup() {
  // Configuración de los pines
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_POT, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Código para encender y apagar LED respecto a un Potenciómetro
  int estado_pot = analogRead(PIN_POT);
  Serial.println(estado_pot);
  if (estado_pot < THPOT){ // Si está piluminado el Potenciómetro
    digitalWrite(PIN_LED, HIGH);
  }
  else { // Si está poco iluminado el Potenciómetro
    digitalWrite(PIN_LED, LOW);
  }
  delay(50);
}
