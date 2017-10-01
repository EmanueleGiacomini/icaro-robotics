/**
 * Phoenix_compass.h
 * Purpose: Interface with HMC6343 inside the phoenix robot.
 *
 * @author Emanuele Giacomini
 * @version 0.1 21/09/17
 */

#ifndef Phoenix_compass_h
#define Phoenix_compass_h

#include <Arduino.h>
#include <Wire.h>
#include "sfe_hmc6343/SFE_HMC6343.h"

/**
  This class takes care of the HMC6343 compass module
*/
class Phoenix_compass{
  SFE_HMC6343 _compass;
  float _virtual_nord;
  /**
    Creates a circular interval for a given value.
    Example:
      value = -182
      value = roundLimit(value, -180, 180);
      value = 178
    @return Integer inside between min and max values.
  */
  int roundLimit(const int value, const int min, const int max);
public:
  int heading_error, heading, vnord;

  Phoenix_compass();
  ~Phoenix_compass();
  /**
    Initialize the class.
    @return 1 if the compass is found. 0 otherwhise.
  */
  int init();
  /**
    Gather data from the HMC6343 module and compute
    heading_error and relative_heading.
  */
  void updateData();
  /**
    Set the current heading as virtual nord.
  */
  void setNord();
  /**
    Resets the HMC6343 module.
  */
  void reset();
  /**
    Starts calibration mode.
  */
  void startCal();
  /**
    Stops calibration mode.
  */
  void stopCal();
  /**
    Sets measuring rate of the HMC6343 module.
    @param rate Desidered rate. Choose 1, 5 or 10 Hz.
  */
  void setRate(const int rate);

};

#endif
