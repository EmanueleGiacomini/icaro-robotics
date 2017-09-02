/**
 * Phoenix.cpp
 * Purpose: interface with phoenix type soccer robots
 *
 * @author Emanuele Giacomini
 * @version 0.2s 28/08/17
 */

#include "Arduino.h"
#include "Phoenix.h"


ShiftRegister::ShiftRegister(const int latch, const int clock, const int data){
	pinMode(latch,OUTPUT);
	pinMode(clock,OUTPUT);
	pinMode(data,OUTPUT);
	_latch = latch;
	_clock = clock;
	_data = data;
}

void ShiftRegister::setLed(const int bit, const int state){
	if(state){
		_led_byte |= 1 << bit;
	} else {
		_led_byte &= ~(1 << bit);
	}
}

void ShiftRegister::setMotor(const int bit, const int state){
	if(state){
		_motor_byte |= 1 << bit;
	} else {
		_motor_byte &= ~(1 << bit);
	}
}

void ShiftRegister::update(void){
	digitalWrite(_latch, LOW);
	shiftOut(_data, _clock, MSBFIRST, _led_byte);
	shiftOut(_data, _clock, MSBFIRST, _motor_byte);
	digitalWrite(_latch, HIGH);
}



Phoenix::Phoenix(const int* motor_pin, const int* shift_reg_pin) : _shreg(shift_reg_pin[0], shift_reg_pin[1], shift_reg_pin[2]) {
	for(int i = 0; i < 4; i++){
		_motor_pin[i] = motor_pin[i];
		pinMode(motor_pin[i], OUTPUT);
	}
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
			_shreg.setMotor(i * 2, HIGH);
			_shreg.setMotor((i * 2) + 1, LOW);
			analogWrite(_motor_pin[i], _motor_vel[i]);
		} else {
			_shreg.setMotor(i * 2, LOW);
			_shreg.setMotor((i * 2) + 1, HIGH);
			analogWrite(_motor_pin[i], - _motor_vel[i]);
		}
		_shreg.update();
	}
	setVector(_motor_vel, 0);
}

void Phoenix::setCompass(const int heading){
	float delta_heading = _vnord - heading;
	if(delta_heading > 180){
		delta_heading -= 360;
	} else if(delta_heading < -180){
		delta_heading += 360;
	}

	_delta_heading = delta_heading;
	float relative_heading = delta_heading + 90;
	if(_relative_heading > 180){
		_relative_heading -= 360;
	} else if(_relative_heading < -180){
		_relative_heading += 360;
	}
	_relative_heading = relative_heading;
}
void Phoenix::setNord(const int vnord){

}

void setVector(float* vec, const float value){
	for(int i = 0; i < sizeof(vec) / sizeof(float); i++){
		vec[i] = value;
	}
}
