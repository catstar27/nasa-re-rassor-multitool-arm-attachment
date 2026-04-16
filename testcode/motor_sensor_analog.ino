#include "Arduino.h"

int sensor_pin = A0;
int motor_position = 0;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	motor_position = analogRead(sensor_pin);
	Serial.print("Motor: ");
	Serial.println(motor_position);
}
