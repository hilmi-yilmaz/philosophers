/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:42:49 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/03 16:23:27 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

static bool	only_numeric_characters(char *str_number)
{
	size_t	i;

	i = 0;
	while (str_number[i])
	{
		if (!ft_isdigit(str_number[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	validate_input(int argc, char *argv[])
{
	size_t	i;
	int		converted_input;
	int		err;
	
	if (argc != 5 && argc != 6)
	{
		printf("No inputs provided\n");
		return (false);
	}
	i = 0;
	err = 0;
	while (argv[i] != NULL)
	{
		if (argv[i][0] == '\0')
		{
			printf("No empty strings allowed\n");
			return (false);
		}
		if (!only_numeric_characters(argv[i]))
		{
			printf("Only numeric characters are accepted\n");
			return (false);
		}
		converted_input = atoi_with_int_overflow_check(argv[i], &err);
		if (err == 1)
		{
			printf("Error: over- or underflow in one of the input values\n");
			return (false);
		}
		if (converted_input < 0)
		{
			printf("Error: Negative number in one of the arguments");
			return (false);
		}
		i++;
	}
	return (true);
}
