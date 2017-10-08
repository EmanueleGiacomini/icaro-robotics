/**
  rescue_sensors.h
  Purpose: Interface with rescue robots of Icaro course

  @author Emanuele Giacomini
  @version 0.1 07/10/2017
*/

#ifndef rescue_sensor_h
#define rescue_sensor_h

#include <Arduino.h>
#include <math.h>
#include "vector_man.h"


class rescue_line{
  int _size;
  int* _sensor_pins;
  int* _sensor_position;

  int* _threshold;
  int _calibration_mode = 0;
  int* _low_reading;
  int* _high_reading;

public:
  // Constructor
  rescue_line();
  //Destructor
  ~rescue_line();
  void init(const int* sensor_pins, const int size);
  int readSensor(const int index);
  int readLine();
  void startCalibration();
  void calibrate();
  void stopCalibration();
  void setThreshold(const int index, const int threshold);
};

#endif
