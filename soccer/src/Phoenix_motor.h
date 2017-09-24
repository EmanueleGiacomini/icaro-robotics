/**
 * Phoenix_motor.h
 * Purpose: interface with phoenix type soccer robots
 *
 * @author Emanuele Giacomini
 * @version 0.3 28/08/17
 */

#ifndef Phoenix_motor_h
#define Phoenix_motor_h

#include <Arduino.h>
#include <math.h>
#include "Phoenix_shiftreg.h"

class Phoenix_motor{
	int _motor_pin[4];
	const float _motor_ang_comp[4][2] = {{0.5, -0.8660}, {0.5, 0.8660}, {-0.7071,0.7071}, {-0.7071,-0.7071}};
	float _motor_vel[4] = {0, 0, 0, 0};

public:
	/**
		Phoenix constructor
	*/
	Phoenix_motor();
	/**
		Initialize the phoenix class.
		@param motor_pin Pointer to motor pins vector. Build the vector in this order:
		Front-Left, Front-Right, Back-Right, Back-Left.
		@param shift_reg_pin Pointer to shift register pins vector. Build the vector in this order:
		Latch, Clock, Data.
	*/
	void init(const int* motor_pin, const int* shift_reg_pin);
	/**
		Compute velocity for each motor in order to move to a given direction.
		@param direction Goes from 0 to 359 where 0 is the right side of the robot.
		Direction goes counter clockwise.
		@param velocity Desidered velocity.
	*/
	void move(const int direction, const int velocity);
	/**
		Compute velocity for each motor in order to rotate by a given value.
		@param rotation Determines the direction and velocity of rotation.
	*/
	void rotate(const int rotation);
	/**
		Send data to the motors in order to achieve the desidered roto-translation.
	*/
	void compute(void);
};
/**
	Set all values inside a given vector equal to a given value.
	@param vec Pointer to a float type vector.
	@param value Value to set the vector.
*/
void setVector(float* vec, const float value);


#endif
