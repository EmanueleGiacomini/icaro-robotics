/**
  lectures.ino
  Purpose: Test field for Icaro lectures.

  @author E. Giacomini
  @version 1.0 18/09/17
*/

#include "src/robotMove.h"

robotMove robot('arduino');

void setup(){
  Serial.begin(9600);
}

void loop(){
  robot.goForward(100);
  delay(1000);
  robot.goLeft(100);
  delay(1000);
  robot.goRight(100);
  delay(1000);
  robot.goBack(100);
  delay(1000);
  robot.stop();
  delay(1000);

}
