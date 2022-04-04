#ifndef DATATYPES_H
#define DATATYPES_H

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned long int uint32;

#define LOW 0
#define HIGH 1

typedef enum
{
    FORWARD = 0,
    BACKWARD = 1,
    MOTOR_OFF = 2
}Motor_Direction;



#endif