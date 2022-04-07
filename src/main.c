#include "datatypes.h"
#include "pwm.h"
#include "GPIO_Pins.h"
#include "CAR.h"

int main(void)
{  
    stdio_init_all();
    InitGPIO();
    pwm_Init();

    uint8 speed = 15;

    while(true)
    {
        Set_MotorDirection(BACKWARD);
        Car_Speed(speed);
    }
}