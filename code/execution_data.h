#ifndef EXECUTION_DATA_H
#define EXECUTION_DATA_H
#include "voltage_data.h"
#include "motion_utilities.h"
#include "tool.h"
#include "tool_storage.h"

class ExecutionData{
  public:
    Tool* current_tool;
    VoltageData* voltage_data = new VoltageData();
    MotionUtilities* motion_utilities = new MotionUtilities();
    ToolStorage* tool_storage = new ToolStorage();
};
#endif