#ifndef TOOL_STORAGE_H
#define TOOL_STORAGE_H
#include "tool.h"

class ToolStorage{
  /*
  Stores references to all implemented tool heads
  Must be manually updated when new ones are added by increasing num_tools and adding the new tool to initialize_tools()
  */
  private:
    Tool** tool_list;
    int num_tools = 2; // Number of implemented tools; Update if more are added
    Tool** initialize_tools(); // Initializes all tools that are implemented for the arm
  public:
    Tool** get_tools(); // Gets a fresh array pointing to each tool
    void print_tools(); // Prints all tools in tool_list
    int get_num_tools(); // Returns num_tools
    Tool* get_tool_from_name(String); // Given a string equal to the name of a tool, returns a pointer to that tool
    ToolStorage(); // Automatically runs initialize_tools() in the constructor
};

#endif