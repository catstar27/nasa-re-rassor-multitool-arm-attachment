#ifndef MOTION_UTILITIES_H
#define MOTION_UTILITIES_H
#include "coordinate.h"

class MotionUtilities{
  private:
    Coordinate current_position;
  public:
    Coordinate get_position();
    void move_toward(Coordinate);
};
#endif