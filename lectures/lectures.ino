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
  int* motor_vector = robot.getMotorVector();
  int motor_size = robot.getMotorSize();
  char print_str[64];
  sprintf(print_str, "motor vector size (n. of int elements): %d\n",motor_size);
  Serial.print(print_str);
  delay(100);
  for(int i = 0; i < motor_size; i++){
    Serial.print(motor_vector[i]);
    Serial.print(" - ");
  }
  Serial.println();
}

void loop(){
  robot.goForward(100);
  Serial.println("Going Forward");
  delay(1000);
  robot.goBack(100);
  Serial.println("Going Back");
  delay(1000);
  robot.goLeft(100);
  Serial.println("Going Left");
  delay(1000);
  robot.goRight(100);
  Serial.println("Going Right");
  delay(1000);
}
