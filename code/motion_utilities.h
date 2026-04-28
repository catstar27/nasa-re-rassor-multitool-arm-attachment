#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"
#include "degrees.h"
#include <Servo.h>

#define PI 3.14159

class MotionUtilities{
  private:
    float swivel_to_shoulder_len = 50;
    float shoulder_to_elbow_len = 158; // Placeholder until measurements are made and distance units decided
    float elbow_to_wrist_len = 145; // Placeholder until measurements are made and distance units decided
    float wrist_to_tool_len = 135;
  public:
    Servo swivel_motor;
    Servo shoulder_motor;
    Servo elbow_motor;
    Servo wrist_motor;
    Servo tool_motor;
    Coordinate get_position();
    void move_toward(Coordinate, double);
    void rotate_angles(double, double, double, double);
    Degrees inverse_kinematics(Coordinate, double);
    MotionUtilities();
};
#endif