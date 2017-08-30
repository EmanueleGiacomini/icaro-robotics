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
  int _motor_pin[4];
  int _vel;
  int _light_sens_pin[3];
public:
  /**
    Initialize the Ulisse class.

    @param motor_pin Pointer to motor pins vector. Build the vector in this order:
    Right-dir, Right-pwm, Left-dir, Left-pwm.
    @param light_sens_pin Pointer to light sensor vector. Build the vector in this order: Right, Center, Left.
    @param bumper_pin Pointer to bumper vector. Build the vector in this order: Right, Left.
  */
  Ulisse(const int[] motor_pin, const int[] light_sens_pin, const int[] bumper_pin);
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
    Update data gathered by light sensors and bumpers
  */
  void update();

  int bumperData[2];
  int lightData[3];
};

#endif
