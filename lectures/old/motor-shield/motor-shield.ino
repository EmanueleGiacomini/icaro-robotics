/*
    motor-shield.ino
    esempio per utilizzo shield per motori di Sparkfun

    @author Emanuele Giacomini 10/1/18
*/

// Shortcut per motori
#define MOT_DESTRA 1
#define MOT_SINISTRA 0

// Shortcut per direzioni
#define OR 1  //Direzione OraRia
#define AOR 0 //Direzione Anti OraRia

void muovi(int motore, int dir, int vel);

void avanti(int vel);
void indietro(int vel);
void destra(int vel);
void sinistra(int vel);
void stop();

// ogni array contiene i pin nell seguente ordine:
// 0: Dir - 1: PWM
const int MOT_DESTRA_PIN[] = { 12, 3};
const int MOT_SINISTRA_PIN[] = {13, 11};

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata!");
  for(int i = 0; i < 2; i++) {
    pinMode(MOT_DESTRA_PIN[i], OUTPUT);
    pinMode(MOT_SINISTRA_PIN[i], OUTPUT);
  }
  Serial.println("pinMode motori impostato.");

}

void loop() {
  avanti(150);
  delay(1000);
  destra(150);
  delay(500);
}

void muovi(int motore, int dir, int vel) {
  if(motore == MOT_DESTRA) { // Voglio muovere il motore di destra
    digitalWrite(MOT_DESTRA_PIN[0], dir);
    analogWrite(MOT_DESTRA_PIN[1], vel);
  }
  if(motore == MOT_SINISTRA) { // Voglio muovere il motore di sinistra
    digitalWrite(MOT_SINISTRA_PIN[0], dir);
    analogWrite(MOT_SINISTRA_PIN[1], vel);
  }
}

void avanti(int vel) {
  muovi(MOT_DESTRA, OR, vel);
  muovi(MOT_SINISTRA, AOR, vel);
}
void indietro(int vel) {
  muovi(MOT_DESTRA, AOR, vel);
  muovi(MOT_SINISTRA, OR, vel);
}
void destra(int vel) {
  muovi(MOT_DESTRA, AOR, vel);
  muovi(MOT_SINISTRA, OR, vel);
}
void sinistra(int vel) {
  muovi(MOT_DESTRA, OR, vel);
  muovi(MOT_SINISTRA, OR, vel);
}
void stop() {
  muovi(MOT_DESTRA, OR, 0);
  muovi(MOT_SINISTRA, OR, 0);
}
