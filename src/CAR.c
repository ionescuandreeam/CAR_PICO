// functii de setare viteza, servo-directie, directie

#include "CAR.h"

void Set_MotorDirection(Motor_Direction direction)
{
    if(direction == FORWARD)
    {
        gpio_put(2, HIGH);
        gpio_put(3, LOW);
    } 
    else if(direction == BACKWARD)
    {
        gpio_put(2, LOW);
        gpio_put(3, HIGH);
    }
    else
    {
        gpio_put(2, LOW);
        gpio_put(3, LOW);
    }
}

void Car_Speed(uint8 speed)
{
    Pwm_set_DC1_DutyCycle(speed);
    Pwm_set_DC2_DutyCycle(speed);
    
}