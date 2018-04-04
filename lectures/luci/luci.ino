/**
 * luci.ino
 * Breve guida per l'uso dei sensori di luce
 * @author Emanuele Giacomini 4/4/2018
 */

// Scelgo un pin analogico arbitrario per questo esempio
int pin_luce = A2;

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata!");

  // IMPORTANTE
  // Ricordiamoci sempre di comunicare al microcontrollore che, i pin usati
  // sono Input (in questo caso)
  pinMode(pin_luce, INPUT);
}

// Prima di passare al loop, vogliamo costruirci una funzione che prenda
// in input il pin relativo al sensore di luce, una soglia
// (vedremo come ricavarla), e ci restituisca l'informazione di sorgente di luce
// visibile

int leggiLuce(int pin, int soglia) {
  if(analogRead(pin) > soglia) {
    // La lettura supera la soglia
    // dunque vedo una sorgente di luce e restituisco 1
    return 1;
  } else {
    return 0;
  }
}

// La funzione ha senso se riusciamo a trovare un valore di soglia corretto.
// Scriviamo una funzione che, dato un pin relativo al sensore di luce, ci
// restituisca la sua soglia.
// Durante l'esecuzione del programma, bisognera' mostrare al sensore, un ambiente
// sia privo che completo di sorgenti di luce (cosi da poter distinguere i due casi)

// TEMPO_CALIBRAZIONE rappresenta il periodo di calibrazione in millisecondi
#define TEMPO_CALIBRAZIONE 3000

int calibraLuce(int pin) {
  long inizio_millis = millis();
  int lettura = analogRead(pin);
  int min = lettura;
  int max = lettura;
  while( millis() - inizio_millis < TEMPO_CALIBRAZIONE) {
    lettura = analogRead(pin);
    if(lettura > max) {
      max = lettura;
    }
    if(lettura < min) {
      min = lettura;
    }
  }
  // Dopo TEMPO_CALIBRAZIONE millisecondi, esco e calcolo la soglia
  return (min + max) / 2;
}


void loop() {

}
