#ifndef EXECUTION_DATA_H
#define EXECUTION_DATA_H
#include "voltage_data.h"
#include "motion_utilities.h"

class ExecutionData{
  public:
    VoltageData voltage_data;
    MotionUtilities motion_utilities;
};
#endif