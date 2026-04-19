#include "SoftPWM.h"
#include "abstract_tool_strategy.h"
#include "motor.h"

#define NUM_TOOLS 1

ExecutionData* execution_data = new ExecutionData();
StepperMotor* shoulderMotor;
StepperMotor* elbowMotor;
StepperMotor* wristMotor;
StepperMotor* toolMotor;

// TODO: Function initializes tools and adds them to an array which it returns
Tool** get_tools(){
  Tool* tool_list[NUM_TOOLS];
  // TODO: Create and configure tools here
  return tool_list;
}

void setup() {
  VoltageData* voltage_data = new VoltageData();
  MotionUtilities* motion_utilities = new MotionUtilities();
  execution_data->voltage_data = voltage_data;
  execution_data->motion_utilities = motion_utilities;
  execution_data->avilable_tools = get_tools();

  Serial.begin(115200);
  delay(1000);
  shoulderMotor = new StepperMotor(4, 5, 2, 3);
  elbowMotor = new StepperMotor(6, 7, 2, 3);
  wristMotor = new StepperMotor(8, 9, 2, 3);
  toolMotor = new StepperMotor(10, 11, 2, 3);
  Serial.println(F("Starting program"));
}

void processCommands() {
  // Input -> X:1,Y:2,Z:3\n
  if(Serial.available() > 0) {
    String str = Serial.readString();
    str.trim();
    String x_pos = str.substring(str.indexOf("X:")+2, str.indexOf(",", 0));
    String y_pos = str.substring(str.indexOf("Y:")+2, str.indexOf(",", str.indexOf("Y:")));
    String z_pos = str.substring(str.indexOf("Z:")+2, str.indexOf(",", str.indexOf("Z:")));
    Serial.print(F("X: ")); Serial.println(x_pos);
    Serial.print(F("Y: ")); Serial.println(y_pos);
    Serial.print(F("Z: ")); Serial.println(z_pos);
    double x = atof(x_pos.c_str());
    double y = atof(y_pos.c_str());
    double z = atof(z_pos.c_str());

    Coordinate* armCoords = new Coordinate();
    armCoords->x = x;
    armCoords->y = y;
    armCoords->z = z;
    Degrees armDegrees = execution_data->motion_utilities->inverse_kinematics(*armCoords);
    
    Serial.print(F("Shoulder Angle: ")); Serial.println(armDegrees.shoulder_degree, 1);
    Serial.print(F("Elbow Angle: ")); Serial.println(armDegrees.elbow_degree, 1);
    Serial.print(F("Wrist Angle: ")); Serial.println(armDegrees.wrist_degree, 1);
    Serial.print(F("Swivel Angle: ")); Serial.println(armDegrees.swivel_degree, 1);

    shoulderMotor->rotateMotor(armDegrees.shoulder_degree);
    elbowMotor->rotateMotor(armDegrees.elbow_degree);
    wristMotor->rotateMotor(armDegrees.wrist_degree);
  }
}

void loop() {
  processCommands();
}
