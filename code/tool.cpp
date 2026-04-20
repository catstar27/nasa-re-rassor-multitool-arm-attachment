#include "tool.h"
#include "coordinate.h"
#include <Arduino.h>

String Tool::get_name(){
  return tool_name;
}

void Tool::set_name(String name){
  tool_name = name;
}

Coordinate Tool::get_storage_pos(){
  return storage_pos;
}

void Tool::set_storage_pos(Coordinate pos){
  storage_pos = pos;
}

Tool::Tool(String name, Coordinate storage_pos){
  this->tool_name = name;
  this->storage_pos = storage_pos;
}
