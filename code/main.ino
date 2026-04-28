#include "SoftPWM.h"
#include "abstract_tool_strategy.h"
#include "command_processor.h"

ExecutionData* execution_data = new ExecutionData();
CommandProcessor* command_processor = new CommandProcessor();

void setup() {
  Serial.begin(115200);
  delay(1000);
  command_processor->execution_data = execution_data;
  Serial.println(F("Starting program"));
}

void loop() {
  command_processor->read_commands();
}
