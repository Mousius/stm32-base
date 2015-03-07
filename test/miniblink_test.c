#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

typedef unsigned char uint8_t;

void led_setup() {
    mock();
}

void led_toggle() {
    mock();
}

static void test_led_called() {
    will_return(led_setup, 0);
    will_return(led_toggle, 0);

    test_main();
}

int main(void) {
    const UnitTest tests[] = {
        unit_test(test_led_called),
    };
    return run_tests(tests);
}
