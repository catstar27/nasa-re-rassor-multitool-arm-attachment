#ifndef TOOL_H
#define TOOL_H
#include "coordinate.h"
#include <Arduino.h>

class Tool{
  /*
  Simple class for tracking tools by name
  Also assigns them a storage position which is used for tool switching
  */
  private:
    String tool_name = "unnamed_tool"; // Tool name should be in snake case
    Coordinate storage_pos = Coordinate(); // Position at which the tool has been stored; must be initialized
  public:
    String get_name(); // Returns this tool's name
    void set_name(String); // Sets this tool's name
    Coordinate get_storage_pos(); // Gets storage_pos
    void set_storage_pos(Coordinate); // Sets storage_pos
    Tool(String, Coordinate); // Constructs a tool and assigns it the given name and storage_pos
};
#endif