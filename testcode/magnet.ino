bool state = false;

void setup() {
    pinMode(4, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    // turns magnet on or off based on state (connects to MOSFET to provide 12VDC)
    digitalWrite(4, (state) ? HIGH : LOW);

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
