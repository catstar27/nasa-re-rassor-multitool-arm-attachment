#include "drill_strategy.h"
#include "abstract_tool_strategy.h"

void DrillStrategy::execute(MotionUtilities* motion_utilities, Coordinate start_pos, double start_angle, Coordinate end_pos, double end_angle){
  // Likely requires tweaking
  for(int i = 0; i < revolutions; i++){
    motion_utilities->move_toward(start_pos, start_angle);
    motion_utilities->tool_motor.write(0);
    motion_utilities->move_toward(end_pos, end_angle);
    motion_utilities->tool_motor.write(180);
  }
}