/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 12:21:21 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* System headers */
#include <stdio.h>
#include <pthread.h>

/* User defined headers */
#include "set_data.h"
#include "init_philo_data.h"
#include "start_threads.h"
#include "free_data.h"

int	main(int argc, char *argv[])
{
	t_input_data	input_data;
	t_philo_data	*philos;
	pthread_t		*threads;
	pthread_t		*monitor_thread;
	
	if (validate_and_set_input_data(argc, argv, &input_data) == false)
		return (-1);
	philos = init_philo_data(&input_data);
	if (philos == NULL)
		return (-1);
	threads = start_philo_threads(philos);
	if (threads == NULL)
		return (-1);
	monitor_thread = start_monitoring_thread(philos);
	if (monitor_thread == NULL)
		return (-1);

	// Join the threads
	pthread_join(*monitor_thread, NULL);
	size_t i = 0;
	void *ret_val;
	while (i < input_data.number_of_philo)
	{
		pthread_join(threads[i], &ret_val);
		printf("thread %lu retval %lu\n", i, (size_t)ret_val);
		i++;
	}


	// // Destroy mutexes
	// destroy_mutexes(philos->forks, input_data.number_of_philo);

	// // Destroy last meal mutex

	// // Free all data
	// free(philos);
	// free(philos->forks);
	// free(threads);
	// free(monitor_thread);
	free_data(philos, threads, monitor_thread);

	return (0);
}