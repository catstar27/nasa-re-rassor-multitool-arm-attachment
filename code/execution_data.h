#ifndef EXECUTION_DATA_H
#define EXECUTION_DATA_H
#include "motion_utilities.h"
#include "tool.h"
#include "tool_storage.h"
#include <Arduino.h>

class ExecutionData{
  public:
    Tool* current_tool;
    MotionUtilities* motion_utilities = new MotionUtilities();
    ToolStorage* tool_storage = new ToolStorage();
    void switch_tool(String);
};
#endif