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
    @param light_sens_pin Pointer to light sensor vector. Build the vector in this order: Right, Center, Left.
    @param bumper_pin Pointer to bumper vector. Build the vector in this order: Right, Left.
  */
  Ulisse(const int motor_A, const int pwm_A, const int motor_B, const int pwm_B, const int[] light_sens_pin, const int[] bumper_pin);
  void goForward();
  void goRight();
  void goLeft();
  void goBack();
  void stop();
  /**
    Set the velocity of the motors

    @param target_vel PWM value to controll the motors. Goes from 0 to 255.
  */
  void setVel(const int target_vel);

  /**
    Gather light data from the right sensor
  */
  int readLightRight();
  /**
    Gather light data from the front sensor
  */
  int readLightFront();
  /**
    Gather light data from the left sensor
  */
  int readLightLeft();
  /**
    Gather the state of the right bumper
    @return 1 if the bumper is pressed, 0 otherwhise
  */
  int readBumperRight(void);
  /**
    Gather the state of the left bumper
    @return 1 if the bumper is pressed, 0 otherwhise
  */
  int readBumperLeft(void);
};

#endif
