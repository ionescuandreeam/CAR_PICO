#ifndef PWM_H
#define PWM_H

#include "datatypes.h"

uint32 pwm_set_freq_duty(uint32 wanted_freq);
void Set_Speed(uint16 wrap, uint8 duty_cycle);



#endif