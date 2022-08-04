/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 17:10:25 by hyilmaz       ########   odam.nl         */
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
#include "timing.h"



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

	t_philo_data	philo = *(t_philo_data *)arg;



	while (1)
	{
		if (philo.philo_id == 0)
		{
			// Pick up the right fork
			pthread_mutex_lock(philo.right_fork);
			printf("%lu picked up right fork\n", philo.philo_id);
			
			// Pick up the left fork
			pthread_mutex_lock(philo.left_fork);
			printf("%lu picked up left fork\n", philo.philo_id);
		}
		else
		{
			// Pick up the left fork
			pthread_mutex_lock(philo.left_fork);
			printf("%lu picked up left fork\n", philo.philo_id);

			// Pick up the right fork
			pthread_mutex_lock(philo.right_fork);
			printf("%lu picked up right fork\n", philo.philo_id);
		}

		// Now we can eat
		printf("%lu is eating\n", philo.philo_id);
		usleep(philo.input_data->time_to_eat * 1000);


		// Release the left fork
		pthread_mutex_unlock(philo.left_fork);
		printf("%lu released left fork\n", philo.philo_id);

		
		// Release the right fork
		pthread_mutex_unlock(philo.right_fork);
		printf("%lu released right fork\n",philo.philo_id);


		// Now we can sleep
		printf("%lu is sleeping\n", philo.philo_id);
		usleep(philo.input_data->time_to_sleep * 1000);


		// Now we can think
		printf("%lu is thinking\n", philo.philo_id);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	// Make run gives:
	// number of philosophers 	= 2
	// time to die 				= 40
	// time to eat 				= 10
	// time to sleep 			= 10
	
	t_input_data	input_data;
	
	// Validate input and save the data
	if (!validate_input(argc, argv + 1))
		return (1);
	ft_memset(&input_data, 0, sizeof(t_input_data));
	set_input_data(argv + 1, &input_data);
	
	// Create the forks and threads array
	pthread_mutex_t	*forks = create_mutexes(input_data.number_of_philo);

	// Data struct for each philo
	t_philo_data	*philos;
	philos = ft_calloc(input_data.number_of_philo, sizeof(*philos));

	size_t i = 0;
	while (i < input_data.number_of_philo)
	{
		philos[i].philo_id = i;
		philos[i].input_data = &input_data;
		philos[i].left_fork = &forks[i];
		philos[i].right_fork = &forks[(i + 1) % input_data.number_of_philo];
		printf("philo_id = %lu\n", philos[i].philo_id);
		i++;
	}

	// Create the threads
	i = 0;
	pthread_t	*threads;
	threads = ft_calloc(input_data.number_of_philo, sizeof(*threads));
	while (i < input_data.number_of_philo)
	{
		pthread_create(&threads[i], NULL, thread_func, &philos[i]);
		i++;
	}

	// Join the threads
	i = 0;
	while (i < input_data.number_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}

	// Destroy mutexes
	destroy_mutexes(forks, input_data.number_of_philo);

	return (0);
}