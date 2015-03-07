#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#include "led.h"

void led_setup(void)
{
	/* Enable GPIOD clock. */
	/* Manually: */
	// RCC_AHB1ENR |= RCC_AHB1ENR_IOPDEN;
	/* Using API functions: */
	rcc_periph_clock_enable(RCC_GPIOE);

	/* Set GPIO12 (in GPIO port D) to 'output push-pull'. */
	/* Manually: */
	// GPIOD_CRH = (GPIO_CNF_OUTPUT_PUSHPULL << (((8 - 8) * 4) + 2));
	// GPIOD_CRH |= (GPIO_MODE_OUTPUT_2_MHZ << ((8 - 8) * 4));
	/* Using API functions: */
	gpio_mode_setup(GPIOE, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO12);
}

void led_toggle() {
	gpio_toggle(GPIOE, GPIO12);	/* LED on/off */
}
