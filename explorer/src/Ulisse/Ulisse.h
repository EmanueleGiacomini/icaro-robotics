/**
 * Ulisse.h
 * Purpose: Basic interface for icaro explorer robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#ifndef Ulisse_h
#define Ulisse_h

#include "Arduino.h"

class Ulisse{

public:
  Ulisse(const int motor_A, const int pwm_A, const int motor_B, const int pwm_B);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  void setVel();
};

#endif
