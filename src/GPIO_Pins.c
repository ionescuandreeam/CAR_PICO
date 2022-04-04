#include "GPIO_Pins.h"


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

void Set_SliceChannel(uint8 gpio)
{
    slice = pwm_gpio_to_slice_num(gpio);
    channel = pwm_gpio_to_channel(gpio);
}
