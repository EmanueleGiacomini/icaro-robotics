/**
  Exercises_2.ino
  purpose: Iniziare a prendere confidenza con le funzioni
           di Arduino ;)
  @author Emanuele Giacomini
  @version 0.1 26/10/17
*/

// Imparate ad inserire un commento come questo all'inizio
// del vostro file per sapere cosa guarderete.

////////////// INCLUDE LIBRARIES ///////////
#include <math.h>
#include "src/p2.h"


////////////// VARIABILI ///////////////////
#define LIGHT_SENSOR_PIN A0
#define BUTTON_PIN 7
#define LED_PIN 6

////////////// FUNZIONI ////////////////////

/*
  Funzione che ritorna 1 se il pin ha cambiato stato dall'ultima
  iterazione, 0 altrimenti.
  Tip: variabili statiche.
  Pro Tip: qual'era lo stato precedente ?
*/
int stateChange(int pin){
}

/*
  Si faccia una lettura di tipo analogica.
  In caso la lettura sia maggiore di una certa soglia,
  si ritorni 1. 0 altrimenti.
*/
int analogToDigital(int pin, int soglia){

}

void setup(){

  // Inizializza il canale seriale

  // Stampa qualcosa per confermare
  // l'attivazione del canale seriale
  // i.e: "Seriale inizializzata."

  // Definisci i ruoli dei pin sopra definiti
  // BUTTON_PIN è un input o un output ?


  // Stampa qualcosa per confermare l'uscita dal setup
  // i.e: "Setup completo."
}

void loop(){

}
