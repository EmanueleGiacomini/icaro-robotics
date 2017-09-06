/**
 * Phoenix.cpp
 * Purpose: interface with phoenix type soccer robots
 *
 * @author Emanuele Giacomini
 * @version 0.2s 28/08/17
 */

#include "Arduino.h"
#include "Phoenix.h"

/////////////////////////////////////////////////////////////
/////////////////////////   SHIFT REGISTER  /////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
ShiftRegister::ShiftRegister(){
}

void ShiftRegister::setup(const int* shift_reg_pins){
	pinMode(shift_reg_pins[0],OUTPUT);
	pinMode(shift_reg_pins[1],OUTPUT);
	pinMode(shift_reg_pins[2],OUTPUT);
	_latch = shift_reg_pins[0];
	_clock = shift_reg_pins[1];
	_data = shift_reg_pins[2];
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
/////////////////////////////////////////////////////////////
/////////////////////////   LINE  ///////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
Line::Line(){

}

void Line::setup(const int* line_sensor_pin){
	for(int i = 0; i < sizeof(line_sensor_pin) / sizeof(int); i++){
		pinMode(line_sensor_pin[i], INPUT);
		_line_sensor_pin[i] = line_sensor_pin[i];
	}
}

void Line::update(){
	_line_found = 0;
	for(int i = 0; i < sizeof(_line_sensor_pin) / sizeof(int); i++){
		int reading = analogRead(_line_sensor_pin[i]);
		if(reading < _threshold[i]){
			_line_status[i] = 1;
			_line_found = 1;
		}
		else{
			_line_status[i] = 0;
		}
	}
}

void Line::setThreshold(const int index, const int threshold){
	_threshold[index] = index;
}

int Line::getStatus(){
	return _line_found;
}

int Line::getDirection(){
	double x = 0;
	double y = 0;
	double direction;

	for(int i = 0; i < sizeof(_line_status) / sizeof(int); i++){
		if(_line_status[i]){
			x += cos(_line_angle[i]);
			y += sin(_line_angle[i]);
		}
	}
	direction = atan2(y,x) + M_PI;
	direction *= (4068 / 71);

	return int(direction);
}

int Line::getReading(const int index){
	return analogRead(_line_sensor_pin[index]);
}


/////////////////////////////////////////////////////////////
/////////////////////////   PHOENIX  ////////////////////////
/////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////
Phoenix::Phoenix(const int* motor_pin, const int* shift_reg_pin, const int* line_sensor_pin) : _shreg(), _line(), _pixy() {
	for(int i = 0; i < 4; i++){
		_motor_pin[i] = motor_pin[i];
		pinMode(motor_pin[i], OUTPUT);
	}

	_shreg.setup(shift_reg_pin);
	_line.setup(line_sensor_pin);
	_pixy.init();
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
	_vnord = vnord;
}

float Phoenix::getHeading(){
	return _relative_heading;
}
float Phoenix::getHeadingError(){
	return _delta_heading;
}

void Phoenix::updateData(){
	_line.update();

	// Pixy
	static int i = 0;
	uint16_t blocks = _pixy.getBlocks();
	if(blocks){
		i++;

		if(i % 50 == 0){
			// Do stuff
		}
	}
}

void setVector(float* vec, const float value){
	for(int i = 0; i < sizeof(vec) / sizeof(float); i++){
		vec[i] = value;
	}
}
