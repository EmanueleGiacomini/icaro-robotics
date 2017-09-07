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
  #define CALIBRATION_TIME 15000

  int _motor_pin[4];
  int _line_sensor_pin[3];
  int _ultrasonic_pin[2];
  int _vel;

  int _line_threshold[3];
  const int _line_pos_error[3] = {1, 0, -1};

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
  int readUltrasonic(const int index);
  /**
    Reads all the line sensors and output a value from -2 to +2 (int) represeting distance from the desidered position.
  */
  int getLinePos();
  /**
    Starts the calibration procedure for the line sensors.
    The procedure will take 15 seconds to complete.
    At the end, velocity will be set by default to 100.
  */
  void calibrate();
  /**
    Sets threshold value for a given sensor to detect the line.
    @param index Index of line_sensor_pin array to select the sensor.
    @param threshold Value to set as threshold.
  */
  void setThreshold(const int index, const int threshold);
};

#endif
