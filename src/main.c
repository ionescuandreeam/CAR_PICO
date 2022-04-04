#include "datatypes.h"
#include "pwm.h"
#include "GPIO_Pins.h"
#include "CAR.h"
// GPIO 6 - Slice 3 Channel 0

uint8 slice = 3;
uint8 channel = 0;
uint16 wrap = 0;

int main(void)
{  
    stdio_init_all();
    InitGPIO();
    pwm_Init();

    uint8 speed = 100;
    pwm_set_enabled(slice, true);

    void Set_PWM1();

    while(true)
    {
        Set_MotorDirection(BACKWARD);
        Car_Speed(speed);
    }
}