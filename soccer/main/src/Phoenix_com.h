/**
  Phoenix_com.h
  Purpose: Library takes care of driving comunications between modules inside Phoenix robot.

  @author Emanuele Giacomini
  @version 0.1 22/09/17
*/

#ifndef Phoenix_com_h
#define Phoenix_com_h

#include <Arduino.h>
#include <math.h>

class Communicator{
uint8_t _recived_byte[32];
uint8_t _target_address;
public:
  /**
    Constructor
  */
  Communicator();
  /**
  */
  ~Communicator();
  /**
  */
  void init(uint8_t target_address);
  void getData(uint8_t command_byte);
};


#endif
