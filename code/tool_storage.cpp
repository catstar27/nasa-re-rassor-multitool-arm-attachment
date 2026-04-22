#include "tool_storage.h"
#include "tool.h"
#include <Arduino.h>

Tool** ToolStorage::initialize_tools(){
  Tool** tools = calloc(num_tools, sizeof(Tool*));
  // Initialize tools here
  tools[0] = new Tool("drill", Coordinate(1,0,0));
  tools[1] = new Tool("scoop", Coordinate(2,0,0));
  return tools;
}

ToolStorage::ToolStorage(){
  this->tool_list = initialize_tools();
}

Tool** ToolStorage::get_tools(){
  Tool** tools = calloc(num_tools, sizeof(Tool*));
  for(int i = 0; i < num_tools; i++){
    tools[i] = tool_list[i];
  }
  return tools;
}

int ToolStorage::get_num_tools(){
  return num_tools;
}

Tool* ToolStorage::get_tool_from_name(String name){
  for(int i = 0; i < num_tools; i++){
    if(tool_list[i]->get_name() == name) return tool_list[i];
  }
  return NULL;
}
