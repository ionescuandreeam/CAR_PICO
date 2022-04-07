#include "datatypes.h"
#include "pwm.h"
#include "GPIO_Pins.h"
#include "CAR.h"
#include "cfg.h"

int main(void)
{  
    stdio_init_all();
    InitGPIO();
    pwm_Init();
    float i = 0;

    uint8 speed = 15;

    while(true)
    {
        Set_MotorDirection(BACKWARD);
        Car_Speed(speed);

        for(i = 5; i <= 10; i+=0.1)
        {
            Car_ServoDirection(i);
            sleep_ms(100);
        }
        
        for(i = 10; i >= 5; i-=0.1)
        {
            Car_ServoDirection(i);
            sleep_ms(100);
        }
    }
}