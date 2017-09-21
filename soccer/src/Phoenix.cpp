/**
 * Phoenix.cpp
 * Purpose: interface with phoenix type soccer robots
 *
 * @author Emanuele Giacomini
 * @version 0.2s 28/08/17
 */


#include "Phoenix.h"


Phoenix::Phoenix(){
}

void Phoenix::init(const int* motor_pin, const int* shift_reg_pin){
	for(int i = 0; i < 4; i++){
		_motor_pin[i] = motor_pin[i];
		pinMode(motor_pin[i], OUTPUT);
	}

	phoenix_shreg.setup(shift_reg_pin);
}

void Phoenix::move(const int direction, const int velocity){
	float rad_direction = (direction * 71) / 4068;
	float vel_x = cos(rad_direction) * velocity;
	float vel_y = sin(rad_direction) * velocity;

	for(int i = 0; i < 4; i++){
		_motor_vel[i] += _motor_ang_comp[i][1] * vel_y;
		_motor_vel[i] -= _motor_ang_comp[i][0] * vel_x;
	}
}

void Phoenix::rotate(const int rotation){
	for(int i = 0; i < 4; i++){
		_motor_vel[i] += rotation;
	}
}

void Phoenix::compute(void){
	for(int i = 0; i < 4; i++){
		if(_motor_vel[i] >= 0){
			phoenix_shreg.setMotor(i * 2, HIGH);
			phoenix_shreg.setMotor((i * 2) + 1, LOW);
			analogWrite(_motor_pin[i], _motor_vel[i]);
		} else {
			phoenix_shreg.setMotor(i * 2, LOW);
			phoenix_shreg.setMotor((i * 2) + 1, HIGH);
			analogWrite(_motor_pin[i], - _motor_vel[i]);
		}
		phoenix_shreg.update();
	}
	setVector(_motor_vel, 0);
}

void setVector(float* vec, const float value){
	for(int i = 0; i < sizeof(vec) / sizeof(float); i++){
		vec[i] = value;
	}
}
