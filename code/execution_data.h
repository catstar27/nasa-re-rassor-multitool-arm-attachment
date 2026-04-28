#ifndef EXECUTION_DATA_H
#define EXECUTION_DATA_H
#include "motion_utilities.h"
#include "tool.h"
#include "tool_storage.h"
#include "strategy_storage.h"
#include <Arduino.h>

class ExecutionData{
  /*
  Set of class instances that must be passed around for functionality
  Also tracks current tool
  */
  public:
    Tool* current_tool;
    MotionUtilities* motion_utilities = new MotionUtilities();
    ToolStorage* tool_storage = new ToolStorage();
    StrategyStorage* strategy_storage = new StrategyStorage();
    void switch_tool(String);
};
#endif