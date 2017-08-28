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
	for(int i = 0; i < 4; i++){
		_motor_pin[i] = motor_pin[i];
		pinMode(motor_pin[i], OUTPUT);
	}
}

void Phoenix::move(const int direction, const int rotation, const int velocity){
	float rad_direction = (direction * 71) / 4068;
	float vel_x = cos(rad_direction) * velocity;
	float vel_y = sin(rad_direction) * velocity; 

	float motor_vel[4] = {0, 0, 0, 0};

	for(int i = 0; i < 4; i++){
		motor_vel[i] = _motor_ang_comp[i][1] * vel_y;
		motor_vel[i] -= _motor_ang_comp[i][0] * vel_x;
		motor_vel[i] += rotation;

		//motorDrive(i, motor_vel[i]);
	}
}