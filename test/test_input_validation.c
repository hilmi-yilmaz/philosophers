/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_validation.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 12:51:35 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 16:58:23 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* Unit-testing framework */
#include <criterion/criterion.h>
#include <criterion/new/assert.h>

/* Source file to test */
#include "../src/input_validation.h"

/* Test utils */
#include "test_utils.h"

/* Variables used in every test */
static char	**argv = NULL;

void	setup_suite(void)
{
	argv = NULL;
}

void	teardown_suite(void)
{
	free_argv(argv);
}

TestSuite(InputValidation, .init = setup_suite, .fini = teardown_suite);

Test(InputValidation, CorrectInput0)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "10", "20", "20", "20");
	cr_assert(eq(int, validate_input(argc, argv), true));
}

Test(InputValidation, CorrectInput1)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "10", "20", "20", "020");
	cr_assert(eq(int, validate_input(argc, argv), true));
}

Test(InputValidation, NonNumericCharacter0)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "10a", "20", "20", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, NonNumericCharacter1)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "10", "2.0", "20", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, TooFewArguments)
{	
	int argc = 3;

	argv = create_argv(argc - 1, "10", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, TooManyArguments)
{	
	int argc = 7;

	argv = create_argv(argc - 1, "10", "20", "10", "299", "1234", "0");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, NegativeNumbers)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "-10", "20", "20", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, IntegerOverflow)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "99999991111111111111111111111111111111111111111111111111", "20", "20", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}

Test(InputValidation, EmptyString)
{	
	int argc = 5;

	argv = create_argv(argc - 1, "66", "20", "", "20");
	cr_assert(eq(int, validate_input(argc, argv), false));
}