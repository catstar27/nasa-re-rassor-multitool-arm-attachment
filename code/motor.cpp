#include "motor.h"
#include <Arduino.h>

StepperMotor::StepperMotor(int dirPin, int stepPin, int zeroPin, int sleepPin) {
  this->dirPin = dirPin;
  this->stepPin = stepPin;
  this->zeroPin = zeroPin;
  this->sleepPin = sleepPin;

  pinMode(dirPin, OUTPUT);
  pinMode(stepPin, OUTPUT);
  pinMode(zeroPin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  digitalWrite(zeroPin, HIGH);
  digitalWrite(sleepPin, HIGH);
}

void StepperMotor::rotateMotor(double angle) {
  // Set the motor to either CW or CCW
  if(angle < 0) {
    digitalWrite(this->dirPin, HIGH);
  } else {
    digitalWrite(this->dirPin, LOW);
  }

  int steps = int(floor(abs(angle)/1.8)); // Turns the angle into steps, remember there is 1.8 degrees/step
  for(int i = 0; i < steps; i++) { // Turns the stepper motor an amount of steps
    digitalWrite(this->stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(this->stepPin, LOW);
    delayMicroseconds(2000);
  }
}