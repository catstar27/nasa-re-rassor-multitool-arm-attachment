#define dirPin 8
#define stepPin 9
#define stepsPerRevolution 200

void setup() {
  Serial.begin(115200);
  delay(1000);
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  Serial.println(F("Starting program"));
}

void loop() {
  digitalWrite(dirPin, HIGH);
  if(Serial.available() > 0) {
    String str = Serial.readString();
    str.trim();
    if(str == "spin") {
      Serial.println(F("Spinning 90 degrees"));
      for(int i = 0; i < 50; i++) {
        digitalWrite(stepPin, HIGH);
        delayMicroseconds(2000);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(2000);
      }
    }
  }
}
