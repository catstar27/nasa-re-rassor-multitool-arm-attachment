#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"
#include "degrees.h"
#include "motor.h"

#define PI 3.14159

class MotionUtilities{
  private:
    StepperMotor* shoulder_motor = new StepperMotor(4, 5, 2, 3);
    StepperMotor* elbow_motor = new StepperMotor(6, 7, 2, 3);
    StepperMotor* wrist_motor = new StepperMotor(8, 9, 2, 3);
    StepperMotor* tool_motor = new StepperMotor(10, 11, 2, 3);
    float shoulder_to_elbow_len = 10; // Placeholder until measurements are made and distance units decided
    float elbow_to_wrist_len = 10; // Placeholder until measurements are made and distance units decided
  public:
    Coordinate get_position();
    void move_toward(Coordinate);
    Degrees inverse_kinematics(Coordinate);
};
#endif