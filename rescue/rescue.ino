/**
 * rescue.ino
 * Purpose: basic interface for icaro rescue robot
 *
 * @author Emanuele Giacomini
 * @version 0.1 28/08/17
 */

#import "src/Atlas/Atlas.h"
const int motor_pin[4] = {12, 13, 10, 11};
const int line_sensor_pin[3] = {A0, A1, A2};

Atlas robot(motor_pin, line_sensor_pin);

void setup() {
  Serial.begin(9600);
}

void loop() {
  robot.update();
  Serial.println(robot.line_data[0]);
}
