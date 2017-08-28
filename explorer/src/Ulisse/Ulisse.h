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
  int _motor_A, _pwm_A;
  int _motor_B, _pwm_B;
  int _vel;
  int _light_sens_pin[3];
public:
  /**
    Initialize the Ulisse class.

    @param motor_A The direction pin relative to motor A (Right motor).
    @param pwm_A Pwm pin relative to motor A.
    @param motor_B Same as motor_A but relative to motor B (Left motor).
    @param pwm_B Pwm pin relative to motor B.
    @param light_sens_pin pointer to light sensor array (3 sensor from right to left).
  */
  Ulisse(const int motor_A, const int pwm_A, const int motor_B, const int pwm_B, const int* light_sens_pin);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  /**
    Set the velocity of the motors

    @param target_vel PWM value to controll the motors. Goes from 0 to 255.
  */
  void setVel(const int target_vel);

  /**
    Gather light data from the right sensor
  */
  int getLightRight();
  /**
    Gather light data from the front sensor
  */
  int getLightFront();
  /**
    Gather light data from the left sensor
  */
  int getLightLeft();
};

#endif
