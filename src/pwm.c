#include "pwm.h"

static uint16 slice_DC1;
static uint16 slice_DC2;
static uint16 slice_SERVO;
static uint16 channel_DC1;
static uint16 channel_DC2;
static uint16 channel_SERVO;
static uint16 wrap_DC1;
static uint16 wrap_DC2;
static uint16 wrap_SERVO;

static uint32 pwm_set_freq_duty_DC(uint8 slice, uint32 wanted_freq);


void pwm_Init()
{
    slice_DC1 = pwm_gpio_to_slice_num(GPIO_DC1);
    channel_DC1 = pwm_gpio_to_channel(GPIO_DC1);

    slice_DC2 = pwm_gpio_to_slice_num(GPIO_DC2);
    channel_DC2 = pwm_gpio_to_channel(GPIO_DC2);

    slice_SERVO = pwm_gpio_to_slice_num(GPIO_SERVO);
    channel_SERVO = pwm_gpio_to_channel(GPIO_SERVO);

    wrap_DC1 = pwm_set_freq_duty_DC(slice_DC1, PWM_FREQ_MOT);
    wrap_DC2 = pwm_set_freq_duty_DC(slice_DC2, PWM_FREQ_MOT);
    wrap_SERVO = pwm_set_freq_duty_DC(slice_SERVO, PWM_FREQ_MOT);

    pwm_set_enabled(slice_DC1, true);
    pwm_set_enabled(slice_DC2, true);
    pwm_set_enabled(slice_SERVO, true);
}


static uint32 pwm_set_freq_duty_DC(uint8 slice, uint32 wanted_freq)
{
    uint32 prescaler = ((FCPU / wanted_freq / 4096) + (FCPU % (wanted_freq * 4096) != 0));
    uint32 wrap = ((FCPU * 16 / prescaler / 50) - 1);

    if (prescaler / 16 == 0)
    {
        prescaler = 16;
    }

    pwm_set_clkdiv_int_frac(slice, prescaler/16, prescaler & 0xF);
    pwm_set_wrap(slice, wrap);

    return wrap;
}


void Pwm_set_DC1_DutyCycle(uint8 dutycycle)
{
    pwm_set_chan_level(slice_DC1, channel_DC1, wrap_DC1 * dutycycle / 100);
}

void Pwm_set_DC2_DutyCycle(uint8 dutycycle)
{
    pwm_set_chan_level(slice_DC2, channel_DC2, wrap_DC2 * dutycycle / 100);
}

void Pwm_set_SERVO_DutyCycle(float dutycycle)
{
    pwm_set_chan_level(slice_SERVO, channel_SERVO, wrap_SERVO * dutycycle / 100);
}