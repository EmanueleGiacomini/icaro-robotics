/**
  explorer_sensors.h
  Purpose: Interface with explorer robots of Icaro course

  @author Emanuele Giacomini
  @version 0.1 14/10/2017
*/

#ifndef explorer_sensors_h
#define explorer_sensors_h

#include <Arduino.h>
#include <math.h>

class explorer_light{
public:
  explorer_light();
  ~explorer_light();

  void init(const int pin);
  int getState();

};

#endif
