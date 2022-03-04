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

void	suite_93_conv_f(t_suite *suite)
{
	SUITE_ADD_TEST(suite, simple_small_nbr);
	SUITE_ADD_TEST(suite, simple_negative_small_nbr);
	SUITE_ADD_TEST(suite, simple_large_nbr);
	SUITE_ADD_TEST(suite, simple_negative_large_nbr);
	SUITE_ADD_TEST(suite, zero_flag);
	SUITE_ADD_TEST(suite, plus_flag);
	SUITE_ADD_TEST(suite, space_flag);
}
