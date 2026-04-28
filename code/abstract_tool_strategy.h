#ifndef ABSTRACT_TOOL_STRATEGY_H
#define ABSTRACT_TOOL_STRATEGY_H
#include "motion_utilities.h"
#include <Arduino.h>

class AbstractToolStrategy{
  /*
  Abstract base class for other Strategy classes to inherit; they must implement the execute function
  */
  public:
    String name = "unnamed"; // Name in snake case
    virtual void execute(MotionUtilities*, Coordinate, double, Coordinate, double) = 0;
};
#endif