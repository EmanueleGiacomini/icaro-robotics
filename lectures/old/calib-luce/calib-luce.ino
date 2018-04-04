/*
  calib-luce.ino
  Algoritmo di calibrazione automatica per
  un sensore analogico di luce.
  @author Emanuele Giacomini
*/
// Letture necessarie per calibrare il sensore
#define NUM_LETTURE 10000

// Inizia il processo di calibrazione
// Per il sensore pin.
// Al termine restituisce il valore di soglia ottimale
int calibraLuce(int pin);

// Il pin collegato al sensore di luce
int pin_luce = A1;
// Variabile che salva la soglia calcolata.
int soglia_luce;

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata...");
  pinMode(pin_luce, INPUT);
  Serial.print("La soglia è: ");
  // Utilizzo la funzione per calcolare la soglia
  soglia_luce = calibraLuce(pin_luce);
  Serial.println(soglia_luce);
}

void loop() {
  // Se la lettura è maggiore della soglia calcolata
  // sto vedendo una sorgente luminosa.
  int lettura = analogRead(pin_luce);
  if(lettura > soglia_luce) {
    Serial.println("SORGENTE LUMINOSA RILEVATA");
  }
}

int calibraLuce(int pin) {
  // Definisco tre variabili:
  // lettura -> lettura attuale del sensore
  // min -> valore minimo di lettura
  // max -> valore massimo di lettura
  // min e max inizialmente sono uguali.
  int lettura = analogRead(pin);
  int min = lettura;
  int max = lettura;
  for(int i = 0; i < NUM_LETTURE; i++) {
    // Eseguo NUM_LETTURE letture per
    // stabilire i valori di min e di max.
    lettura = analogRead(pin);
    // Se la lettura è maggiore del massimo allora
    // tale lettura diventa il massimo
    if(lettura > max) {
      max = lettura;
    }
    // Se la lettura è minore del minimo allora
    // tale lettura diventa il minimo
    if(lettura < min) {
      min = lettura;
    }
  }
  // La soglia si costruisce sommando min e max
  // e poi dividendo per 2.
  // Questa è un operazione di media aritmetica.
  int soglia = max + min;
  soglia = soglia / 2;
  return soglia;
}
