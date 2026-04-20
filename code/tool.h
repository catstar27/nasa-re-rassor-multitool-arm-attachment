#ifndef TOOL_H
#define TOOL_H
#include "coordinate.h"
#include <Arduino.h>

// TODO: Figure out how tools will be operated and add methods to help them operate correctly
class Tool{
  private:
    String tool_name = "unnamed_tool"; // Tool name should be in snake case
    Coordinate storage_pos = Coordinate();
  public:
    String get_name();
    void set_name(String);
    Coordinate get_storage_pos();
    void set_storage_pos(Coordinate);
    Tool(String, Coordinate);
};
#endif