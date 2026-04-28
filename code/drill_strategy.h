#ifndef DRILL_STRATEGY_H
#define DRILL_STRATEGY_H
#include "abstract_tool_strategy.h"
#include <Arduino.h>

class DrillStrategy: public AbstractToolStrategy{
  /*
  A strategy designed to rotate a drill and push it into a surface
  */
  public:
    int revolutions = 10;
    void execute(MotionUtilities*, Coordinate, double, Coordinate, double) override;
};
#endif