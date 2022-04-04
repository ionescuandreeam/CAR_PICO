#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "datatypes.h"
/*
requirements:
    1. functie in care setam directia rotii 

    In1 In2 
    0   1  -> dreapta    -> PUN PE PWM PIN HIGH 
    1   0  -> stanga     -> PUN PE PWM PIN HIGH
    1   1  -> Nu se invarte 
    0   0  -> Nu se invarte 

    2. functie care seteaza viteza motorului 
*/

void Init(void);
void MotorDirection(Motor_Direction direction);

int main(void)
{  
    stdio_init_all();
    Init();

    while (true)
    {
        MotorDirection(FORWARD);
    }


}

hello word hello
void Init(void)
{
    gpio_init(2);
    gpio_set_dir(2, GPIO_OUT);
    gpio_put(2, LOW);

    gpio_init(3);
    gpio_set_dir(3, GPIO_OUT);
    gpio_put(3, LOW);

    gpio_init(6);
    gpio_set_dir(6, GPIO_OUT);
    gpio_put(6, HIGH);

}

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