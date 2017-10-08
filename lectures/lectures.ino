/**
  lectures.ino
  Purpose: Test field for Icaro lectures.

  @author E. Giacomini
  @version 1.0 18/09/17
*/

#include "src/robotMove.h"

robotMove robot('seedstudio');

void setup(){
  Serial.begin(9600);
  Serial.println("Serial initialized!");
  delay(100);
}

void loop(){
}
