#include "Arduino.h"
#include "Wire.h"

#define AS5600_ADDR 0x36
#define STATUS_REG 0x0B
#define ANGLE_REG 0x0E

uint8_t readByte(uint8_t reg) {
    Wire.beginTransmission(AS5600_ADDR);
    Wire.write(reg);
    Wire.endTransmission(false);
    Wire.requestFrom(AS5600_ADDR, (uint8_t)1);
    return Wire.read();
}

uint16_t readAngle() {
    Wire.beginTransmission(AS5600_ADDR);
    Wire.write(ANGLE_REG);
    Wire.endTransmission(false);
    Wire.requestFrom(AS5600_ADDR, (uint8_t)2);
    uint16_t high = Wire.read();
    uint16_t low = Wire.read();
    return (high << 8) | low;
}

void setup() {
    Serial.begin(9600);
    Wire.begin();
}

void loop() {
    uint8_t status = readByte(STATUS_REG);
    bool magnet_detected = status & (1 << 5);
    bool too_weak = status & (1 << 4);
    bool too_strong = status & (1 << 3);

    Serial.print("Magnet detected: "); Serial.println(magnet_detected);
    Serial.print("Too weak: "); Serial.println(too_weak);
    Serial.print("Too strong: "); Serial.println(too_strong);
    Serial.print("Angle: "); Serial.println(readAngle());
    Serial.println("---");

    delay(200);
}
