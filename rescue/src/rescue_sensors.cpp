
/**
  rescue_sensors.cpp
  Purpose: Interface with rescue robots of Icaro course

  @author Emanuele Giacomini
  @version 0.1 07/10/2017
*/
#include "rescue_sensors.h"

rescue_line::rescue_line(){
  
}
rescue_line::~rescue_line(){
  free(_sensor_pins);
  free(_sensor_position);
  free(_threshold);
  free(_low_reading);
  free(_high_reading);
}


void rescue_line::init(const int* sensor_pins, const int size){
  _size = size;
  // Alloc in the heap memory vectors as big as sensor_pins
  _sensor_pins = vecAlloc(size);
  _sensor_position = vecAlloc(size);
  _threshold = vecAlloc(size);
  _low_reading = vecAlloc(size);
  _high_reading = vecAlloc(size);
  // Sets all pins as INPUT
  vecSetAsInput(sensor_pins,size);

  // Build the pin vector.
  vecWrite(_sensor_pins, size, 0); // Set all elements to 0
  vecSum(sensor_pins, size, _sensor_pins); // Copy pins from sensor_pins.


  // Generalized Method to choose position of each sensor
  if(size % 2 == 0){ // There is an even number of sensors.
    int current_position;
    for(int i = 0; i < size; i++){
      current_position = i - ( size / 2 );
      _sensor_position[i] = current_position;
      if(current_position == 0){
        _sensor_position[i] += 1;
      }
    }
  } else { // There is an odd number of sensors.
    int current_position;
    for(int i = 0; i < size; i++){
      current_position = floor(i - ( size / 2 )); // rounds down to the nearest integer
      _sensor_position[i] = current_position;
    }
  }

  // initialize the threshold vector.
  vecWrite(_threshold, size, 0);
  vecWrite(_low_reading, size, 1023);
  vecWrite(_high_reading, size, 1023);
}

int rescue_line::readSensor(const int index){
  if(index < 0 || index >= _size){
    return 0;
  }
  return analogRead(_sensor_pins[index]);
}

int rescue_line::readLine(){
}

void rescue_line::startCalibration(){
  _calibration_mode = 1;
}

void rescue_line::calibrate(){
  if(_calibration_mode){

    int current_reading;
    for(int i = 0; i < _size; i++){
      current_reading = readSensor(i);
      if(current_reading < _low_reading[i]){
        _low_reading[i] = current_reading;
      }
      if(current_reading > _high_reading[i]){
        _high_reading[i] = current_reading;
      }
    }
  }
}

void rescue_line::stopCalibration(){
  for(int i = 0; i < _size; i++){
    _threshold[i] = ( _high_reading[i] + _low_reading[i] ) / 2;
  }
  _calibration_mode = 0;

}

void rescue_line::setThreshold(const int index, const int threshold){
  vecWriteAt(_threshold, _size, index, threshold);
}
