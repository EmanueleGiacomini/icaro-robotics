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
#include "SPI.h"
#include "math.h"
#include "Pixy/Pixy.h"
#include "PID_v1/PID_v1.h"


class ShiftRegister{
public:
	/**
	*/
	ShiftRegister();
	void setup(const int* shift_reg_pins);
	void setLed(const int bit, const int state);
	void setMotor(const int bit, const int state);
	void update(void);
private:
	int _latch, _clock, _data;
	byte _led_byte = 0;
	byte _motor_byte = 0;
};

class Line{
	int _line_sensor_pin[12];
	const float _line_angle[12];
	int _line_status[12];
	int _threshold[12];
	int _line_found = 0;
public:
	/**
		Initialize Line object.
	*/
	Line();
	/**
		Setup pins for the Line object.
		@param line_sensor_pin Pointer to line sensor pins vector.
	*/
	void setup(const int* line_sensor_pin);
	/**
		Gather data from the sensors and saves it on _status array.
	*/
	void update();
	/**
		Sets a sensor's threshold to detect a white line on the field
		@param index The choosen sensor. choose an index of _line_sensor_pin vector.
		@param threshold Value of the threshold. Goes from 0 to 1023.
		*/
	void setThreshold(const int index, const int threshold);
	/**
	Returns the current status of the Line object.
	@return 0 if no line is found, 1 otherwhise
	*/
	int getStatus();
	/**
		Returns the best direction to get away from the line. Use only if _line_found is 1.
		@return the direction to take in order to get away from the line. Goes from 0 to 359.
	*/
	int getDirection();
	/**
		Returns the reading from a given sensor's index.
	*/
	int getReading(const int index);
};

class Phoenix{
	int _motor_pin[4];
	const float _motor_ang_comp[4][2] = {{0.5, -0.8660}, {0.5, 0.8660}, {-0.7071,0.7071}, {-0.7071,-0.7071}};
	float _motor_vel[4] = {0, 0, 0, 0};


	ShiftRegister _shreg;
	Line _line;
	Pixy _pixy;

	float _heading, _vnord, _delta_heading, _relative_heading;
public:
	/**
		Initialize the phoenix class.
		@param motor_pin Pointer to motor pins vector. Build the vector in this order:
		Front-Left, Front-Right, Back-Right, Back-Left.
		@param shift_reg_pin Pointer to shift register pins vector. Build the vector in this order:
		Latch, Clock, Data.
		@param line_sensor_pin Pointer to line sensor pins vector.
	*/
	Phoenix(const int* motor_pin, const int* shift_reg_pin, const int* line_sensor_pin);
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
	/**
		After getting the raw heading from the compass, the function process delta_heading and relative_heading.
		delta_heading gives the heading distance from the vnord.
		relative_heading gives the heading relative to the vnord.
	*/
	void setCompass(const int heading);
	/**
		Set the Virtual nord (Usually the enemy goal).
	*/
	void setNord(const int vnord);

	/**
		Returns heading data.
		@return relative heading value [0- 360)
	*/
	float getHeading();
	/**
		Returns heading data.
		@return delta heading value (-180 - 180)
	*/
	float getHeadingError();
	/**
		Get data from line sensors and pixy.
	*/
	void updateData();
};
/**
	Set all values inside a given vector equal to a given value.
	@param vec Pointer to a float type vector.
	@param value Value to set the vector.
*/
void setVector(float* vec, const float value);


#endif
