/*
  lezione-motori.ino
  Utilizzo di un circuito monodirezionale per un
  motore.
  @author Emanuele Giacomini 13/12/2017
*/

// Accende il motore in modo digitale ( 0 - 1)
void accendiMotore(int pin);

// Spegne il motore
void spegniMotore(int pin);

// Accende il motore in modalità analogica ( PWM )
// la velocita và da 0 a 255.
void velocitaMotore(int pin, int vel);

int mot_a = 10; // Pin a cui il motore è collegato.

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata!");

  pinMode(mot_a, OUTPUT);

}

void loop() {
  Serial.println(F("Accendo il motore per 2 secondi"));
  accendiMotore(mot_a);
  delay(2000);
  Serial.println(F("Spengo il motore per 1 secondo"));
  spegniMotore(mot_a);
  delay(1000);
  Serial.println(F("Imposto la velocità a 50 per 1 secondo"));
  velocitaMotore(mot_a, 50);
  delay(1000);
  Serial.println(F("Imposto la velocità a 100 per 1 secondo"));
  velocitaMotore(mot_a, 100);
  delay(1000);
  Serial.println(F("Imposto la velocità a 200 per 1 secondo"));
  velocitaMotore(mot_a, 200);
  delay(1000);
  Serial.println(F("Imposto la velocità a 255 per 1 secondo"));
  velocitaMotore(mot_a, 255);
  delay(1000);

}

void accendiMotore(int pin) {
  // impostando il pin ad HIGH
  // chiudiamo il circuito e il motore si avvia
  digitalWrite(pin, HIGH);
}

void spegniMotore(int pin) {
  // impostando il pin ad LOW
  // apriamo il circuito e il motore si ferma
  digitalWrite(pin, LOW);
}

// PRIMA LEGGI COME FUNZIONA IL PWM
// http://www.maffucci.it/2011/11/29/arduino-lezione-06-modulazione-di-larghezza-di-impulso-pwm/
void velocitaMotore(int pin, int vel) {
  // se vel = 255 analogWrite corrisponde a digitalWrite(pin, HIGH);
  // se vel = 0 analogWrite corrisponde a digitalWrite(pin, LOW);

  // Gli intermedi non sono replicabili con digitalWrite
  analogWrite(pin, vel);
}
