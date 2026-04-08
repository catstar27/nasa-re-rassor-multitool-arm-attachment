#include "motion_utilities.h"
#include "math.h"
#include "coordinate.h"
#include "degrees.h"
#include <Arduino.h>

Coordinate MotionUtilities::get_position(){
  return current_position;
}
void MotionUtilities::move_toward(Coordinate destination){
  return;
}

Degrees MotionUtilities::inverse_kinematics(Coordinate target_pos){
  Degrees deg = Degrees();

  double distance_squared_xz = target_pos.x*target_pos.x + target_pos.z*target_pos.z;
  double distance_xz = sqrt(distance_squared_xz); //Finding the distance away from the robot arm.
  double distance_squared_disy = distance_xz*distance_xz + target_pos.y*target_pos.y;
  double distance_disy = sqrt(distance_squared_disy); //Finding the distance away from the robot arm.

  if(distance > shoulder_to_elbow_len + elbow_to_wrist_len){
    Serial.print("Error: coordinate too far");
    return deg;
  }

  deg.wrist_degree = 0; //the wrist is at the end point of the arm, it best turn when something else calls upon it.
  deg.swivel_degree = atan(target_pos.z/target_pos.x) * (180.0 / PI); //gets the angle for the swivel in radians, that is then converted to degrees.
  double angle2 = -acos((distance_squared_disy - shoulder_to_elbow_len*shoulder_to_elbow_len - elbow_to_wrist_len*elbow_to_wrist_len) / (2 * elbow_to_wrist_len * shoulder_to_elbow_len));
  double angle1 = atan((elbow_to_wrist_len * sin(angle2))/(elbow_to_wrist_len*cos(angle2) + shoulder_to_elbow_len));
  //Obtained the angles for the shoulder and elbow via inverse kinematics and elbow-down orientation.
  deg.shoulder_degree = angle1 * (180.0 / PI);
  deg.elbow_degree = angle2 * (180.0 / PI); 
  //Of course, the angles obtained are measured in radians so they get converted to degrees just like it wa done for the swivel.
  return deg;
}
