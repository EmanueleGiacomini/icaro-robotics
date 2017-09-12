/**
 * Ulisse.cpp
 * Purpose: Basic interface for icaro explorer robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */
#include "Ulisse.h"

Ulisse::Ulisse(const int* motor_pin, const int* light_sens_pin, const int* bumper_pin){
  for(int i = 0; i < 4; i++){
    pinMode(motor_pin[i],OUTPUT);
    _motor_pin[i] = motor_pin[i];
  }
  _vel = 100;
  for(int i = 0; i < 3; i++){
    pinMode(light_sens_pin[i],INPUT);
    _light_sens_pin[i] = light_sens_pin[i];
  }
  for(int i = 0; i < 3; i++){
    pinMode(bumper_pin[i],INPUT);
    _bumper_pin[i] = bumper_pin[i];
  }
}
void Ulisse::goForward(){
  digitalWrite(_motor_pin[0],HIGH);
  digitalWrite(_motor_pin[2],LOW);
  analogWrite(_motor_pin[1], _vel);
  analogWrite(_motor_pin[3], _vel);
}
void Ulisse::goRight(){
  digitalWrite(_motor_pin[0],LOW);
  digitalWrite(_motor_pin[2],LOW);
  analogWrite(_motor_pin[1], _vel);
  analogWrite(_motor_pin[3], _vel);
}
void Ulisse::goLeft(){
  digitalWrite(_motor_pin[0],HIGH);
  digitalWrite(_motor_pin[2],HIGH);
  analogWrite(_motor_pin[1], _vel);
  analogWrite(_motor_pin[3], _vel);
}
void Ulisse::goBack(){
  digitalWrite(_motor_pin[0],LOW);
  digitalWrite(_motor_pin[2],HIGH);
  analogWrite(_motor_pin[1], _vel);
  analogWrite(_motor_pin[3], _vel);
}

void Ulisse::stop(){
  digitalWrite(_motor_pin[0],HIGH);
  digitalWrite(_motor_pin[2],HIGH);
  analogWrite(_motor_pin[1], 0);
  analogWrite(_motor_pin[3], 0);
}

void Ulisse::setVel(const int target_vel){
  _vel = constrain(target_vel, 0, 255);
}

void Ulisse::update(){
  for(int i = 0; i < sizeof(_light_sens_pin) / sizeof(int); i++){
    lightData[i] = analogRead(_light_sens_pin[i]);
  }

  for(int i = 0; i < sizeof(_bumper_pin) / sizeof(int); i++){
    bumperData[i] = analogRead(_bumper_pin[i]);
  }
}

int Ulisse::heatGasSensor(){
}

int Ulisse::gasReady(){

}

int Ulisse::readGas(){

}
