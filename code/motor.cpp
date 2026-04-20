#include "motor.h"
#include <Arduino.h>

StepperMotor::StepperMotor(int direction_pin, int step_pin, int zero_pin, int sleep_pin) {
  this->direction_pin = direction_pin;
  this->step_pin = step_pin;
  this->zero_pin = zero_pin;
  this->sleep_pin = sleep_pin;

  pinMode(direction_pin, OUTPUT);
  pinMode(step_pin, OUTPUT);
  pinMode(zero_pin, OUTPUT);
  pinMode(sleep_pin, OUTPUT);
  digitalWrite(zero_pin, HIGH);
  digitalWrite(sleep_pin, HIGH);
}

void StepperMotor::rotate_motor(double angle) {
  // Set the motor to either CW or CCW
  if(angle < 0) {
    digitalWrite(this->direction_pin, HIGH);
  } else {
    digitalWrite(this->direction_pin, LOW);
  }

  int steps = int(floor(abs(angle)/1.8)); // Turns the angle into steps, remember there is 1.8 degrees/step
  for(int i = 0; i < steps; i++) { // Turns the stepper motor an amount of steps
    digitalWrite(this->step_pin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(this->step_pin, LOW);
    delayMicroseconds(2000);
  }
}