/*
  Basics_1
  Purpose: Teach Icaro students how to properly code :).
*/

////////////// INCLUDE LIBRARIES ///////////
#include <math.h>
#include <Wire.h>
#include <LiquidCrystal.h>

////////////// VARIABLES & COSTANTS ///////

int integer = 32767; // (2 bytes) = 2^16 values. POSITIVE AND NEGATIVE
const int COSTANT_INTEGER_PI = 42; // Answer to everything.
unsigned int positive_integer = 13; // (2 bytes) = 2^16 values. ONLY POSITIVE.
// unsigned int pippo = -134; NO!!
long int longer_integer = 2147483647 //loooong (4 bytes) = 2^32 values. POSITIVE AND NEGATIVE

float floating_point_value = 3.141592; // decimal point values. (4 bytes) goes from very little to REALLY BIG
                                      // (3.4028235*10^38) vs unsigned long (2.1474836*10^9)
double same_as_float = 3.141592; // on arduino uno and mega (4 bytes). On arduino due (8 bytes) = WAY TO BIG.

char character = 'X' // ASCII equals to 88

#define ANSWER_TO_UNIVERSE 42

////////////// COMMENTS ////////////

// Questo è un commento !

/*
  Anche questo è un commento !
  Solo che più grande ;)


  Eh si.
  ..
  .
*/

// setup: AREA OF SOFTWARE WHERE CODE IS ONLY REPEATED ONCE.
void setup(){
  // Why the comment is traslated ?
  // ITS CALLED INDENTAZIONE
  same_as_float = 4023.12;
  Wire.begin();
// this is bad inside a function
  /*
Serial.begin(9600); // NOT GOOD
  Serial.begin(9600); // GOOD
  */

  // How do you print on the console ?
  Serial.print("Hello world!");
  // come si và a capo ? (aka go new line)
  Serial.print("\n Hello again world!");
  // or
  Serial.println("Hello world!");

  int x = 0;
  int y = 15;
  Serial.print("X is ");
  Serial.println(x);
  x = x + y;
  Serial.print("X now is ");
  Serial.println(x);
}
/*
  int pippo = ANSWER_TO_UNIVERSE; // SBAGLIATO
int pippo = ANSWER_TO_UNIVERSE // Giusto!
*/
// loop: AREA WHERE CODE IS BEGIN REPEATED OVER AND OVER.
void loop(){
  /*
   Esercizio: Calcolare le radici di un polinomio di primo grado
   ax + b = 0
   STEPS:
   ax + b = 0
   ax = -b
   x = -b/a
   Provare:
   a = 2, b = 2 (x1 = 1)
   se a = 2, b = 1 ? il risultato è un intero ?


   Esercizio: Calcolare le radici di un polinomio di secondo grado
   ax^2 + bx + c = 0
   calcolo il delta:
   b^2 + 4*a*c
   le radici si trovano con la formula
   x1 = (-b + sqrt(delta)) / (2*a)
   x2 = (-b - sqrt(delta)) / (2*a)
   Provare:
   x^2 - 1 = 0 ( -1, +1)
   x^2 - 2x = 0 ( 0, 2)
   x^2 = 0 ( 0, 0)
   3x^2 - 2x - 4 = 0 (-0.869, 1.535);
  */



}
