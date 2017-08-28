/**
 * Phoenix.cpp
 * Purpose: interface with phoenix type soccer robots
 * 
 * @author Emanuele Giacomini
 * @version 0.2s 28/08/17
 */

#include "Arduino.h"
#include "Phoenix.h"

Phoenix::Phoenix(const int* motor_pin){
	for(int i = 0; i < sizeof(motor_pin); i++){
		_motor_pin[i] = motor_pin[i];
		pinMode(motor_pin[i], OUTPUT);
	}
}