/**
  Phoenix_shiftreg.h
  Purpose: Interface with the shift register Ic's on the Phoenix robot.

  @author Emanuele Giacomini
  @version 0.1 21/09/17
*/
#ifndef Phoenix_shiftreg_h
#define Phoenix_shiftreg_h

#include <Arduino.h>

class ShiftRegister{
	int _latch, _clock, _data;
	byte _led_byte = 0;
	byte _motor_byte = 0;
public:
	ShiftRegister();
	void setup(const int* shift_reg_pins);
	void setLed(const int bit, const int state);
	void setMotor(const int bit, const int state);
	void update(void);
};

extern ShiftRegister phoenix_shreg;

#endif
