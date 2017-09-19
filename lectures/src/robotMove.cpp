/**

*/

#include "robotMove.h"


robotMove::robotMove(const char* shield_name){
  // Checks and setup the class by checking which shield the user has choosen.
  if(stringIsEqual(shield_name, 'arduino')){
    _shield = 0;
    _motor_pin = vectorMalloc(sizeof(_ARDUINO_SHIELD_PINOUT));
    vectorCopy(_ARDUINO_SHIELD_PINOUT, _motor_pin);

    for(int i = 0; i < 4; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  } else if(stringIsEqual(shield_name, 'seedstudio')){
    _shield = 1;
    _motor_pin = vectorMalloc(sizeof(_SEEDSTUDIO_SHIELD_PINOUT));
    vectorCopy(_SEEDSTUDIO_SHIELD_PINOUT, _motor_pin);
    for(int i = 0; i < 8; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  }
}

void robotMove::goForward(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      pinMode(_motor_pin[0], HIGH);
      pinMode(_motor_pin[2], LOW);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      pinMode(_motor_pin[0],HIGH);
      pinMode(_motor_pin[1],LOW);
      pinMode(_motor_pin[3],LOW);
      pinMode(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goBack(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      pinMode(_motor_pin[0], LOW);
      pinMode(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      pinMode(_motor_pin[0],LOW);
      pinMode(_motor_pin[1],HIGH);
      pinMode(_motor_pin[3],HIGH);
      pinMode(_motor_pin[4],LOW);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goRight(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      pinMode(_motor_pin[0], LOW);
      pinMode(_motor_pin[2], LOW);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      pinMode(_motor_pin[0],LOW);
      pinMode(_motor_pin[1],HIGH);
      pinMode(_motor_pin[3],LOW);
      pinMode(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}
void robotMove::goLeft(const int speed){
  switch(_shield){
    case 0: {  // Arduino shield.
      pinMode(_motor_pin[0], HIGH);
      pinMode(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], speed);
      analogWrite(_motor_pin[3], speed);
      break;
    }
    case 1: {  // Seedstudio shield.
      pinMode(_motor_pin[0],HIGH);
      pinMode(_motor_pin[1],LOW);
      pinMode(_motor_pin[3],HIGH);
      pinMode(_motor_pin[4],LOW);

      analogWrite(_motor_pin[2], speed);
      analogWrite(_motor_pin[5], speed);
      break;
    }
  }
}

void robotMove::stop(){
  switch(_shield){
    case 0: {  // Arduino shield.
      pinMode(_motor_pin[0], HIGH);
      pinMode(_motor_pin[2], HIGH);
      analogWrite(_motor_pin[1], 0);
      analogWrite(_motor_pin[3], 0);
      break;
    }
    case 1: {  // Seedstudio shield.
      pinMode(_motor_pin[0],HIGH);
      pinMode(_motor_pin[1],HIGH);
      pinMode(_motor_pin[3],HIGH);
      pinMode(_motor_pin[4],HIGH);

      analogWrite(_motor_pin[2], 0);
      analogWrite(_motor_pin[5], 0);
      break;
    }
  }
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

void vectorCopy(const int* src, int* dest){
  int src_size = sizeof(src);
  int dest_size = sizeof(dest);
  int int_size = sizeof(int);

  // Check first if both vectors have the same size.
  if(src_size == dest_size){
    for(int i = 0; i < src_size / int_size; i++){
      // Copy element by element.
      dest[i] = src[i];
    }
  }
}
