#ifndef VOLTAGE_DATA_H
#define VOLTAGE_DATA_H

#define EPM_ARM_IN1 0
#define EPM_ARM_IN2 1
#define EPM_TOOL_IN3 2
#define EPM_TOOL_IN4 3
#define SH_STEP 4
#define SH_DIR 5
#define SH_EN 6
#define SW_STEP 7
  
#define WR_EN 8
#define WR_DIR 9
#define WR_STEP 10
#define EL_EN 11
#define EL_DIR 12
#define EL_STEP 13
#define SW_EN 14
#define SW_DIR 15
 
#define EPM_ARM_PWM 16
#define EPM_TOOL_PWM 17

class VoltageData{
  private:
    float* pin_voltages;
  public:
    void update_voltage(int, float);
};
#endif