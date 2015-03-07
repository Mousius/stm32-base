#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "led.h"

void led_setup(void)
{
	/* Enable GPIOD clock.
	 * Manually:
	 * RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	 * Using API functions:
	 */
	rcc_periph_clock_enable(RCC_GPIOE);

	/*
	 * set gpio12 (in gpio port d) to 'output push-pull'.
	 * manually:
	 * gpiod_crh = (gpio_cnf_output_pushpull << (((8 - 8) * 4) + 2));
	 * gpiod_crh |= (gpio_mode_output_2_mhz << ((8 - 8) * 4));
	 * Using API functions:
	 */
	gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);
}

void led_toggle()
{
	/* LED on/off */
	gpio_toggle(GPIOE, GPIO12);
}
