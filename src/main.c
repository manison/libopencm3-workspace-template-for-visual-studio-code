#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

static void gpio_setup(void)
{
    /* Enable GPIOE clock. */
    rcc_periph_clock_enable(RCC_GPIOA);

    /* Set GPIO12 (in GPIO port E) to 'output push-pull'. */
    gpio_mode_setup(GPIOA, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO0);
}

int main(void)
{
    int i;

    gpio_setup();

    /* Blink the LED (PC8) on the board. */
    while (1)
    {
        /* Using API function gpio_toggle(): */
        gpio_toggle(GPIOA, GPIO0);    /* LED on/off */
        for (i = 0; i < 2000000; i++) /* Wait a bit. */
            __asm__("nop");
    }

    return 0;
}
