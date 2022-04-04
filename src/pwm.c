#include "pwm.h"


uint32 pwm_set_freq_duty(uint32 wanted_freq)
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
    return wrap;
}

void Set_Speed(uint16 wrap, uint8 duty_cycle)
{
    pwm_set_chan_level(slice, channel, wrap * duty_cycle / 100);
}