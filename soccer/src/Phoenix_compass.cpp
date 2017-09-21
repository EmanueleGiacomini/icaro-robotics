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
}

int Phoenix_compass::begin(){
  return _compass.init();
}

void Phoenix_compass::updateData(){
  _compass.readHeading();

  heading_error = ( _virtual_nord - _compass.heading / 10 );
  if(heading_error > 180){
    heading_error -= 360;
  } else if(heading_error < -180){
    heading_error += 360;
  }
}
