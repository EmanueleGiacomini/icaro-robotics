/*
  Esercizi base per programmare con gli array
*/

#include "src/p.h"
#include <math.h>

// Scrivi qui dentro una funzione che ritorni il
// contenuto di un array ad un dato indice
int leggiElemento(int v[], int indice) {
  return -1;
}
// Scrivi qui dentro una funzione che scriva numero dentro
// array nella posizione indice
void scriviElemento(int v[], int indice, int numero) {

}
// Scrivi qui dentro una funzione che scriva numero dentro
// tutte le celle di array di dimensione pari a dim
void scriviArray(int v[], int dim, int numero) {

}
// Scrivi qui dentro una funzione che cerchi numero
// all'interno di array di dimensione pari a dim
int trovaNumero(int v[], int dim, int numero) {
}

// Scrivi qui dentro una funzione che ritorni il numero
// di elementi pari all'interno di un vettore v grande dim.
int trovaPari(int v[], int dim) {
  return -1;
}

// Scrivi qui dentro una funzione che ritorni quante volte
// numero è presente all'interno del array v.
int frequenzaNum(int v[], int dim, int numero) {
  return -1;
}

void setup() {
  Serial.begin(9600);
  Serial.println("Seriale inizializzata");

  char buf[64];

  int v[] = { 0, 0, 152, 32, 332};
  int v_dim = 5;
  int perc = 0;
  int correct = 100 / v_dim;
  Serial.println("TEST leggiElemento");
  for(int i = 0; i < v_dim; i++) {
    sprintf(buf, "Tuo risultato: %d\t Soluzione: %d\n", leggiElemento(v, i), vec_getElem(v, i));
    Serial.write(buf);
    perc += correct * (leggiElemento(v, i) == vec_getElem(v, i));
  }
  sprintf(buf, "Percentuale correttezza: %d", perc);
  Serial.write(buf);
}

void loop() {

}
