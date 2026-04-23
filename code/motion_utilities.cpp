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
  Degrees deg = Degrees(); //making the deg object as the thing we send to other functions.

  //Since the target of the inverse kinematics equations will be offset by the length of the wrist, we adjust the coordinates.
  double x = target_pos.x;
  double y = target_pos.y - wrist_to_tool_len * sin(approach_angle * (PI / 180)); //The minus here is the vertical offset from the wrist's length.
  double z = target_pos.z; 

  //These equations make length values that we use for IK equations and accessibility checks.
  double distance_squared_xz = x*x + z*z;
  double distance_xz = sqrt(distance_squared_xz) - wrist_to_tool_len * cos(approach_angle * (PI / 180)); //The minus here is the horizontal offset derived from wrist's length.
  double distance_squared_disy = distance_xz*distance_xz + y*y;
  double distance_disy = sqrt(distance_squared_disy); 

  //This checks to see if the robot can actually reach the desired coordinate.
  if(distance_disy > shoulder_to_elbow_len + elbow_to_wrist_len){
    printf("Error: coordinate too far");
    return deg;
  }

  //These are the inverse kinematics equations, sivel turns towards the target as this program does 2D equations to find out where the motor's base is supposedly located.
  deg.swivel_degree = atan2(z,x) * (180.0 / PI); 
  double angle2 = -acos((distance_squared_disy - shoulder_to_elbow_len*shoulder_to_elbow_len - elbow_to_wrist_len*elbow_to_wrist_len) / (2 * elbow_to_wrist_len * shoulder_to_elbow_len));
  double angle1 = atan2(y,distance_xz) - atan2((elbow_to_wrist_len * sin(angle2)),(elbow_to_wrist_len*cos(angle2) + shoulder_to_elbow_len));
  //Obtained the angles for the shoulder and elbow via inverse kinematics and elbow-down orientation in the 2d plane, using famous right triangle math to account for the horizontal coordinate being a hypotenuse of x and z.
  deg.shoulder_degree = angle1 * (180.0 / PI);
  deg.elbow_degree = angle2 * (180.0 / PI); 
  //Of course, the angles obtained are measured in radians so they get converted to degrees when placed into the storage for motor angles.
  deg.wrist_degree = approach_angle - (deg.shoulder_degree + deg.elbow_degree); //The wrists angle plus the sum of other angles equals the approach angle if we want such an angle for use.
  return deg;
}
