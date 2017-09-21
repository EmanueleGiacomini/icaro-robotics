/**
  Phoenix_shiftreg.cpp
  Purpose: Interface with the shift register Ic's on the Phoenix robot.

  @author Emanuele Giacomini
  @version 0.1 21/09/17
*/
#include "Phoenix_shiftreg.h"

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

ShiftRegister phoenix_shreg;
