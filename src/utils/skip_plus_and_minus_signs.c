/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_plus_and_minus_signs.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:45:05 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 14:55:53 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

/*
** Skips plus and minus signs.
** Returns the index of the first digit.
** If not a -, + or digit, err = 1.
*/

int	skip_plus_and_minus_signs(const char *num_str, int *minus, int *err)
{
	int	i;

	i = 0;
	while (num_str[i] != '\0')
	{
		if (num_str[i] == '-')
			*minus += 1;
		else if (ft_isdigit(num_str[i]) != 0)
		{
			*minus = *minus % 2;
			return (i);
		}
		else if (num_str[i] != '+')
		{
			*err = 1;
			return (-1);
		}
		i++;
	}
	return (-1);
}
