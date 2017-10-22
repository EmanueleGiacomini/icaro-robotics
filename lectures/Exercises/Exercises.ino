#include <math.h>
#include "src/p.h"


// LE PROSSIME DUE RIGHE SARANNO UTILI PIU' TARDI
const int PIN_TASTO = 7;
const int PIN_LED = 13;
///////////////////////////////////////////////////


/*
  Completa le funzioni indicate qui sotto.
*/

/*
  Scrivere il programma per stampare
  n iterazioni della successione di fibonacci.
  La successione è tale per cui ogni numero è la somma
  dei due precedenti e i primi due termini della successione
  sono per definizione n1 = 1 e n2 = 1
  Esempio:
  1 - 1 - 2 - 3 - 5 - 8 ecc
*/
void fibonacci(int n){

}

/*
  Scrivere il programma che, dati 3 numeri non ordinati,
  li stampi in ordine decrescente.
  Esempio:
  n1 = 3, n2 = 1, n3 = 154
  deve stampare
  154
  3
  1
*/
void sort(int n1, int n2, int n3){

}

/*
  Scrivere il programma che ritorni true se la terna di numeri
  data è una terna pitagorica, e ritorni false altrimenti.
  Le terne pitagoriche sono del tipo (a)^2 + (b)^2 = (c)^2
  IMPORTANTE: per rappresentare un elevazione a potenza del tipo
  a ^ b usa pow(a, b) della libreria math.h

  Esempio:
  (3)^2 + (4)^2 = (5)^2 -> è una terna pitagorica -> return true
  (5)^2 + (12)^2 = (13)^2 -> è una terna pitagorica -> return true
  (1)^2 + (2)^2 = (3)^2 -> non è una terna pitagorica -> return false
*/
int pyt_triples(int a, int b, int c){
  return false;
}


void setup(){
  // Per avviare un tester rimuovi
  // all'inizio e alla fine della sezione
  // i caratteri /* e */. Prova
  /*
  Serial.println("Hello world!");
  */
  // aggiungili quando vuoi commentare il tester.

  // DO NOT TOUCH HERE.
  Serial.begin(9600);
  char buf[32];
  /////////////////////

  // TESTER DI FIBONACCI
  // RIMUOVI /* E */ all'inzio e alla fine della sezione per avviare

/*

  int it[] = { 0, 1, 5, 7 };
  Serial.println("TESTING fibonacci FUNCTION: ");
  for(int i = 0; i < 4; i++){
    sprintf(buf,"testing %d iterations:\n", it[i] );
    Serial.print(buf);
    Serial.println("Il tuo risultato è:");
    fibonacci(it[i]);
    Serial.println("La soluzione è:");
    p_fibonacci(it[i]);
    Serial.print("\n");
  }
  Serial.println("END OF TESTING");

*/


  // TESTER SORT
  // RIMUOVI /* E */ all'inzio e alla fine della sezione per avviare.

/*

  int testing_triplet[4][3] = {{1, 2, 3}, {3, 6, 15}, {0, 0, 0}, {1534, 123, 443}};

  Serial.println("TESTING sort FUNCTION: ");
  for(int i = 0; i < 4; i++){
    sprintf(buf, "Sorting [ %d, %d, %d ] :\n", testing_triplet[i][0], testing_triplet[i][1], testing_triplet[i][2]);
    Serial.print(buf);
    Serial.println("Il tuo risultato è:");
    sort(testing_triplet[i][0], testing_triplet[i][1], testing_triplet[i][2]);
    Serial.println("La soluzione è:");
    p_sort(testing_triplet[i][0], testing_triplet[i][1], testing_triplet[i][2]);
    Serial.print("\n");
  }
  Serial.println("END OF TESTING");

*/


  // TESTER pyt_triples
  // RIMUOVI /* E */ all'inzio e alla fine della sezione per avviare.

/*

  int testing_triples[5][3] = {{3, 4, 5}, {1, 5, 13}, {5, 10, 2}, {5, 12, 13}, {9, 40, 41} };
  int percentage = 0;

  Serial.println("TESTING sort FUNCTION: ");
  for(int i = 0 ; i < 5; i++){
    sprintf(buf, "Testing the triple [ %d, %d, %d ] :\n", testing_triples[i][0], testing_triples[i][1], testing_triples[i][2] );
    Serial.print(buf);
    Serial.println("Il tuo risultato è:");
    int result = pyt_triples(testing_triples[i][0], testing_triples[i][1], testing_triples[i][2]);
    int p_result = p_pyt_triples(testing_triples[i][0], testing_triples[i][1], testing_triples[i][2]);
    Serial.println(result);
    Serial.println("La soluzione è:");
    Serial.println(p_result);

    if(p_result == result){
      percentage += 20;
      sprintf(buf, "CORRETTO !\tPercentuale di successo: %d\n", percentage);
      Serial.print(buf);
    } else {
      sprintf(buf, "NON CORRETTO !\tPercentuale di successo: %d\n", percentage);
      Serial.print(buf);
    }
    Serial.print("\n");
  }
  Serial.println("END OF TESTING");

*/


// PRIMA DI INIZIARE GLI ESERCIZI DEDICATI AD ARDUINO:
// togliere il commento alle prossime due righe.
 pinMode(PIN_TASTO, INPUT);
 pinMode(PIN_LED, OUTPUT);


}



void loop(){

  // Esercizi dedicati di Arduino.
  /*
    Dato il circuito in figura (esercArduino_1.jpg)
    Scrivere un programma che accende il led (pin 13) se il tasto è premuto.
  */

  /*
    Scrivere un programma che scrive sulla seriale "Tasto premuto" quando il tasto
    viene premuto.
    Suggerimento: Chiedete cos'è una variabile statica.
  */

  /*
    scrivere un programma che è conta quante volte è stato premuto il tasto.
  */

  /*
    Se il tasto viene premuto un numero pari di volte, si richiede l'accensione del
    led 13 integrato in Arduino.
    suggerimento: utilizzare l'operatore modulo %.
  */
}
