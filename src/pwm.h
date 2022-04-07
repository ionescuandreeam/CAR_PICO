#ifndef PWM_H
#define PWM_H

#include "datatypes.h"
#include "cfg.h"

extern void pwm_Init();
extern void Pwm_set_DC1_DutyCycle(uint8 dutycycle);
extern void Pwm_set_DC2_DutyCycle(uint8 dutycycle);
extern void Pwm_set_SERVO_DutyCycle(float dutycycle);

#endif