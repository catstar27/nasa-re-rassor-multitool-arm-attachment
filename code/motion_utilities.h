#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"
#include "degrees.h"
#include <Servo.h>

#define PI 3.14159

class MotionUtilities{
  /*
  Controls all movement and motors for the arm
  Contains arm measurements that must be updated if changes are made
  */
  private:
    float swivel_to_shoulder_len = 50;
    float shoulder_to_elbow_len = 158;
    float elbow_to_wrist_len = 145;
    float wrist_to_tool_len = 135;
    bool target_reached(int, Servo, int); // Waits for the given servo to reach the target angle; returns true when it does, or false if it takes too long for the given tolerance
    void check_angles_reached(int, int, int, int); // Waits for each of the four main servos to reach their target in a set time and prints an error if they dont
  public:
    Servo swivel_motor;
    Servo shoulder_motor;
    Servo elbow_motor;
    Servo wrist_motor;
    Servo tool_motor;
    void move_toward(Coordinate, double); // Moves the arm to the target position at the given approach angle
    void rotate_angles(double, double, double, double); // Rotates each servo (other than the tool servo) to the respective angles
    Degrees inverse_kinematics(Coordinate, double); // Performs IK calculations and returns a set of angles for the motors to rotate to
    MotionUtilities();
};
#endif