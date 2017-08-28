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
  int _motor_A, _pwm_A;
  int _motor_B, _pwm_B;
  int _vel;

public:
  Atlas(const int motor_A, const int pwm_A, const int motor_B, const int pwm_B);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  void setVel(const int target_vel);
};

#endif
