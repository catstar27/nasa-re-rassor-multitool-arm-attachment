#ifndef COMMAND_PROCESSOR_H
#define COMMAND_PROCESSOR_H
#include <Arduino.h>
#include "execution_data.h"

class CommandProcessor{
  public:
    ExecutionData* execution_data = NULL;
    String* split_string(String, char); // Takes an input string and a delimiter; returns an array of two substrings on the left and right of the delimiter
    void read_commands(); // Reads from serial and gets a command and number and list of arguments, passing them to process_command()
    void process_command(String, int, String*); // Checks the command and runs the appropriate function relevant to that command
    // Below are miscellaneous functions tied to commands
    void move_to(int, String*);
    void rotate_to(int, String*);
    void rotate_motor(int, String*);
    void print_tools(int, String*);
    void switch_tool(int, String*);
    void print_strategies(int, String*);
    void execute_strategy(int, String*);
};
#endif