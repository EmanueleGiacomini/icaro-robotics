/**
 * rescue.ino
 * Purpose: basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#import "src/vector_man.h"
#import "src/rescue_sensors.h"

const int motor_pin[4] = {12, 13, 10, 11};
const int line_sensor_pin[3] = {A0, A1, A2};
const int ultrasonic_pin[2] = {9, 8};

rescue_line line;

void setup() {
  Serial.begin(9600);
  line.init(line_sensor_pin, 3);
}

void loop() {
}
