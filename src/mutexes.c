/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutexes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 17:06:28 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 11:02:38 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mutexes.h"

pthread_mutex_t	*create_mutexes(size_t number_of_forks)
{
	size_t			i;
	pthread_mutex_t	*forks;
	
	i = 0;
	forks = ft_calloc(number_of_forks + 1, sizeof(pthread_mutex_t));
	if (forks == NULL)
		return (NULL);
	while (i < number_of_forks)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			destroy_mutexes(forks, i);
			printf("Error with pthread_mutex_init");
			return (NULL);
		}
		i++;
	}
	return (forks);
}

bool	destroy_mutexes(pthread_mutex_t *forks, size_t number_of_forks)
{
	size_t	i;

	i = 0;
	while (i < number_of_forks)
	{
		if (pthread_mutex_destroy(&forks[i]))
		{
			printf("Error with pthread_mutex_destroy");
			return (false);
		}
		i++;
	}
	return (true);
}