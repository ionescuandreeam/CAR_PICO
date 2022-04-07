#include "GPIO_Pins.h"


void InitGPIO(void)
{
    gpio_set_function(GPIO_DC1, GPIO_FUNC_PWM);
    gpio_set_function(GPIO_DC2, GPIO_FUNC_PWM);
    gpio_set_function(GPIO_SERVO, GPIO_FUNC_PWM);

    gpio_init(2);
    gpio_set_dir(2, GPIO_OUT);
    gpio_put(2, LOW);

    gpio_init(3);
    gpio_set_dir(3, GPIO_OUT);
    gpio_put(3, LOW);
}

