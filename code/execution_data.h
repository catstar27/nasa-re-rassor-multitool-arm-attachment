#ifndef EXECUTION_DATA_H
#define EXECUTION_DATA_H
#include "voltage_data.h"
#include "motion_utilities.h"
#include "tool.h"

class ExecutionData{
  private:
    Tool* current_tool;
  public:
    VoltageData* voltage_data;
    MotionUtilities* motion_utilities;
    Tool** avilable_tools;
};
#endif