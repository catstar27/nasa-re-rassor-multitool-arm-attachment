#include "SoftPWM.h"
#include "abstract_tool_strategy.h"

#define NUM_TOOLS 1

ExecutionData* execution_data = new ExecutionData();

// TODO: Function initializes tools and adds them to an array which it returns
Tool** get_tools(){
  Tool* tool_list[NUM_TOOLS];
  // TODO: Create and configure tools here
  return tool_list;
}

void setup() {
  VoltageData* voltage_data = new VoltageData();
  MotionUtilities* motion_utilities = new MotionUtilities();
  execution_data->voltage_data = voltage_data;
  execution_data->motion_utilities = motion_utilities;
  execution_data->avilable_tools = get_tools();
}

void loop() {
  // put your main code here, to run repeatedly:

}
