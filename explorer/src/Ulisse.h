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
  int _bumper_pin[2];
public:
  /**
    Initialize the Ulisse class.

    @param motor_pin Pointer to motor pins vector. Build the vector in this order:
    Right-dir, Right-pwm, Left-dir, Left-pwm.
    @param light_sens_pin Pointer to light sensor vector. Build the vector in this order: Right, Center, Left.
    @param bumper_pin Pointer to bumper vector. Build the vector in this order: Right, Left.
  */
  Ulisse(const int* motor_pin, const int* light_sens_pin, const int* bumper_pin);
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
  /**
    Initialize the gas sensor and pre-heats it in order to work.
  */
  void heatGasSensor();
  /**
    Returns the current status of the gas sensor.
    @return 1 if the sensor is ready, 0 otherwhise.
  */
  int gasReady();
  /**
    Gather data from the gas sensor.
    @return Analog read from the sensor (from 0 to 1024).
  */
  int readGas();

  int bumperData[2];
  int lightData[3];
};

#endif
