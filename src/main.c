/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/10 16:11:20 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* System headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
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

	struct timeval 	start_time;
	// struct timeval 	current_time;
	t_milliseconds	start_time_milliseconds;
	// t_milliseconds	current_time_milliseconds;


	gettimeofday(&start_time, NULL);
	start_time_milliseconds = timeval_to_milliseconds(start_time);

	size_t	times_ate = 0;

	while (1)
	{
		if (philo.philo_id == 0)
		{
			// Pick up the right fork
			pthread_mutex_lock(philo.right_fork);
			printf("timestap: %-6lu ms --> %lu picked up right fork (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.right_fork);
			
			// Pick up the left fork
			pthread_mutex_lock(philo.left_fork);
			printf("timestap: %-6lu ms --> %lu picked up left fork  (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.left_fork);
		}
		else
		{
			// Pick up the left fork
			pthread_mutex_lock(philo.left_fork);
			printf("timestap: %-6lu ms --> %lu picked up left fork  (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.left_fork);

			// Pick up the right fork
			pthread_mutex_lock(philo.right_fork);
			printf("timestap: %-6lu ms --> %lu picked up right fork (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.right_fork);
		}

		// Set timestamp that philosopher has started eaten
		pthread_mutex_lock(philo.mutex_last_meal);
		*philo.timestamp_last_meal = get_current_timestamp_in_ms(start_time_milliseconds);
		pthread_mutex_unlock(philo.mutex_last_meal);

		// Now we can eat
		printf("timestap: %-6lu ms --> %lu is eating\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id);
		sleep_milliseconds(philo.input_data->time_to_eat);


		// // Release the left fork
		// printf("timestap: %-6lu ms --> %lu released left fork  (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.left_fork);
		pthread_mutex_unlock(philo.left_fork);

		
		// // Release the right fork
		// printf("timestap: %-6lu ms --> %lu released right fork (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.right_fork);
		pthread_mutex_unlock(philo.right_fork);

		times_ate++;
		// printf("Ate %lu times\n", times_ate);
		if (philo.input_data->number_of_times_to_eat > 0 && times_ate == philo.input_data->number_of_times_to_eat) 
		{
			return 0;
		}

		// Now we can sleep
		printf("timestap: %-6lu ms --> %lu is sleeping\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id);
		sleep_milliseconds(philo.input_data->time_to_sleep);

		// Now we can think
		printf("timestap: %-6lu ms --> %lu is thinking\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id);

	}
	return (0);
}

/*
** This thread will monitor whether a philosopher died.
** arg is an array of t_philo_data.
*/
void	*monitor_philos(void *arg)
{

	t_philo_data	*philos = arg;
	size_t			time_to_die = philos[0].input_data->time_to_die;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	t_milliseconds start_time_milliseconds = timeval_to_milliseconds(start_time);

	while (1)
	{
		size_t	i = 0;
		while (i < philos[0].input_data->number_of_philo)
		{
			pthread_mutex_lock(philos[i].mutex_last_meal);
			t_milliseconds current_timestamp = get_current_timestamp_in_ms(start_time_milliseconds);
			// printf("philo %lu timestamp_last_meal = %lu\n", i, *philos[i].timestamp_last_meal);
			if (*philos[i].timestamp_last_meal + time_to_die < current_timestamp)
			{
				printf("timestap: %-6lu ms --> %lu died\n", current_timestamp, i);
				pthread_mutex_unlock(philos[i].mutex_last_meal);
				return (void *)2;
			}
			pthread_mutex_unlock(philos[i].mutex_last_meal);
			sleep_milliseconds(1);
		}
	}
}

int	main(int argc, char *argv[])
{
	// Make run gives:
	// number of philosophers 	= 4
	// time to die 				= 60
	// time to eat 				= 10
	// time to sleep 			= 20
	
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
		philos[i].timestamp_last_meal = ft_calloc(1, sizeof(unsigned long));
		*philos[i].timestamp_last_meal = 0;
		philos[i].mutex_last_meal = ft_calloc(1, sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i].mutex_last_meal, NULL);
		printf("%lu right_fork = %p -- left_fork = %p\n", i, philos[i].right_fork, philos[i].left_fork);
		// printf("philo_id = %lu\n", philos[i].philo_id);
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

	// Start monitoring thread
	pthread_t	monitor_thread;
	pthread_create(&monitor_thread, NULL, monitor_philos, philos);

	// Join the threads
	pthread_join(monitor_thread, NULL);

	i = 0;
	void *ret_val;
	while (i < input_data.number_of_philo)
	{
		pthread_join(threads[i], &ret_val);
		printf("thread %lu retval %lu\n", i, (size_t)ret_val);
		i++;
	}


	// Destroy mutexes
	destroy_mutexes(forks, input_data.number_of_philo);

	// Destroy last meal mutex

	// Free all data
	free(philos);
	free(forks);
	free(threads);

	return (0);
}