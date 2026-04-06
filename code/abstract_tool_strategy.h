#ifndef ABSTRACT_TOOL_STRATEGY_H
#define ABSTRACT_TOOL_STRATEGY_H
#include "execution_data.h"

class AbstractToolStrategy{
  public:
    void execute(ExecutionData*);
    void switch_tool(ExecutionData*, Tool*, Coordinate);
};
#endif