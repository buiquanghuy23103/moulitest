#include <project.h>
#include <limits.h>
#include <signal.h>

static void simple_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", 1.42, 1.42, 1.42l);
}

static void simple_negative_small_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", -1.42, -1.42, -1.42l);
}

static void simple_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", 1444565444646.6465424242242, 1444565444646.6465424242242, 1444565444646.6465424242242l);
}

static void simple_negative_large_nbr(t_test *test)
{
	// test->debug = 1;
	assert_printf("{%f}{%lf}{%Lf}", -1444565444646.6465424242242454654, -1444565444646.6465424242242454654, -1444565444646.6465424242242454654l);
}

static void zero_flag(t_test *test)
{
	assert_printf("%012f - %012lf - %012Lf\n", 1.42, 1.42, 1.42l);
}

static void plus_flag(t_test *test)
{
	assert_printf("%+06.0f - %+06.0lf - %+06.0Lf\n", 1.42, 1.42, 1.42l);
}

static void space_flag(t_test *test)
{
	assert_printf("% 06.0f - % 06.0lf - % 06.0Lf\n", 1.42, 1.42, 1.42l);
}

static void mix_flag(t_test *test)
{
	assert_printf("% f - % lf - % Lf\n", 1.42, 1.42, 1.42l);
	assert_printf("%+f - %+lf - %+Lf\n", 1.42, 1.42, 1.42l);
	assert_printf("% 0f - % 0lf - % 0Lf\n", 1.42, 1.42, 1.42l);
	assert_printf("%+0f - %+0lf - %+0Lf\n", 1.42, 1.42, 1.42l);
}

static void minus_zero(t_test *test)
{
	assert_printf("%Lf\n", -0.0L);
}

static void minus_zero_one(t_test *test)
{
	assert_printf("-0.1 == %f\n", -0.1);
}

static void default_precision(t_test *test)
{
	assert_printf("%f\n", 0.0000016);
	assert_printf("999.999999 -> %f", 999.999999);
}

static void precision_zero_flag_min_width(t_test *test)
{
	assert_printf("%012.8f", 42.4242);
}

static void zero_precision(t_test *test)
{
	assert_printf("%012.0f, %012.0lf, %012.0Lf", 42.4242, 42.4242, 42.4242L);
}

void	suite_93_conv_f(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_small_nbr);
	SUITE_ADD_TEST(suite, simple_negative_small_nbr);
	SUITE_ADD_TEST(suite, simple_large_nbr);
	SUITE_ADD_TEST(suite, simple_negative_large_nbr);
	SUITE_ADD_TEST(suite, zero_flag);
	SUITE_ADD_TEST(suite, plus_flag);
	SUITE_ADD_TEST(suite, space_flag);
	SUITE_ADD_TEST(suite, mix_flag);
	SUITE_ADD_TEST(suite, minus_zero_one);
	SUITE_ADD_TEST(suite, default_precision);
	SUITE_ADD_TEST(suite, precision_zero_flag_min_width);
	SUITE_ADD_TEST(suite, zero_precision);
	SUITE_ADD_TEST(suite, minus_zero);
}
