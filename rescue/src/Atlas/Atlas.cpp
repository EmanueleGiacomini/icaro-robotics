/**
 * Atlas.cpp
 * Purpose: Basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#include "Atlas.h"

Atlas::Atlas(const int motor_A, const int pwm_A, const int motor_B, const int pwm_B){
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
  pinMode(pwm_A, OUTPUT);
  pinMode(pwm_B, OUTPUT);
  _motor_A = motor_A;
  _motor_B = motor_B;
  _pwm_A = pwm_A;
  _pwm_B = pwm_B;

  _vel = 100;
}
void Atlas::goForward(){
  digitalWrite(motor_A,HIGH);
  digitalWrite(motor_B,LOW);
  analogWrite(_pwm_A, _vel);
  analogWrite(_pwm_B, _vel);
}
void Atlas::goRight(){
  digitalWrite(motor_A,LOW);
  digitalWrite(motor_B,LOW);
  analogWrite(_pwm_A, _vel);
  analogWrite(_pwm_B, _vel);
}
void Atlas::goLeft(){
  digitalWrite(motor_A,HIGH);
  digitalWrite(motor_B,HIGH);
  analogWrite(_pwm_A, _vel);
  analogWrite(_pwm_B, _vel);
}
void Atlas::goBack(){
  digitalWrite(motor_A,LOW);
  digitalWrite(motor_B,HIGH);
  analogWrite(_pwm_A, _vel);
  analogWrite(_pwm_B, _vel);
}

void Atlas::setVel(const int target_vel){
  _vel = target_vel;
}
