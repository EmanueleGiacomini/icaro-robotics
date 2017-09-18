/**
*/

#ifndef robotMove_h
#define robotMove_h

class robotMove{
  // Pins are set in the following order: A_direction, A_PWM, B_direction, B_pwm.
  const int _ARDUINO_SHIELD_PINOUT[4] = {12, 3, 13, 11};
  // Pins are set in the following order: A_dir1, A_dir2, A_PWM, B_dir1, B_dir2, B_PWM.
  const int _SEEDSTUDIO_SHIELD_PINOUT[8] = {8, 11, 9, 12, 13, 10};
  int* _motor_pin;
  // _shield: 0 if the current shield is arduino, 1 if its seedStudio.
  int _shield;
  int checkShield();
public:
  robotMove(const char* shield_name);
  void goForward(const int speed);
  void goBack(const int speed);
  void goRight(const int speed);
  void goLeft(const int speed);
  void stop():
};

int vectorMalloc(const int size);
int stringIsEqual(const char* s1, const char* s2);
void vectorSet(const int* src, const int* dest);
#endif
