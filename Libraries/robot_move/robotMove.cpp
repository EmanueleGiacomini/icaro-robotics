/**

*/

#include "robotMove.h"


robotMove::robotMove(const char* shield_name){
  // Checks and setup the class by checking which shield the user has choosen.
  if(stringIsEqual(shield_name, 'arduino')){
    _shield = 0;
    _motor_pin = vectorMalloc(sizeof(_ARDUINO_SHIELD_PINOUT));
    _motor_pin_size = sizeof(_ARDUINO_SHIELD_PINOUT) / sizeof(int);
    vectorCopy(_ARDUINO_SHIELD_PINOUT, _motor_pin, _motor_pin_size);

    for(int i = 0; i < 4; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  } else if(stringIsEqual(shield_name, 'seedstudio')){
    _shield = 1;
    _motor_pin = vectorMalloc(sizeof(_SEEDSTUDIO_SHIELD_PINOUT));
    _motor_pin_size = sizeof(_SEEDSTUDIO_SHIELD_PINOUT) / sizeof(int);
    vectorCopy(_SEEDSTUDIO_SHIELD_PINOUT, _motor_pin, _motor_pin_size);
    for(int i = 0; i < 8; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  }
}

void robotMove::goForward(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      digitalWrite(_motor_pin[0], HIGH);
      digitalWrite(_motor_pin[2], LOW);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      digitalWrite(_motor_pin[0],HIGH);
      digitalWrite(_motor_pin[1],LOW);
      digitalWrite(_motor_pin[3],LOW);
      digitalWrite(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goBack(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      digitalWrite(_motor_pin[0], LOW);
      digitalWrite(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      digitalWrite(_motor_pin[0],LOW);
      digitalWrite(_motor_pin[1],HIGH);
      digitalWrite(_motor_pin[3],HIGH);
      digitalWrite(_motor_pin[4],LOW);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goRight(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      digitalWrite(_motor_pin[0], LOW);
      digitalWrite(_motor_pin[2], LOW);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      digitalWrite(_motor_pin[0],LOW);
      digitalWrite(_motor_pin[1],HIGH);
      digitalWrite(_motor_pin[3],LOW);
      digitalWrite(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goLeft(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      digitalWrite(_motor_pin[0], HIGH);
      digitalWrite(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      digitalWrite(_motor_pin[0],HIGH);
      digitalWrite(_motor_pin[1],LOW);
      digitalWrite(_motor_pin[3],HIGH);
      digitalWrite(_motor_pin[4],LOW);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}

void robotMove::stop(){
  switch(_shield){
    case 0: {  // Arduino shield.
      digitalWrite(_motor_pin[0], HIGH);
      digitalWrite(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], 0);
      analogWrite(_motor_pin[3], 0);
      break;
    }
    case 1: {  // Seedstudio shield.
      digitalWrite(_motor_pin[0],HIGH);
      digitalWrite(_motor_pin[1],HIGH);
      digitalWrite(_motor_pin[3],HIGH);
      digitalWrite(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], 0);
      analogWrite(_motor_pin[5], 0);
      break;
    }
  }
}

void robotMove::driveRightMotor(const int speed){
  unsigned int negative_speed = 0;
  if(speed < 0){
    negative_speed = !negative_speed;
  }

  switch(_shield){
    case 0: {  // Arduino shield.
      if(negative_speed){
          digitalWrite(_motor_pin[0], LOW);
      } else {
        digitalWrite(_motor_pin[0], HIGH);
      }

      digitalWrite(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], 0);
      break;
    }
    case 1: {  // Seedstudio shield.
      if(negative_speed){
        digitalWrite(_motor_pin[0],HIGH);
        digitalWrite(_motor_pin[1],LOW);
      } else {
        digitalWrite(_motor_pin[0],LOW);
        digitalWrite(_motor_pin[1],HIGH);
      }
      digitalWrite(_motor_pin[3],HIGH);
      digitalWrite(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], 0);
      break;
    }
  }
}
void robotMove::driveLeftMotor(const int speed){
  unsigned int negative_speed = 0;
  if(speed < 0){
    negative_speed = !negative_speed;
  }

  switch(_shield){
    case 0: {  // Arduino shield.
      if(negative_speed){
          digitalWrite(_motor_pin[2], HIGH);
      } else {
          digitalWrite(_motor_pin[2], LOW);
      }
      digitalWrite(_motor_pin[0], HIGH);
      analogWrite(_motor_pin[1], 0);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      if(negative_speed){
        digitalWrite(_motor_pin[3],HIGH);
        digitalWrite(_motor_pin[4],LOW);
      } else {
        digitalWrite(_motor_pin[3],LOW);
        digitalWrite(_motor_pin[4],HIGH);
      }
      digitalWrite(_motor_pin[0],HIGH);
      digitalWrite(_motor_pin[1],HIGH);

      analogWrite(_motor_pin[2], 0);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}

int robotMove::getShield(){
  return _shield;
}

int* vectorMalloc(const int size){
  return (int*) malloc(size);
}
int stringIsEqual(const char* s1, const char* s2){
  int s1_len = sizeof(s1);
  int s2_len = sizeof(s2);
  // Checks if string sizes are equal.
  if(s1_len == s2_len){
    for(int i = 0; i < s1_len; i++){
      //Checks element by element if the strings are equal.
      if(s1[i] != s2[i]){
        return 0;
      }
    }
    // Strings are equal, therfore returns 1.
    return 1;
  }
  return 0;
}

int* robotMove::getMotorVector(){
  return _motor_pin;
}
int robotMove::getMotorSize(){
  return _motor_pin_size;
}

void vectorCopy(const int* src, int* dest, const int size){
  for(int i = 0; i < size; i++){
    // Copy element by element.
    dest[i] = src[i];
  }
}
