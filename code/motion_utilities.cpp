#include "motion_utilities.h"
#include "math.h"
#include "coordinate.h"
#include "degrees.h"
#include "stdio.h"

float Length_Shoulder_To_Elbow = 5;
float Length_Elbow_To_Wrist = 5; 
//Temporary placeholder length values until we measure the arm lengths 
//and have the units that Coordinate object will be measured in. - Dmitry K

Coordinate MotionUtilities::get_position(){
  return current_position;
}
void MotionUtilities::move_toward(Coordinate){
  return;
}

Degrees inverseKinematics(Coordinate){
double pi = 3.14159;
Coordinate coords = Coordinate();
Degrees deg = Degrees();  //Defining objects and pi constant

double distance_squared = coords.x*coords.x + coords.y*coords.y;
double distance = sqrt(distance_squared); //Finding the distance away from the robot arm.

if(distance > Length_Shoulder_To_Elbow + Length_Elbow_To_Wrist){
  printf("Error: coordinate too far");
  return deg;
}

 deg.wrist_degree = 0; //the wrist is at the end point of the arm, it best turn when something else calls upon it.
 deg.swivel_degree = atan(coords.z/coords.x) * (180.0 / pi); //gets the angle for the swivel in radians, that is then converted to degrees.
 double angle2 = -acos((distance - Length_Shoulder_To_Elbow*Length_Shoulder_To_Elbow - Length_Elbow_To_Wrist*Length_Elbow_To_Wrist) / (2 * Length_Elbow_To_Wrist * Length_Shoulder_To_Elbow));
 double angle1 = atan((Length_Elbow_To_Wrist * sin(angle2))/(Length_Elbow_To_Wrist*cos(angle2) + Length_Shoulder_To_Elbow));
//Obtained the angles for the shoulder and elbow via inverse kinematics and elbow-down orientation.
 deg.shoulder_degree = angle1 * (180.0 / pi);
 deg.elbow_degree = angle2 * (180.0 / pi); 
 //Of course, the angles obtained are measured in radians so they get converted to degrees just like it wa done for the swivel.
  return deg;
}