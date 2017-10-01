/**
  Phoenix_line.h
  Purpose: Interface with the line sensors on the Phoenix robot.

  @author Emanuele Giacomini
  @version 0.1 21/09/17
*/
#ifndef Phoenix_line_h
#define Phoenix_line_h

#include <Arduino.h>
#include <math.h>

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
	void init(const int* line_sensor_pin);
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
	*/
	int getReading(const int index);
};

#endif
