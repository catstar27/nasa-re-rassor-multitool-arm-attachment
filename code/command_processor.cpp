#include "command_processor.h"
#include <Arduino.h>
#include "execution_data.h"

String* CommandProcessor::split_string(String target, char delimiter){
  int target_len = strlen(target.c_str());
  int split_index = -1;
  for(int i = 0; i < target_len; i++){
    if(target[i] == delimiter){
      split_index = i;
      break;
    }
  }
  String left = target.substring(0, split_index);
  String right;
  if(split_index == -1) right = ""; // If delimiter not found, right is empty
  else right = target.substring(split_index+1);
  String* out = calloc(2, sizeof(String));
  out[0] = left;
  out[1] = right;
  return out;
}

void CommandProcessor::read_commands(){
  if(Serial.available() > 0) {
    String input_str = Serial.readString();
    input_str.trim();
    String* processed_str = split_string(input_str, ' ');
    String command = processed_str[0];
    String arg_string = processed_str[1];
    int arg_string_len = strlen(arg_string.c_str());
    int num_args = 0;
    if(arg_string_len > 0) num_args++;
    for(int i = 0; i < arg_string_len; i++) if(arg_string[i] == ' ') num_args++;
    String* arg_arr = calloc(num_args, sizeof(String));
    for(int i = 0; i < num_args; i++){
      String* arg_string_processed = split_string(arg_string, ' ');
      arg_arr[i] = arg_string_processed[0];
      arg_string = arg_string_processed[1];
    }
    process_command(command, num_args, arg_arr);
  }
}

void CommandProcessor::process_command(String command, int num_args, String* args){
  if(execution_data == NULL){
    Serial.println(F("Execution data uninitialized! Cannot process commands!"));
    return;
  }
  if(command == "move_to") move_to(num_args, args);
  else if(command == "print_tools") print_tools(num_args, args);
  else if(command == "switch_tool") switch_tool(num_args, args);
  else Serial.println(F("Unknown Command"));
}

void CommandProcessor::move_to(int num_args, String* args){
  if(num_args != 3) Serial.println(F("move_to requires 3 arguments: x, y, and z coordinates"));
  else{
    double x = atof(args[0].c_str());
    double y = atof(args[1].c_str());
    double z = atof(args[2].c_str());

    Coordinate* target_pos = new Coordinate(x, y, z);
    Degrees arm_degrees = execution_data->motion_utilities->inverse_kinematics(*target_pos);
    
    Serial.print(F("Shoulder Angle: "));
    Serial.println(arm_degrees.shoulder_degree, 1);
    Serial.print(F("Elbow Angle: "));
    Serial.println(arm_degrees.elbow_degree, 1);
    Serial.print(F("Wrist Angle: "));
    Serial.println(arm_degrees.wrist_degree, 1);
    Serial.print(F("Swivel Angle: "));
    Serial.println(arm_degrees.swivel_degree, 1);
    execution_data->motion_utilities->move_toward(*target_pos);
  }
}

void CommandProcessor::print_tools(int num_args, String* args){
  if(num_args > 0) Serial.println(F("print_tools does not take any arguments!"));
  else{
    int num_tools = execution_data->tool_storage->get_num_tools();
    Tool** tools = execution_data->tool_storage->get_tools();
    for (int i = 0; i < num_tools; i++) {
      Serial.print(F("Tool: "));
      Serial.print(tools[i]->get_name());
      Serial.print(F("\tStored At: "));
      if(execution_data->current_tool == tools[i]){
        Serial.println(F("In hand"));
      } 
      else{
        Coordinate stored_at = tools[i]->get_storage_pos();
        Serial.print(stored_at.x);
        Serial.print(F("x, "));
        Serial.print(stored_at.y);
        Serial.print(F("y, "));
        Serial.print(stored_at.z);
        Serial.println(F("z"));
      }
    }
  }
}

void CommandProcessor::switch_tool(int num_args, String* args){
  if(num_args != 1) Serial.println(F("switch_tool takes one argument, tool name!"));
  else{
    execution_data->switch_tool(args[0]);
  }
}
