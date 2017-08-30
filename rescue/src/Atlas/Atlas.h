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
  int _vel;

public:
  /**
    Initialize the Atlas class.
    @param motor_pin Pointer to motor pins vector. Build the vector in this order:
    Right-dir, Right-pwm, Left-dir, Left-pwm.

  */
  Atlas(const int* motor_pin, const int* line_sensor_pin);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  void setVel(const int target_vel);
  /**
    Update data gathered by line sensors and
  */
  void update();

  int line_data[3];

};

#endif
