/**
 * Phoenix_compass.cpp
 * Purpose: Interface with HMC6343 inside the phoenix robot.
 *
 * @author Emanuele Giacomini
 * @version 0.1 21/09/17
 */

 #include "Phoenix_compass.h"

// Class constructor.
Phoenix_compass::Phoenix_compass() : _compass(){
  heading_error = vnord = heading = 0;

}
Phoenix_compass::~Phoenix_compass(){

}

int Phoenix_compass::init(){
  return _compass.init();
}

int Phoenix_compass::roundLimit(const int value, const int min, const int max){
  int interval_size = max - min;
  if(value > max){
    return value - interval_size;
  } else if(value < min){
    return value + interval_size;
  }
}

void Phoenix_compass::updateData(){
  _compass.readHeading();

  heading_error = ( _virtual_nord - int(_compass.heading / 10));
  heading_error = roundLimit(heading_error, -180, 180);
  heading = roundLimit(heading_error + 90, 0, 360);
}

void Phoenix_compass::setNord(){
  vnord = heading;
}

void Phoenix_compass::reset(){
  _compass.reset();
}

void Phoenix_compass::startCal(){
  _compass.enterCalMode();
}

void Phoenix_compass::stopCal(){
  _compass.exitCalMode();
}

void Phoenix_compass::setRate(const int rate){
  switch(rate){
    case 1: {
      _compass.writeEEPROM(OP_MODE2, 0x00);
      break;
    }
    case 5: {
      _compass.writeEEPROM(OP_MODE2, 0x01);
      break;
    }
    case 10: {
      _compass.writeEEPROM(OP_MODE2, 0x02);
      break;
    }
  }
}
