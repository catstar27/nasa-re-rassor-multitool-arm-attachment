#include <math.h>

#define dirPin 8 // set this pin to low for CW spin, set to high for CCW spin
#define stepPin 9 // 1.8 degrees/step
#define zeroPin 10 // Pull this pin low to zero the motor
#define sleepPin 11 // Pull this pin low to stop inputs from working (do not recommend)
#define stepsPerRevolution 200

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(zeroPin, OUTPUT);
  pinMode(sleepPin, OUTPUT);
  digitalWrite(zeroPin, HIGH);
  digitalWrite(sleepPin, HIGH);
  Serial.println(F("Starting program"));
}

void rotateMotor(double angle) {
  // Set the motor to either CW or CCW
  if(angle < 0) {
    digitalWrite(dirPin, HIGH);
  } else {
    digitalWrite(dirPin, LOW);
  }

  int steps = int(floor(abs(angle)/1.8)); // Turns the angle into steps, remember there is 1.8 degrees/step
  for(int i = 0; i < steps; i++) { // Turns the stepper motor an amount of steps
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(2000);
    digitalWrite(stepPin, LOW);
    delayMicroseconds(2000);
  }
}

void processCommands() {
  if(Serial.available() > 0) {
    String str = Serial.readString();
    str.trim(); // Remove whitespace from the input
    String cmd = str.substring(0, str.indexOf(' ')); // Gets all of an input string before a space is entered
    String arg = str.substring(str.indexOf(' ') + 1); // Gets all of an input string after a space is entered
    if(cmd == "spin") {
      bool negative = false;
      if(arg.indexOf('-') != -1) { // If there is a negative character in the argument string, remove it and set the negative flag to true
        arg.replace('-', '\n');
        arg.trim();
        negative = true;
      }

      double angle = atof(arg.c_str()) * (negative ? -1 : 1); // Gets the angle from the argument string
      rotateMotor(angle);
    }
  }
}

void loop() {
  processCommands();
}
