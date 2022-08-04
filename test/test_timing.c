/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_timing.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 17:14:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 17:28:50 by hyilmaz       ########   odam.nl         */
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

void	setup_suite_set_timing(void)
{
}

void	teardown_suite_set_timing(void)
{
}

TestSuite(SleepMilliseconds, .init = setup_suite_set_timing, .fini = teardown_suite_set_timing);

Test(SleepMilliseconds, Simple)
{
	struct timeval start_time;
	struct timeval end_time;


	gettimeofday(&start_time, NULL);
	sleep_milliseconds(10);
	gettimeofday(&end_time, NULL);

	printf("actually slept %d microseconds\n", end_time.tv_usec - start_time.tv_usec);
	
}