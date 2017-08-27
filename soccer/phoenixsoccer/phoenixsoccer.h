/**
  	phoenixsoccer.h

  	@author Emanuele Giacomini
  	@version 0.1 27/08/17
*/

#ifndef phoenixSoccer_h
#define phoenixSoccer_h

#include <Arduino.h>
#include <math.h>


class phoenix{
	public:
		phoenix(const int* motor_pwm_ptr);
		/**
			Drive the motors in order to move the robot on a given direction with a given heading

			@param direction Direction value from 0 to 360.
			0 will point to the right side of the robot, increase to go counter clockwise.

			@param rotation Rotation value during the robot movement.

			@velocity velocity Velocity of the movement. Range from 0 to 254. 
		*/
		void move(const int direction, const int rotation, const int velocity);
	private:
		// Motors order: Ant-Left, Ant-Right, Post-Right, Post-Left
		int _motor_pwm[4];
		// sine and cosine of each motor.
		const float _motor_ang_components[4][2] = {{0.5, -0.8660}, {0.5, 0.8660}, {-0.7071,0.7071}, {-0.7071,-0.7071}};
		
}

class shiftRegister{
	public:
		byte led_byte;
		byte motor_byte;
		shiftRegister(const int latch, const int clock, const int data);
		void changeByte(String byte_to_change, int bit, boolean value);
		void update();
	private:
		int _latch,_clock,_data;
		
}
/**
			Checks if two strings are equal
			@param a The first string to check.
			@param b The second string to check.
			@return 1 if the strings are the same, 0 otherwise.
*/
int stringEqual(const String a, const String b){

}
/**
			Drive a single motor forward and backwards with a given velocity

			@param motor The selected motor, goes from 0 to 3.
			@param velocity Goes from -255 to 255.
*/
void driveMotor(const int motor, const int velocity);
 
#endif
