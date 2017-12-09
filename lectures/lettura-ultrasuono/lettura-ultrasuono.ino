/*
  lettura-ultrasuono.ino
  Algoritmo per la lettura di un
  sensore ultrasonico HC-SR04
*/
// Tempo di attesa massimo per il sensore
// 35000 microsecondi corrispondono a circa 5,6 metri.
// Per calcolare la distanza massima usa questa formula:
// Distanza = 325 * timeout(in secondi) / 2
// Es: 325 * 0.035 / 2 = 5,68 metri
#define TIMEOUT_ULTRASUONO 35000

// Legge il sensore ultrasonico connesso ai pin trig ed echo
// ritorna la distanza in cm dall'ostacolo
// Se l'ostacolo è troppo lontano ritorna -1
int leggiUltrasuono(int trig, int echo);

// il trigger invia l'impulso sonico
int trigger_pin = 10;
// l'echo attende che l'impulso torni indietro.
int echo_pin = 9;

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata!");

  pinMode(trigger_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}

void loop() {
  int dist = leggiUltrasuono(trigger_pin, echo_pin);
  if(dist != -1) {
    Serial.print("Distanza ultrasuono: ");
    Serial.println(dist);
  }
}

int leggiUltrasuono(int trig, int echo) {
  // Assicuriamoci che trig sia spento.
  digitalWrite(trig, LOW);
  // Attiviamo trig per 10 microsecondi
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  // Attendiamo il ritorno dell'onda ultrasonica, tenendo conto
  // del tempo trascorso.
  long durata = pulseIn(echo, HIGH, TIMEOUT_ULTRASUONO);
  // Se l'onda ultrasonica impiega più di TIMEOUT_ULTRASUONO microsecondi,
  // pulseIn ritorna 0 (valore di errore)
  if(durata == 0) return -1;
  long distanza = 0.034 * (durata / 2);
  return distanza;
}
