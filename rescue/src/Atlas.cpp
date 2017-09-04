/**
 * Atlas.cpp
 * Purpose: Basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#include "Atlas.h"

Atlas::Atlas(const int* motor_pin, const int* line_sensor_pin){
  for(int i = 0; i < 4; i++){
    _motor_pin[i] = motor_pin[i];
    pinMode(motor_pin[i], OUTPUT);
  }

  for(int i = 0; i < 3; i++){
    _line_sensor_pin[i] = line_sensor_pin[i];
    pinMode(line_sensor_pin[i], INPUT);
  }
  _vel = 100;
}
void Atlas::goForward(){
  digitalWrite(_motor_pin[0], HIGH);
  analogWrite(_motor_pin[1], _vel);
  digitalWrite(_motor_pin[2], LOW);
  analogWrite(_motor_pin[3], _vel);
}
void Atlas::goRight(){
  digitalWrite(_motor_pin[0], LOW);
  analogWrite(_motor_pin[1], _vel);
  digitalWrite(_motor_pin[2], LOW);
  analogWrite(_motor_pin[3], _vel);
}
void Atlas::goLeft(){
  digitalWrite(_motor_pin[0], HIGH);
  analogWrite(_motor_pin[1], _vel);
  digitalWrite(_motor_pin[2], HIGH);
  analogWrite(_motor_pin[3], _vel);
}
void Atlas::goBack(){
  digitalWrite(_motor_pin[0], LOW);
  analogWrite(_motor_pin[1], _vel);
  digitalWrite(_motor_pin[2], HIGH);
  analogWrite(_motor_pin[3], _vel);
}

void Atlas::setVel(const int target_vel){
  _vel = target_vel;
}

void Atlas::update(){
  for(int i = 0; i < 3; i++){
    line_data[i] = analogRead(_line_sensor_pin[i]);
  }
}
