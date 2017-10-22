/*
  Hey there :(
  Don't cheat please ! close this page and go do the exercizes :)
*/

// Seriously don't :|



















#include "p.h"

void p_fibonacci(int iterazioni){
  int primo = 1;
  int secondo = 1;
  int fib;
  Serial.println(primo);
  Serial.println(secondo);
  for(int i = 0; i < iterazioni; i++){
    fib = primo + secondo;
    primo = secondo;
    secondo = fib;
    Serial.println(fib);
  }
}

void p_sort(int n1, int n2, int n3){
  if( n1 >= n2 && n1 >= n3 ){
    if(n2 >= n3){
      // n1 >= n2 >= n3
      Serial.println(n1);
      Serial.println(n2);
      Serial.println(n3);
    } else {
      // n1 >= n3 >= n2
      Serial.println(n1);
      Serial.println(n3);
      Serial.println(n2);
    }
  } else if(n2 >= n1 && n2 >= n3){
    if(n1 >= n3){
      //n2 > n1 > n3
      Serial.println(n2);
      Serial.println(n1);
      Serial.println(n3);
    } else {
      //n2 > n3 > n1
      Serial.println(n2);
      Serial.println(n3);
      Serial.println(n1);
    }
  } else if( n3 >= n1 && n3 >= n2){
    if(n1 >= n2){
      //n3 > n1 > n2
      Serial.println(n3);
      Serial.println(n1);
      Serial.println(n2);
    } else {
      //n3 > n2 > n1
      Serial.println(n3);
      Serial.println(n2);
      Serial.println(n1);
    }
  }
}

int p_pyt_triples(int a, int b, int c){
  if( ( pow(a, 2) + pow(b, 2) ) == pow(c, 2) ){
    return true;
  }
  return false;
}

/*
  RESULTS FOR ARDUINO BASED EXERCIZES
*/
/*
  Dato il circuito in figura (esercArduino_1.jpg)
  Scrivere un programma che accende il led (pin 13) se il tasto è premuto.
*/

/*
if(digitalRead(PIN_TASTO) == HIGH){
  digitalWrite(PIN_LED, HIGH);
} else {
  digitalWrite(PIN_LED, LOW);
}
*/

/*
  Scrivere un programma che scrive sulla seriale "Tasto premuto" quando il tasto
  viene premuto.
  Suggerimento: Chiedete cos'è una variabile statica.
*/

/*
static int previous_state;

int current_state = digitalRead(PIN_TASTO);
if(current_state == HIGH && current_state != previous_state){
    Serial.println("TASTO PREMUTO");
}
previous_state = current_state;
*/

/*
  scrivere un programma che è conta quante volte è stato premuto il tasto.
*/

/*

static int previous_state;
static int volte_premuto = 0;

int current_state = digitalRead(PIN_TASTO);
if(current_state == HIGH && current_state != previous_state){
    volte_premuto++;
    Serial.println(volte_premuto);
}
previous_state = current_state;

*/

/*
  Se il tasto viene premuto un numero pari di volte, si richiede l'accensione del
  led 13 integrato in Arduino.
  suggerimento: utilizzare l'operatore modulo %.
*/

/*
static int previous_state;
static int volte_premuto = 0;

int current_state = digitalRead(PIN_TASTO);
if(current_state == HIGH && current_state != previous_state){
    volte_premuto++;
    Serial.println(volte_premuto);
}
if(( volte_premuto % 2 ) == 0){
  digitalWrite(PIN_LED, HIGH);
} else {
  digitalWrite(PIN_LED, LOW);
}
previous_state = current_state;

*/
