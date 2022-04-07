#ifndef DATATYPES_H
#define DATATYPES_H

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "cfg.h"

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long int uint32;

typedef enum
{
    FORWARD = 0,
    BACKWARD = 1,
    MOTOR_OFF = 2
}Motor_Direction;



#endif