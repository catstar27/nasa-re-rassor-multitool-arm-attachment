#include "execution_data.h"
#include "motion_utilities.h"
#include "tool.h"
#include "tool_storage.h"
#include <Arduino.h>

void ExecutionData::switch_tool(String new_tool_name){
  Tool* new_tool = tool_storage->get_tool_from_name(new_tool_name);
  if(new_tool == NULL){
    Serial.print(F("Attempted to switch to invalid tool: "));
    Serial.println(new_tool_name);
    return;
  }
  if(current_tool != NULL && motion_utilities->get_position() != current_tool->get_storage_pos()){
    motion_utilities->move_toward(current_tool->get_storage_pos(), 0.0);
    // TODO: Add Magnet activation and deactivation so tool head can switch
    Serial.println(F("WIP: Deactivate Magnet"));
    current_tool = NULL;
  }
  if(motion_utilities->get_position() != new_tool->get_storage_pos()){
    motion_utilities->move_toward(new_tool->get_storage_pos(), 0.0);
  }
  Serial.println(F("WIP: Activate Magnet"));
  current_tool = new_tool;
}