// functii de setare viteza, servo-directie, directie

#include "CAR.H"

void MotorDirection(Motor_Direction direction)
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
