#ifndef SCOOP_STRATEGY_H
#define SCOOP_STRATEGY_H
#include "abstract_tool_strategy.h"
#include <Arduino.h>

class ScoopStrategy: public AbstractToolStrategy{
  /*
  A strategy designed to perform a scooping maneuver for excavation
  */
  public:
    void execute(MotionUtilities*, Coordinate, double, Coordinate, double) override;
};
#endif