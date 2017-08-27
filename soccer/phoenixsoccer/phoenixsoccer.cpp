/**
  	phoenixsoccer.cpp

  	@author Emanuele Giacomini
  	@version 0.1 27/08/17
*/

#include <Arduino.h>
#include "phoenixSoccer.h"

phoenix::phoenix(const int* motor_pwm_ptr){
	for(int i = 0; i < 4; i++){
		_motor_pwm[i] = motor_pwm_ptr[i];
		pinMode(motor_pwm_ptr[i],OUTPUT);
	}
}

void phoenix::driveMotor(const int motor, const int velocity){

}

void phoenix::move(const int direction, const int rotation, const int velocity){
	float rad_direction = (direction * 71) / 4068;
	float motor_velocity[4] = {0, 0, 0, 0};		
	float velocity_x = cos(rad_direction) * velocity;
	float velocity_y = sin(rad_direction) * velocity;

	for(int i = 0; i < 4; i++){
		motor_velocity[i] = _motor_ang_components[i][1] * velocity_y;
		motor_velocity[i] -= _motor_ang_components[i][0] * velocity_x;
		motor_velocity[i] += rotation;
		//driveMotor(i, int(motor_velocity[i]));
	}
}

shiftRegister::shiftRegister(const int latch, const int clock, const int data){
	_latch = latch;
	_clock = clock;
	_data = data;

	pinMode(latch,OUTPUT);
	pinMode(clock, OUTPUT);
	pinMode(data, OUTPUT);

}

void shiftRegister::changeByte(String byte_to_change, int bit, boolean value){
	if(stringEqual(byte_to_change,'led')){
		if(value)
	} else if(stringEqual(byte_to_change,'motor')){

	}
}

int stringEqual(const String a, const String b){
	if(sizeof(a) != sizeof(b)){
		return 0;
	}
	for(int i = 0; i < sizeof(a); i++){
		if(a[i] != b[i]){
			return 0;
		}
	}
	return 1;    
}