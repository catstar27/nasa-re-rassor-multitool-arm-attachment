#include <SoftwareWire.h>

#define AS5600_ADDR 0x36
#define STATUS_REG 0x0B
#define ANGLE_REG 0x0E

// param1 is sda, param2 is scl
SoftwareWire sensorWire1(16, 17);
SoftwareWire sensorWire2(14, 15);
SoftwareWire sensorWire3(18, 19);

uint8_t readByte(SoftwareWire wire, uint8_t reg) {
    int ret;

    wire.beginTransmission(AS5600_ADDR);
    wire.write(reg);
    ret = wire.endTransmission(false);
    if (ret != SOFTWAREWIRE_NO_ERROR) {
       Serial.print("I2C error on transmission: ");
       Serial.println(ret);
    }

    wire.requestFrom(AS5600_ADDR, (uint8_t)1);
    return wire.read();
}

uint16_t readAngle(SoftwareWire wire) {
    wire.beginTransmission(AS5600_ADDR);
    wire.write(ANGLE_REG);
    wire.endTransmission(false);
    wire.requestFrom(AS5600_ADDR, (uint8_t)2);
    uint16_t high = wire.read();
    uint16_t low = wire.read();
    return (high << 8) | low;
}

static inline void printSensor(SoftwareWire wire, int n) {
  uint8_t status = readByte(wire, STATUS_REG);
  bool magnet_detected = status & (1 << 5);
  bool too_weak = status & (1 << 4);
  bool too_strong = status & (1 << 3);
  uint16_t angle = readAngle(wire);

  Serial.print("---Magnet Sensor ");
  Serial.print(n);
  Serial.println("---");
  Serial.print(F("Magnet detected: ")); Serial.println(magnet_detected);
  Serial.print(F("Too weak: ")); Serial.println(too_weak);
  Serial.print(F("Too strong: ")); Serial.println(too_strong);
  Serial.print(F("Angle: ")); Serial.println(angle);
  Serial.println(F("---"));
}

void setup() {
  sensorWire1.begin();
  sensorWire2.begin();
  sensorWire3.begin();

  Serial.begin(115200);
  delay(1000);
  Serial.println(F("Started program"));
}

void loop() {
  printSensor(sensorWire1, 1);
  printSensor(sensorWire2, 2);
  printSensor(sensorWire3, 3);

  delay(200);
}
