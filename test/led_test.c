#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

typedef unsigned char uint8_t;

void rcc_periph_clock_enable(unsigned char i) {
}

void gpio_mode_setup(uint8_t port, uint8_t mode, uint8_t pullup, uint8_t pin) {
}

void gpio_toggle(uint8_t port, uint8_t pin) {
}

int main(void) {
    led_setup();

    return 0;
}
