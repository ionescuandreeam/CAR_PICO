#include "datatypes.h"
#include "pwm.h"
#include "GPIO_Pins.h"
#include "CAR.h"

uint8 slice = 0;
uint8 channel = 0;
uint16 wrap = 0;

int main(void)
{  
    stdio_init_all();
    InitGPIO();
    Set_SliceChannel(6);

    uint8 duty_cycle = 100;
    wrap = pwm_set_freq_duty(50);

    Set_Speed(duty_cycle);
    pwm_set_enabled(slice, true);

void Motor1_Speed()
{
    
}

    while(true)
    {
        Set_MotorDirection(BACKWARD);
    }
}