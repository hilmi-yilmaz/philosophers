/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/11 17:10:24 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

/* User defined headers */
#include "input_validation.h"
#include "set_data.h"
#include "data_structs.h"
#include "utils/utils.h"

pthread_mutex_t	*create_mutexes(size_t number_of_forks)
{
	size_t	i;
	pthread_mutex_t	*forks;
	
	i = 0;
	forks = ft_calloc(number_of_forks, sizeof(pthread_mutex_t));
	while (i < number_of_forks)
	{
		if (pthread_mutex_init(&forks[i], NULL))
		{
			perror("Error with pthread_mutex_init");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (forks);
}

void	destroy_mutexes(pthread_mutex_t *forks, size_t number_of_forks)
{
	size_t	i;

	i = 0;
	while (i < number_of_forks)
	{
		if (pthread_mutex_destroy(&forks[i]))
		{
			perror("Error with pthread_mutex_init");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	*thread_func(void *arg)
{
	pthread_mutex_t *forks = arg;

	pthread_mutex_lock(&forks[0]);
	write(1, "h", 1);
	write(1, "y", 1);
	write(1, "\n", 1);
	pthread_mutex_unlock(&forks[0]);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	
	if (!validate_input(argc, argv + 1))
		return (1);
	ft_memset(&data, 0, sizeof(t_data));
	set_data(argv + 1, &data);

	// Make run gives:
	// number of philosophers 	= 2
	// time to die 				= 40
	// time to eat 				= 10
	// time to sleep 			= 10
	
	// Create the forks and threads array
	pthread_mutex_t	*forks = create_mutexes(data.number_of_philo);

	// Create the threads
	size_t	i = 0;
	pthread_t	*threads;
	threads = ft_calloc(data.number_of_philo, sizeof(*threads));
	while (i < data.number_of_philo)
	{
		pthread_create(&threads[i], NULL, thread_func, forks);
		i++;
	}

	// Join the threads
	i = 0;
	while (i < data.number_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	// Destroy mutexes
	destroy_mutexes(forks, data.number_of_philo);

	return (0);
}