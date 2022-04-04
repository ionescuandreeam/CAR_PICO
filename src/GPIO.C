#include "GPIO.H"



void Set_SliceChannel(uint8 gpio)
{
    slice = pwm_gpio_to_slice_num(gpio);
    channel = pwm_gpio_to_channel(gpio);
}