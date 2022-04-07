/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_chr.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 13:43:08 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 13:43:18 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	skip_chr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}