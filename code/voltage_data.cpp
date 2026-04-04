#include "voltage_data.h"

void VoltageData::update_voltage(int index, float value){
  pin_voltages[index] = value;
}

/**Pins to Array indexes 
 * PA0 EPM_ARM_IN1  0
 * PA1 EPM_ARM_IN2  1
 * PA2 EPM_TOOL_IN3 2
 * PA3 EPM_TOOL_IN4 3
 * PA4 SH_STEP      4
 * PA5 SH_DIR       5
 * PA6 SH_EN        6
 * PA7 SW_STEP      7
 * 
 * PC0 WR_EN        8
 * PC1 WR_DIR       9
 * PC2 WR_STEP      10
 * PC3 EL_EN        11
 * PC4 EL_DIR       12
 * PC5 EL_STEP      13
 * PC6 SW_EN        14
 * PC7 SW_DIR       15
 * 
 * PH5 EPM_ARM_PWM  16
 * PH6 EPM_TOOL_PWM 17
*/