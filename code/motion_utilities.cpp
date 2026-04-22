#include "motion_utilities.h"
#include "math.h"
#include "coordinate.h"
#include "degrees.h"
#include <Arduino.h>
#include <InverseK.h>

Coordinate MotionUtilities::get_position(){
  return current_position;
}
void MotionUtilities::move_toward(Coordinate destination){
  return;
}

float b2a(float b){
  return b / 180.0 * PI - HALF_PI;
}

// Quick conversion from radians to the Braccio angle system
float a2b(float a) {
  return (a + HALF_PI) * 180 / PI;
}

Degrees MotionUtilities::inverse_kinematics(Coordinate target_pos){
  Degrees deg = Degrees();

  Link base, shoulder, elbow, wrist;

  base.init(10, b2a(0.0), b2a(180.0));
  shoulder.init(100, b2a(0.0), b2a(180.0));
  elbow.init(100, b2a(-60.0), b2a(160.0));
  wrist.init(10, b2a(0.0), b2a(180.0));

  InverseK.attach(base, shoulder, elbow, wrist);

  float a0, a1, a2, a3;

  if(InverseK.solve(target_pos.x, target_pos.y, target_pos.z, a0, a1, a2, a3)) {
    deg.swivel_degree = a2b(a0);
    deg.shoulder_degree = a2b(a1);
    deg.elbow_degree = a2b(a2);
    deg.wrist_degree = a2b(a3);
  } else {
    Serial.println(F("No Inverse Kinematic Soltuion Found!"));
  }

  // double distance_squared_xz = target_pos.x*target_pos.x + target_pos.z*target_pos.z;
  // double distance_xz = sqrt(distance_squared_xz); //Finding the distance away from the robot arm.
  // double distance_squared_disy = distance_xz*distance_xz + target_pos.y*target_pos.y;
  // double distance_disy = sqrt(distance_squared_disy); //Finding the distance away from the robot arm.

  // if(distance_disy > shoulder_to_elbow_len + elbow_to_wrist_len){
  //   Serial.print("Error: coordinate too far");
  //   return deg;
  // }

  // deg.wrist_degree = 0; //the wrist is at the end point of the arm, it best turn when something else calls upon it.
  // deg.swivel_degree = atan(target_pos.z/target_pos.x) * (180.0 / PI); //gets the angle for the swivel in radians, that is then converted to degrees.
  // double angle2 = -acos((distance_squared_disy - shoulder_to_elbow_len*shoulder_to_elbow_len - elbow_to_wrist_len*elbow_to_wrist_len) / (2 * elbow_to_wrist_len * shoulder_to_elbow_len));
  // double angle1 = atan(target_pos.y/distance_xz) - atan((elbow_to_wrist_len * sin(angle2))/(elbow_to_wrist_len*cos(angle2) + shoulder_to_elbow_len));
  // //Obtained the angles for the shoulder and elbow via inverse kinematics and elbow-down orientation.
  // deg.shoulder_degree = -angle2 * (180.0 / PI);
  // deg.elbow_degree = -angle1 * (180.0 / PI); 
  // //Of course, the angles obtained are measured in radians so they get converted to degrees just like it wa done for the swivel.
  return deg;
}
