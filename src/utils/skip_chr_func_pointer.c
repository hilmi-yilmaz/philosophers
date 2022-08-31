/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_chr_func_pointer.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:41:48 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 14:55:49 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	skip_chr_func_pointer(char *str, int (func)(int))
{
	int	i;

	i = 0;
	while (func(str[i]) != 0)
		i++;
	return (i);
}
