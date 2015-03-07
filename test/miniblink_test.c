#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

void led_setup(void)
{
	mock();
}

void led_toggle(void)
{
	mock();
}

static void test_led_called(void)
{
	will_return(led_setup, 0);
	will_return(led_toggle, 0);

	test_main();
}

int main(void)
{
	const UnitTest tests[] = {
		unit_test(test_led_called),
	};
	return run_tests(tests);
}
