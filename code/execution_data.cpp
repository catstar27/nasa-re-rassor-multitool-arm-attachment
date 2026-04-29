#include "execution_data.h"
#include "motion_utilities.h"
#include "tool.h"
#include "tool_storage.h"
#include <Arduino.h>
#include "magnet.h"

void ExecutionData::switch_tool(String new_tool_name){
  Tool* new_tool = tool_storage->get_tool_from_name(new_tool_name);
  if(new_tool == NULL){
    Serial.print(F("Attempted to switch to invalid tool: "));
    Serial.println(new_tool_name);
    return;
  }
  if(current_tool != NULL){
    motion_utilities->move_toward(current_tool->get_storage_pos(), 0.0);
    magnet1->set_simultaneously(magnet2, false);
    current_tool = NULL;
  }
  motion_utilities->move_toward(new_tool->get_storage_pos(), 0.0);
  magnet1->set_simultaneously(magnet2, true);
  current_tool = new_tool;
}