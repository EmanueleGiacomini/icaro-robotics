/*
  Hey there :(
  Don't cheat please ! close this page and go do the exercizes :)
*/

// Seriously don't :|



















#include "p2.h"


int p_stateChange(int pin){
  static int previous_state = 0;
  int current_state = digitalRead(pin);
  if(previous_state != current_state && previous_state == 0){
    previous_state = current_state;
    return 1;
  }
  previous_state = current_state;
  return 0;
}


int p_analogToDigital(int pin, int soglia){
  int reading = analogRead(pin);
  if(reading >= soglia){
    return 1;
  }
  return 0;
}

int p_showGraph(int pin, int soglia){
  Serial.print(analogRead(pin));
  Serial.print("\t");
  Serial.print(p_analogToDigital(pin, soglia) * soglia);
  Serial.print("\t");
  Serial.println(1023);
}
