/**
 * soccer.ino
 * Purpose: basic interface for the phoenix soccer robot
 *
 * @author Emanuele Giacomini
 * @version 0.2s 27/08/17
 */

 #include "src/Phoenix/Phoenix.h"

const int motor_pwm_pins[] = {5, 9, 32, 4};
const int shift_reg_pins[] = {30, 28, 17};
Phoenix robot(motor_pwm_pins, shift_reg_pins);


 void setup(){
 }

 void loop(){
 }
