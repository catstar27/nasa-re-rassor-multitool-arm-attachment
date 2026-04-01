bool state = false;

void setup() {
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(state) {
    // Magnet On
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    analogWrite(6, 0);
  } else {
    // Magnet Off
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    analogWrite(6, 255);
  }
  
  if(Serial.available() > 0) {
    String str = Serial.readString();
    str.trim();
    if(str == "on") {
      state = true;
      Serial.println(F("Turned on the EPM"));
    } else {
      state = false;
      Serial.println(F("Turned off the EPM"));
    }
  }

}
