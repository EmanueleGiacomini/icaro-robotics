/**
 * Phoenix.h
 * Purpose: interface with phoenix type soccer robots
 * 
 * @author Emanuele Giacomini
 * @version 0.2s 28/08/17
 */

#ifndef Phoenix_h
#define Phoenix_h

#include "Arduino.h"

class Phoenix{
public:
	Phoenix(const int* motor_pin);
private:
	int _motor_pin[4];

};

#endif



