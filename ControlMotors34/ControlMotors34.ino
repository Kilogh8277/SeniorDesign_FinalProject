#include <DualVNH5019MotorShield.h>

char motorMove;

DualVNH5019MotorShield Motors; // Declare Motors

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() >= 1) {
    motorMove = Serial.read();
      if (motorMove == 's') {
        Motors.setBrakes(400, 400);
        Serial.println("Stopping motors!"); 
      }
      else if(motorMove == 'a') {
        Motors.setM1Speed(200); 
        Serial.println("Setting M3 to 200");   
      }
      else if (motorMove == 'd') {
        Motors.setM2Speed(200);
        Serial.println("Setting M4 to 200");     
      }
      else if (motorMove == 'z') {
        Motors.setM1Speed(-200);
        Serial.println("Setting M3 to -200"); 
      }
      else if (motorMove == 'c') {
        Motors.setM2Speed(-200);
        Serial.println("Setting M4 to -200"); 
      }
  }
}
