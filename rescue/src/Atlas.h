/**
 * Atlas.h
 * Purpose: Basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#ifndef Atlas_h
#define Atlas_h

#include "Arduino.h"

class Atlas{
  int _motor_pin[4];
  int _line_sensor_pin[3];
  int _ultrasonic_pin[2];
  int _vel;

public:
  /**
    Initialize the Atlas class.
    @param motor_pin Pointer to motor pins vector. Build the vector in this order:
    Right-dir, Right-pwm, Left-dir, Left-pwm.
    @param line_sensor_pin Pointer to light pins vector. Build the vector in this order:
    Right, Center, Left.
    @param ultrasonic_pin Pointer to ultrasonic pins vector. Build the vector in this order:
    Right, Left.

  */
  Atlas(const int* motor_pin, const int* line_sensor_pin, const int* ultrasonic_pin);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  void setVel(const int target_vel);
  /**
    Update data gathered by line sensors and
    @param index Index of _line_sensor_pin
    @return Value from 0 to 1024 (int)
  */
  int readLine(const int index);
  /**
    Reads a given ultrasonic sensor.
    @param index Index of the ultrasonic sensor ( From _ultrasonic_pin array).
    @return the distance in centimeters from the object.
  */
  float readUltrasonic(const int index);

};

#endif
