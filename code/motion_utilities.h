#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"
#include "degrees.h"
#include "motor.h"

#define PI 3.14159

class MotionUtilities{
  private:
    StepperMotor* shoulder_motor1 = new StepperMotor(28, 29, 2, 3);
    StepperMotor* shoulder_motor2 = new StepperMotor(24, 25, 2 ,3);
    StepperMotor* elbow_motor = new StepperMotor(22, 23, 2, 3);
    StepperMotor* wrist_motor = new StepperMotor(26, 27, 2, 3);
    StepperMotor* tool_motor = new StepperMotor(10, 11, 2, 3);
    float swivel_to_shoulder_len = 50;
    float shoulder_to_elbow_len = 158; // Placeholder until measurements are made and distance units decided
    float elbow_to_wrist_len = 145; // Placeholder until measurements are made and distance units decided
    float wrist_to_tool_len = 135;
  public:
    Coordinate get_position();
    void move_toward(Coordinate, double);
    Degrees inverse_kinematics(Coordinate, double);
};
#endif