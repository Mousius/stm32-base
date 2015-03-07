#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

void rcc_periph_clock_enable(enum rcc_periph_clken i) {
    check_expected(i);
    mock();
}

void gpio_mode_setup(uint32_t port, uint8_t mode, uint8_t pullup, uint16_t pin) {
    check_expected(port);
    check_expected(mode);
    check_expected(pullup);
    check_expected(pin);
    mock();
}

void gpio_toggle(uint32_t port, uint16_t pin) {
    check_expected(port);
    check_expected(pin);
    mock();
}

static void test_led_setup() {
    expect_value(rcc_periph_clock_enable, i, RCC_GPIOD);
    will_return(rcc_periph_clock_enable, 0);

    expect_value(gpio_mode_setup, port, GPIOD);
    expect_value(gpio_mode_setup, mode, GPIO_MODE_OUTPUT);
    expect_value(gpio_mode_setup, pullup, GPIO_PUPD_NONE);
    expect_value(gpio_mode_setup, pin, GPIO12);
    will_return(gpio_mode_setup, 0);

    led_setup();
}

static void test_led_toggle() {
     expect_value(gpio_toggle, port, GPIOD);
     expect_value(gpio_toggle, pin, GPIO12);
     will_return(gpio_toggle, 0);

     led_toggle();
}

int main(void) {
    const UnitTest tests[] = {
        unit_test(test_led_setup),
        unit_test(test_led_toggle)
    };
    return run_tests(tests);
}
