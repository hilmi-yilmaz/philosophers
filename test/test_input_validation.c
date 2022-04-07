/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_validation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 12:51:35 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 14:02:26 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unit-testing framework */
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

/* Source file to test */
#include "../philo/input_validation.h"

/* Test utils */
#include "test_utils.h"

/* Variables used in every test */
static char	**argv = NULL;

void	setup_suite(void)
{
}

void	teardown_suite(void)
{
	free_argv(argv);
}

TestSuite(InputValidation, .init = setup_suite, .fini = teardown_suite);

Test(InputValidation, CorrectInput)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "10", "20", "20", "20");
	cr_assert(validate_input(argc, argv));
}