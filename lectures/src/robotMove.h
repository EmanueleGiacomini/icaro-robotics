/**
*/

#ifndef robotMove_h
#define robotMove_h

#include <Arduino.h>
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

  int* _motor_pin;
  // _shield value depends on the shield choosen by the user: 0 for Arduino shield, 1 for Seedstudio shield.
  int _shield;
public:
  /**
  */
  robotMove(const char* shield_name);
  void goForward(const int speed);
  void goBack(const int speed);
  void goRight(const int speed);
  void goLeft(const int speed);
  void stop();
};

int* vectorMalloc(const int size);
int stringIsEqual(const char* s1, const char* s2);
/**
  Copy the values from a given src vector, into a dest vector.
  @param src The source vector.
  @param dest The destination vector.
*/
void vectorCopy(const int* src, int* dest);
#endif
