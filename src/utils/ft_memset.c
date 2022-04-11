/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/11 12:17:29 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 12:17:39 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*(p + i) = c;
		i++;
	}
	return (s);
}