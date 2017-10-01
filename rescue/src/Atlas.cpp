/**
 * Atlas.cpp
 * Purpose: Basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#include "Atlas.h"

Atlas::Atlas(const int* motor_pin, const int* line_sensor_pin, const int* ultrasonic_pin){
  for(int i = 0; i < 4; i++){
    _motor_pin[i] = motor_pin[i];
    pinMode(motor_pin[i], OUTPUT);
  }

  for(int i = 0; i < 3; i++){
    _line_sensor_pin[i] = line_sensor_pin[i];
    pinMode(line_sensor_pin[i], INPUT);
  }

  for(int i = 0; i < 2; i++){
    _ultrasonic_pin[i] = ultrasonic_pin[i];
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

int Atlas::readLine(const int index){
  return analogRead(_line_sensor_pin[index]);
}

int Atlas::readUltrasonic(const int index){
  int pin = _ultrasonic_pin[index];
  unsigned long duration;

  pinMode(pin, OUTPUT);
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  pinMode(pin, INPUT);
  duration = pulseIn(pin, HIGH);
  return int(duration / 58);
}

int Atlas::getLinePos(){
  int line_position = 0;
  for(int i = 0; i < 3; i++){
    if(readLine(i) < _line_threshold[i]){
      // Do stuff
    }
    else {
    }
  }
}
void Atlas::calibrate(){
  int value_max[3] = {0,0,0};
  int value_min[3] = {1024, 1024, 1024};
  unsigned long current_millis, previous_millis;

  previous_millis = millis();

  while(current_millis - previous_millis < CALIBRATION_TIME){
    setVel(100);
    goRight();
    // Get maximum and minimum values for each sensor
    for(int i = 0; i < 3; i++){
      int current_reading = readLine(i);

      if(current_reading > value_max[i]){
        value_max[i] = current_reading;
      }

      if(current_reading < value_min[i]){
        value_min[i] = current_reading;
      }
    }
    current_millis = millis();
  }
  // Calculate thresholds by calculating the gathered data's mean.
  for(int i = 0; i < 3; i++){
    setThreshold(i, (value_max[i] + value_min[i]) / 2);
  }
}
void Atlas::setThreshold(const int index, const int threshold){
  _line_threshold[index] = threshold;
}
