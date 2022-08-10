/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_add_timeval.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/10 11:12:34 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/10 11:48:13 by hyilmaz       ########   odam.nl         */
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

void	setup_suite_add_milliseconds_to_timeval(void)
{
}

void	teardown_suite_add_milliseconds_to_timeval(void)
{
}

TestSuite(AddMillisecondsToTimeval, .init = setup_suite_add_milliseconds_to_timeval, .fini = teardown_suite_add_milliseconds_to_timeval);


Test(AddMillisecondsToTimeval, AddOneSecond)
{
	struct timeval	start_time;
	struct timeval	end_time;
	useconds_t		milliseconds;

	start_time.tv_sec = 1000;	// seconds (long)
	start_time.tv_usec = 0;		// microseconds (int)
	milliseconds = 1000;		// milliseconds (int)

	// Add 1000 milliseconds (1 second) to 1000 seconds.
	add_milliseconds_to_timeval(&start_time, &end_time, milliseconds);

	// Check seconds
	cr_assert(eq(int, end_time.tv_sec, 1001));

	// Check microseconds
	cr_assert(eq(int, end_time.tv_usec, 0));
}

Test(AddMillisecondsToTimeval, AddHundredMilliseconds)
{
	struct timeval	start_time;
	struct timeval	end_time;
	useconds_t		milliseconds;

	start_time.tv_sec = 1000;	// seconds (long)
	start_time.tv_usec = 0;		// microseconds (int)
	milliseconds = 100;			// milliseconds (int)

	// Add 100 milliseconds (0.1 second) to 1000 seconds.
	add_milliseconds_to_timeval(&start_time, &end_time, milliseconds);

	// Check seconds
	cr_assert(eq(int, end_time.tv_sec, 1000));

	// Check microseconds
	cr_assert(eq(int, end_time.tv_usec, 100000));
}

Test(AddMillisecondsToTimeval, AddOneThousandHundredMilliseconds)
{
	struct timeval	start_time;
	struct timeval	end_time;
	useconds_t		milliseconds;

	start_time.tv_sec = 1000;	// seconds (long)
	start_time.tv_usec = 0;		// microseconds int)
	milliseconds = 1100;		// milliseconds (int)

	// Add 1100 milliseconds (1.1 second) to 1000 seconds.
	add_milliseconds_to_timeval(&start_time, &end_time, milliseconds);

	// Check seconds
	cr_assert(eq(int, end_time.tv_sec, 1001));

	// Check microseconds
	cr_assert(eq(int, end_time.tv_usec, 100000));
}

Test(AddMillisecondsToTimeval, AddTwentyTwoThousandAndTwoHundredTwentyTwoMilliseconds)
{
	struct timeval	start_time;
	struct timeval	end_time;
	useconds_t		milliseconds;

	start_time.tv_sec = 1000;	// seconds (long)
	start_time.tv_usec = 11;	// microseconds int)
	milliseconds = 22222;		// milliseconds (int)

	// Add 1100 milliseconds (22.222 second) to 1000 seconds.
	add_milliseconds_to_timeval(&start_time, &end_time, milliseconds);

	// Check seconds
	cr_assert(eq(int, end_time.tv_sec, 1022));

	// Check microseconds
	cr_assert(eq(int, end_time.tv_usec, 222011));
}