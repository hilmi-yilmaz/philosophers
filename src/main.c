/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/03 17:59:50 by hyilmaz       ########   odam.nl         */
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
#include "mutexes.h"
#include "data_structs.h"
#include "utils/utils.h"



// void	*thread_func(void *arg)
// {
// 	pthread_mutex_t *forks = arg;

// 	// (void)forks;
// 	pthread_mutex_lock(&forks[0]);
// 	write(1, "h", 1);
// 	write(1, "y", 1);
// 	write(1, "\n", 1);
// 	pthread_mutex_unlock(&forks[0]);
// 	return (0);
// }

void	*thread_func(void *arg)
{

	t_philo	philo = *(t_philo *)arg;
	const int left_fork_idx = philo.idx;
	const int right_fork_idx = (philo.idx + 1) % 3;	// 3 is number of philo


	while (1)
	{

		if (philo.idx == 2)
		{
			// Pick up the right fork
			pthread_mutex_lock(&philo.forks[right_fork_idx]);
			printf("philo %lu picked up right fork\n", philo.idx);
			
			// Pick up the left fork
			pthread_mutex_lock(&philo.forks[left_fork_idx]);
			printf("philo %lu picked up left fork\n", philo.idx);
		}
		else
		{
			// Pick up the left fork
			pthread_mutex_lock(&philo.forks[left_fork_idx]);
			printf("philo %lu picked up left fork\n", philo.idx);

			// Pick up the right fork
			pthread_mutex_lock(&philo.forks[right_fork_idx]);
			printf("philo %lu picked up right fork\n", philo.idx);
		}

		// Now we can eat
		sleep(5);
		printf("philo %lu finished eating \n", philo.idx);


		// Release the left fork
		pthread_mutex_unlock(&philo.forks[left_fork_idx]);
		printf("philo %lu released up left fork\n", philo.idx);

		
		// Release the right fork
		pthread_mutex_unlock(&philo.forks[right_fork_idx]);
		printf("philo %lu released up right fork\n", philo.idx);


		// Now we can sleep
		sleep(5);
		printf("philo %lu finished sleeping \n", philo.idx);


		// // Now we can think
		// sleep(10);


	}

	// while (1)
	// {
	// 	// pick up left fork
	// 	pthread_mutex_lock(philo->forks[philo->idx]);

	// 	// pick up right fork
	// 	// eat
	// 	// sleep
	// 	// thick
	// }
	return (0);
}

int	main(int argc, char *argv[])
{
	// Make run gives:
	// number of philosophers 	= 2
	// time to die 				= 40
	// time to eat 				= 10
	// time to sleep 			= 10
	
	t_data	data;
	t_philo	*philos;
	
	// Validate input and save the data
	if (!validate_input(argc, argv + 1))
		return (1);
	ft_memset(&data, 0, sizeof(t_data));
	set_data(argv + 1, &data);

	
	// Create the forks and threads array
	pthread_mutex_t	*forks = create_mutexes(data.number_of_philo);

	// Create the philo's: this is the argument passed to each thread.
	philos = ft_calloc(data.number_of_philo, sizeof(*philos));

	// Create the threads
	size_t	i = 0;
	pthread_t	*threads;
	threads = ft_calloc(data.number_of_philo, sizeof(*threads));
	while (i < data.number_of_philo)
	{
		philos[i].idx = i;
		philos[i].forks = forks;
		// pthread_create(&threads[i], NULL, thread_func, forks);
		pthread_create(&threads[i], NULL, thread_func, &philos[i]);

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