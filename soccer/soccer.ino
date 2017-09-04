/**
 * soccer.ino
 * Purpose: basic interface for the phoenix soccer robot
 *
 * @author Emanuele Giacomini
 * @version 0.2s 27/08/17
 */

#include "SPI.h"
#include "src/Pixy/Pixy.h"
#include "src/sfe_hmc6343/SFE_HMC6343.h"
#include "src/PID_v1/PID_v1.h"
#include "src/Phoenix.h"

const int motor_pwm_pins[] = {5, 9, 32, 4};
const int shift_reg_pins[] = {30, 28, 17};
const int line_sensor_pin[12];
Phoenix robot(motor_pwm_pins, shift_reg_pins, line_sensor_pin);


 void setup(){
 }

 void loop(){
 }
