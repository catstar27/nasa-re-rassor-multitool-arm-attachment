#ifndef MOTOR_H
#define MOTOR_H

class StepperMotor {
  public:
    int dirPin;
    int stepPin;
    int zeroPin;
    int sleepPin;

    void rotateMotor(double angle);
    StepperMotor(int dirPin, int stepPin, int zeroPin, int sleepPin);
};

#endif