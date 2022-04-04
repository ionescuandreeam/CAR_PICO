#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "datatypes.h"

void InitGPIO(void);
uint32 pwm_set_freq_duty(uint8 slice, uint8 channel, uint32 wanted_freq, uint16 duty_cycle);
void MotorDirection(Motor_Direction direction);

int main(void)
{  
    stdio_init_all();
    InitGPIO();

    uint8 slice = pwm_gpio_to_slice_num(6);
    uint8 channel = pwm_gpio_to_channel(6);

    pwm_set_freq_duty(slice, channel, 50, 10);
    pwm_set_enabled(slice, true);

    while (true)
    {
        MotorDirection(BACKWARD);
    }

}


void InitGPIO(void)
{
    gpio_set_function(6, GPIO_FUNC_PWM);

    gpio_init(2);
    gpio_set_dir(2, GPIO_OUT);
    gpio_put(2, LOW);

    gpio_init(3);
    gpio_set_dir(3, GPIO_OUT);
    gpio_put(3, LOW);
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

uint32 pwm_set_freq_duty(uint8 slice, uint8 channel, uint32 wanted_freq, uint16 duty_cycle)
{
    uint32 clock = 125000000;
    uint32 prescaler = ((clock / wanted_freq / 4096) + (clock % (wanted_freq * 4096) != 0));
    uint32 wrap = ((clock * 16 / prescaler / 50) - 1);

    if (prescaler / 16 == 0)
    {
        prescaler = 16;
    }

    pwm_set_clkdiv_int_frac(slice, prescaler/16, prescaler & 0xF);
    pwm_set_wrap(slice, wrap);
    pwm_set_chan_level(slice, channel, wrap * duty_cycle / 100);
    return wrap;
}