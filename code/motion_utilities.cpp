#include "motion_utilities.h"
#include "math.h"
#include "coordinate.h"
#include "degrees.h"
#include "stdio.h"
#include <Arduino.h>

Coordinate MotionUtilities::get_position(){
  return Coordinate();
}

void MotionUtilities::move_toward(Coordinate destination, double approach_angle){
  Degrees target_angles = inverse_kinematics(destination, approach_angle);
  shoulder_motor1->rotate_motor(target_angles.shoulder_degree);
  shoulder_motor2->rotate_motor(-1*target_angles.shoulder_degree);
  elbow_motor->rotate_motor(target_angles.elbow_degree);
  wrist_motor->rotate_motor(target_angles.wrist_degree);
  return;
}

Degrees MotionUtilities::inverse_kinematics(Coordinate target_pos, double approach_angle){
  Degrees deg = Degrees();

  double x = target_pos.x;
  double y = target_pos.y - wrist_to_tool_len * sin(approach_angle);
  double z = target_pos.z;

  double distance_squared_xz = x*x + z*z;
  double distance_xz = sqrt(distance_squared_xz) - cos(approach_angle); //Finding the distance away from the robot arm.
  double distance_squared_disy = distance_xz*distance_xz + y*y;
  double distance_disy = sqrt(distance_squared_disy); //Finding the distance away from the robot arm.

  if(distance_disy > shoulder_to_elbow_len + elbow_to_wrist_len){
    printf("Error: coordinate too far");
    return deg;
  }

  //the wrist is at the end point of the arm, it best turn when something else calls upon it.
  deg.swivel_degree = atan2(z,x) * (180.0 / PI); //gets the angle for the swivel in radians, that is then converted to degrees.
  double angle2 = -acos((distance_squared_disy - shoulder_to_elbow_len*shoulder_to_elbow_len - elbow_to_wrist_len*elbow_to_wrist_len) / (2 * elbow_to_wrist_len * shoulder_to_elbow_len));
  double angle1 = atan2(y,distance_xz) - atan2((elbow_to_wrist_len * sin(angle2)),(elbow_to_wrist_len*cos(angle2) + shoulder_to_elbow_len));
  //Obtained the angles for the shoulder and elbow via inverse kinematics and elbow-down orientation.
  deg.shoulder_degree = angle1 * (180.0 / PI);
  deg.elbow_degree = angle2 * (180.0 / PI); 
  //Of course, the angles obtained are measured in radians so they get converted to degrees just like it wa done for the swivel.
  deg.wrist_degree = approach_angle - (deg.shoulder_degree + deg.elbow_degree);
  return deg;
}
