/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:42:49 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 14:04:08 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "input_validation.h"

bool	validate_input(int argc, char *argv[])
{
	size_t	i;
	int		converted_input;
	int		err;
	
	if (argc != 5 && argc != 6)
		return (false);
	i = 0;
	err = 0;
	while (argv[i] != NULL)
	{
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
