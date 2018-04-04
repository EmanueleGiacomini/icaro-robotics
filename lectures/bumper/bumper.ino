/**
 * bumper.ino
 * Breve guia all'uso dei bumper
 * @author Emanuele Giacomini 4/4/2018
 */

// Scelgo due pin digitali arbitrari per questo esempio
int pin_bumper_dx = 12;
int pin_bumper_sx = 11;

void setup() {
    Serial.begin(9600);
    Serial.println("Seriale inizializzata!");

    // IMPORTANTE
    // Ricordiamoci sempre di comunicare al microcontrollore che, i pin usati
    // sono Input (in questo caso)
    pinMode(pin_bumper_dx, INPUT);
    pinMode(pin_bumper_sx, INPUT);
}

// Prima di passare al loop, vogliamo costruirci una funzione che prenda
// in input il pin relativo al bumper, e ne restituisca il suo
// stato aperto / chiuso

int leggiBumper(int pin) {
  return digitalRead(pin);
}

// Possiamo utilizzare questa funzione ora per sviluppare una funzione piu'
// complessa che, dati due bumper, restituisce un valore che indica quale bumper
// viene chiuso.

// In maniera completamente arbitraria scelgo che questa funzione restituira':
// 1 -> entrambi i sensori sono chiusi
// 2 -> solo il sensore di destra e' chiuso
// 3 -> solo il sensore di sinistra e' chiuso
// 0 -> nessun sensore e' chiuso

int leggiOstacoli(int pin_dx, int pin_sx) {
  int lettura_dx = leggiBumper(pin_dx);
  int lettura_sx = leggiBumper(pin_sx);

  if(lettura_dx == 1 && lettura_sx == 1) {
    // Entrambi i sensori sono attualmente chiusi
    return 1;
  } else if(lettura_dx == 1 && lettura_sx == 0) {
    // Solo il sensore di destra e' attualmente chiuso
    return 2;
  } else if(lettura_dx == 0 && lettura_sx == 1) {
    // Solo il sensore di sinistra e' attualmente chiuso
    return 3;
  } else {
    // Nessun sensore e' attualmente chiuso. Restituisco 0
    return 0;
  }
}

// Con queste due funzioni possiamo finalmente guardare il loop !

void loop() {
  int stato_bumper = leggiOstacoli(pin_bumper_dx, pin_bumper_sx);
  switch(stato_bumper) {
    case 1: {
      Serial.println("Entrambi i bumper sono chiusi!");
      delay(300);
      break;
    }
    case 2: {
      Serial.println("Il bumper di destra e' chiuso!");
      delay(300);
      break;
    }
    case 3: {
      Serial.println("Il bumper di sinistra e' chiuso!");
      delay(300);
      break;
    }
  }


}
