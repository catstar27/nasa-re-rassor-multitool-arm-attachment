#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H
#include <Arduino.h>
#include "execution_data.h"

class CommandProcessor{
  public:
    ExecutionData* execution_data = NULL;
    String* split_string(String, char);
    void read_commands();
    void process_command(String, int, String*);
    void move_to(int, String*);
    void print_tools(int, String*);
    void switch_tool(int, String*);
};
#endif