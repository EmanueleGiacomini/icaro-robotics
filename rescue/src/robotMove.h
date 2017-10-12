/**
  robotMove.h
  Purpose: Interface with the motor shields available to ICARO students =)

  @author Emanuele Giacomini
  @version 0.2 08/10/2017
*/

#ifndef robotMove_h
#define robotMove_h

#include <Arduino.h>
#include "vector_man.h"
/**
  Interface with icaro project robots.
  Please consider right motor as motor-A, left motor as motor-B
  A positive speed should result in clockwise rotation (therfore setting up both motors with positive speed results in
  a counter-clockwise rotation of the robot).
*/
class robotMove{
  /**
    Pins are set in the following order: A_direction, A_PWM, B_direction, B_pwm.
  */
  const int _ARDUINO_SHIELD_PINOUT[4] = {12, 3, 13, 11};
  /**
    Pins are set in the following order: A_dir1, A_dir2, A_PWM, B_dir1, B_dir2, B_PWM.
  */
  const int _SEEDSTUDIO_SHIELD_PINOUT[6] = {8, 11, 9, 12, 13, 10};
  /**
    Pointer to internal motors pin dynamic array.
  */
  int* _motor_pin;
  /**
    The dimension in integers of the _motor_pin vector.
  */
  int _motor_pin_size;
  /**
    Value given by the current shield that's begin used.
    0 -> Arduino
    1 -> Seedstudio
  */
  int _shield;
public:
  /**
    Initialize the class.
    @param shield_name String representing the current motor shield.
    'arduino' -> you're using arduino motor shield.
    'seedstudio' -> you're using seedstudio motor shield.
  */
  robotMove();
  ~robotMove();
  void init(const char* shield_name);
  /**
    Drives the motors with a given direction.
    @param speed The PWM rate for the motors.
  */
  void goForward(const int speed = 100);
  void goBack(const int speed = 100);
  void goRight(const int speed = 100);
  void goLeft(const int speed = 100);
  /**
    Stops the robot motion by shutting down the motors.
  */
  void stop();

  /**
    Move one single motor at the time.
    @param speed The desidered motor speed. If a negative value is given, the motor changes direction.
  */
  void driveRightMotor(const int speed);
  void driveLeftMotor(const int speed);

  /**
    Gets the shield data from the class.
    @return integer representing which shield is currently begin used.
    0 -> Arduino
    1 -> Seedstudio
  */
  int getShield();
  /**
    Gets the pin pointer from the class. Don't mess with the vector.
    @return integer pointer to the private _motor_pin pointer.

  */
  int* getMotorVector();
  /**
    Gets the size of the motor pin pointer.
    @return The size (in integers) of _motor_pin vector.
  */
  int getMotorSize();
};
/**

*/
int stringIsEqual(const char* s1, const char* s2);

#endif
