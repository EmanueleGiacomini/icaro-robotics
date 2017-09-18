/**

*/

#include "robotMove.h"

robotMove::robotMove(const char* shield_name){
  // Checks and setup the class by checking which shield the user has choosen.
  if(stringIsEqual(shield_name, 'arduino')){
    _shield = 0;
    _motor_pin = vectorMalloc(sizeof(_ARDUINO_SHIELD_PINOUT));
    vectorSet(_ARDUINO_SHIELD_PINOUT, _motor_pin);

    for(int i = 0; i < 4; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  } else if(stringIsEqual(shield_name, 'seedstudio')){
    _shield = 1;
    _motor_pin = vectorMalloc(sizeof(_SEEDSTUDIO_SHIELD_PINOUT));
    vectorSet(_SEEDSTUDIO_SHIELD_PINOUT, _motor_pin);
    for(int i = 0; i < 8; i++){
      pinMode(_motor_pin[i], OUTPUT);
    }
  }
}

int robotMove::checkShield(){
  return _shield;
}

void robotMove::goForward(const int speed){
  int current_shield = this->checkShield();
  if(current_shield == 0){ // Arduino Shield.

  } else if(current_shield == 1){ // SeedStudio Shield.

  }
}
void robotMove::goBack(const int speed){

}
void robotMove::goRight(const int speed){

}
void robotMove::goLeft(const int speed){

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

void vectorSet(const int* src, const int* dest){
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
