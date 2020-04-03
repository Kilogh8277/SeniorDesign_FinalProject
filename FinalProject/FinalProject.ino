/**********************************************************
 * Author: Kiley Gross
 * Date: February 4, 2020
 *********************************************************/
#include <DualVNH5019MotorShield.h>
int leftValIn = A0; // Variable for left motor speed
int rightValIn = A1; // Variable for right motor speed

int buttonPin = 2; // This is an interrupt pin -- will be used to turn motors on and off
volatile bool motorOn = 1;

signed int leftVal;
signed int rightVal;
DualVNH5019MotorShield Motors; // Declare Motors

void setup() {
  // Begin serial communication
  Serial.begin(9600);
  
  Motors.init(); // Initialize the motors from the library

  // Initialize the pins for reading from PLC
  pinMode(leftValIn, INPUT);
  pinMode(rightValIn, INPUT);
}

void loop() {
  // Read the values for the left and right motors
  leftVal = analogRead(leftValIn);
  rightVal = analogRead(rightValIn);

    Serial.print("The left value is ");
    Serial.println(leftVal);

    Serial.print("The right value is ");
    Serial.println(rightVal);
  if (leftVal == 0 || rightVal == 0) {
    Motors.setM1Speed(0);
    Motors.setM2Speed(0);
  }
  else {
    // Map the values, where 1 corresponds to -400 and 255 corresponds to 400
    leftVal = map(leftVal, 10, 1023, -200, 200);
    rightVal = map(rightVal, 10, 1023, -200, 200);

    //Serial.print("The left value is ");
    //Serial.println(leftVal);

    //Serial.print("The right value is ");
    //Serial.println(rightVal);
    
    // Set the motor speeds
    Motors.setM1Speed(leftVal);
    Motors.setM2Speed(rightVal);
  }
}
