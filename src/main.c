#include "datatypes.h"
#include "pwm.h"
#include "GPIO.H"
#include "CAR.H"

uint8 slice = 0;
uint8 channel = 0;

int main(void)
{  
    stdio_init_all();
    InitGPIO();
    Set_SliceChannel(6);

    uint8 duty_cycle = 100;
    uint16 wrap = pwm_set_freq_duty(50);

    Set_Speed(wrap, duty_cycle);
    pwm_set_enabled(slice, true);

    while(true)
    {
        MotorDirection(BACKWARD);
    }
}