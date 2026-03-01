#include "voltage_data.h"

void VoltageData::update_voltage(int index, float value){
  pin_voltages[index] = value;
}