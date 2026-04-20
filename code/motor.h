#ifndef MOTOR_H
#define MOTOR_H

class StepperMotor {
  public:
    int direction_pin;
    int step_pin;
    int zero_pin;
    int sleep_pin;

    void rotate_motor(double angle);
    StepperMotor(int direction_pin, int step_pin, int zero_pin, int sleep_pin);
};

#endif