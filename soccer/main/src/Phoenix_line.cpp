#include "Phoenix_line.h"

Line::Line(){}

void Line::init(const int* line_sensor_pin){
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
