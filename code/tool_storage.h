#ifndef TOOL_STORAGE_H
#define TOOL_STORAGE_H
#include "tool.h"

class ToolStorage{
  private:
    Tool** tool_list;
    int num_tools = 2; // Number of implemented tools; Update if more are added
    Tool** initialize_tools(); // Initializes all tools that are implemented for the arm
  public:
    Tool** get_tools();
    void print_tools();
    int get_num_tools();
    Tool* get_tool_from_name(String);
    ToolStorage();
};

#endif