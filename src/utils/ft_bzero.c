/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:19:15 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 12:19:22 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s;

	i = 0;
	ptr_s = s;
	while (i < n)
	{
		*(ptr_s + i) = '\0';
		i++;
	}
}