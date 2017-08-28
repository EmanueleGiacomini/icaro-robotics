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
#include "math.h"

class Phoenix{
public:
	Phoenix(const int* motor_pin);
	void move(const int direction, const int rotation, const int velocity);
private:
	int _motor_pin[4];
	const float _motor_ang_comp[4][2] = {{0.5, -0.8660}, {0.5, 0.8660}, {-0.7071,0.7071}, {-0.7071,-0.7071}};

};

#endif



