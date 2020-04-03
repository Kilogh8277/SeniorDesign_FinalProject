/**********************************************************
 * Author: Kiley Gross
 * Date: February 4, 2020
 *********************************************************/
#include <DualVNH5019MotorShield.h>
DualVNH5019MotorShield Motors; // Declare Motors

void setup() {
  // Begin serial communication
  Serial.begin(9600);
  
  Motors.init(); // Initialize the motors from the library
}

void loop() {
  Motors.setBrakes(400, 400);
}
