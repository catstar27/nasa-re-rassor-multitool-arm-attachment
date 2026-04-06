#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"
#include "degrees.h"

#define PI 3.14159

class MotionUtilities{
  private:
    Coordinate current_position = Coordinate();
    float shoulder_to_elbow_len = 5; // Placeholder until measurements are made and distance units decided
    float elbow_to_wrist_len = 5; // Placeholder until measurements are made and distance units decided
  public:
    Coordinate get_position();
    void move_toward(Coordinate);
    Degrees inverse_kinematics(Coordinate);
};
#endif