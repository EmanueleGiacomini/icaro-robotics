/**
 * soccer.ino
 * Purpose: basic interface for the phoenix soccer robot
 *
 * @author Emanuele Giacomini
 * @version 0.3 27/08/17
 */

#include <Wire.h>
#include "SPI.h"
#include "src/Pixy/Pixy.h"
#include "src/sfe_hmc6343/SFE_HMC6343.h"
#include "src/PID_v1/PID_v1.h"
#include "src/Phoenix_shiftreg.h"
#include "src/Phoenix_motor.h"
#include "src/Phoenix_compass.h"
#include "src/Phoenix_line.h"

const int motor_pwm_pin[4];
const int shift_reg_pin[3];
Phoenix_motor robot;
Phoenix_compass robot_compass;

 void setup(){
   Serial.begin(9600);

   robot.init(motor_pwm_pin, shift_reg_pin);
   if(!robot_compass.init()){
     Serial.print("ERROR!, unable to initialize HMC6343 Module\n");
   }
   Serial.print("HMC6343 initialized!\n");
 }

 void loop(){
 }
