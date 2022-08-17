/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_timing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 17:14:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/10 15:15:34 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unit-testing framework */
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

/* System headers */


/* Source file to test */
#include "../src/timing.h"

/* Test utils */
#include "test_utils.h"

/* Macros */
#define RUN_EACH_TEST_X_TIMES 1
#define MILLISECONDS_INTERVAL 5

void	setup_suite_set_timing(void)
{
}

void	teardown_suite_set_timing(void)
{
}

TestSuite(SleepMilliseconds, .init = setup_suite_set_timing, .fini = teardown_suite_set_timing);

// Test(SleepMilliseconds, SleepTenMillisecond)
// {
// 	struct 			timeval start_time;
// 	struct			timeval end_time;
// 	t_milliseconds	milliseconds;

// 	milliseconds = 10;

// 	size_t	i = 0;
// 	while (i < RUN_EACH_TEST_X_TIMES)
// 	{

// 		gettimeofday(&start_time, NULL);
// 		sleep_milliseconds(milliseconds);
// 		gettimeofday(&end_time, NULL);
		
// 		// Calculate the actual milliseconds slept
// 		t_milliseconds	actual_milliseconds_slept = timeval_to_milliseconds(end_time) - timeval_to_milliseconds(start_time);
// 		printf("Expected %lu, actually slept %lu milliseconds\n", milliseconds, actual_milliseconds_slept);

// 		cr_assert(ge(int, actual_milliseconds_slept, milliseconds));
// 		cr_assert(le(int, actual_milliseconds_slept - milliseconds, 10));
// 		i++;
// 	}
// }

Test(SleepMilliseconds, SleepMillisecondsRangeTest)
{
	struct 			timeval start_time;
	struct			timeval end_time;
	t_milliseconds	milliseconds;
	t_milliseconds	total_milliseconds;
	size_t			i;

	milliseconds = 1;
	total_milliseconds = 100;
	while (milliseconds < total_milliseconds)
	{
		i = 0;
		while (i < RUN_EACH_TEST_X_TIMES)
		{

			gettimeofday(&start_time, NULL);
			sleep_milliseconds_new(milliseconds);
			gettimeofday(&end_time, NULL);
			
			// Calculate the actual milliseconds slept
			t_milliseconds	actual_milliseconds_slept = timeval_to_milliseconds(end_time) - timeval_to_milliseconds(start_time);
			printf("Expected %lu, actually slept %lu milliseconds\n", milliseconds, actual_milliseconds_slept);

			cr_assert(ge(int, actual_milliseconds_slept, milliseconds));
			cr_assert(le(int, actual_milliseconds_slept - milliseconds, 10));
			i++;
		}
		milliseconds += MILLISECONDS_INTERVAL;
	}
}