#ifndef CAR_H
#define CAR_H

#include "datatypes.h"
#include "pwm.h"

extern void Set_MotorDirection(Motor_Direction direction);
extern void Car_Speed(uint8 speed);
extern void Car_ServoDirection(float degree);




#endif