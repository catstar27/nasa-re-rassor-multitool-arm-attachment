#include "abstract_tool_strategy.h"
#include "execution_data.h"

void AbstractToolStrategy::execute(ExecutionData* execution_data){
  return;
}

void AbstractToolStrategy::switch_tool(ExecutionData* execution_data, Tool* , Coordinate new_tool_position){
  if(execution_data->motion_utilities->get_position() != new_tool_position) 
    execution_data->motion_utilities->move_toward(new_tool_position);
  else return; // TODO: Add code for switching tool head
}