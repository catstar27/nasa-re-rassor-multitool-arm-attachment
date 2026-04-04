#ifndef VOLTAGE_DATA_H
#define VOLTAGE_DATA_H

class VoltageData{
  private:
    float* pin_voltages;
  public:
    void update_voltage(int, float);
};
#endif