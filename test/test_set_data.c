/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_set_data.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 11:54:00 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 12:08:10 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unit-testing framework */
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

/* System headers */
#include <string.h>

/* Source file to test */
#include "../src/set_data.h"

/* Test utils */
#include "test_utils.h"

/* Variables used in every test */
static char		**argv = NULL;
static t_data	data;

/* Helper functions */


void	setup_suite_set_data(void)
{
	argv = NULL;
	memset(&data, 0, sizeof(t_data));
}

void	teardown_suite_set_data(void)
{
	free_argv(argv);
}

TestSuite(SetData, .init = setup_suite_set_data, .fini = teardown_suite_set_data);

Test(SetData, FourArguments)
{
	int argc = 5;

	argv = create_argv(argc - 1, "10", "20", "30", "40");

	set_data(argv, &data);

	cr_assert(eq(int, data.number_of_philo, 10));
	cr_assert(eq(int, data.time_to_die, 20));
	cr_assert(eq(int, data.time_to_eat, 30));
	cr_assert(eq(int, data.time_to_sleep, 40));
	cr_assert(eq(int, data.number_of_times_to_eat, -1));
}

Test(SetData, FiveArguments)
{
	int argc = 6;

	argv = create_argv(argc - 1, "10", "20", "30", "40", "50");

	set_data(argv, &data);

	cr_assert(eq(int, data.number_of_philo, 10));
	cr_assert(eq(int, data.time_to_die, 20));
	cr_assert(eq(int, data.time_to_eat, 30));
	cr_assert(eq(int, data.time_to_sleep, 40));
	cr_assert(eq(int, data.number_of_times_to_eat, 50));
}