/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 13:38:00 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* System headers */
#include <stdio.h>
#include <pthread.h>

/* User defined headers */
#include "set_data.h"
#include "init_data.h"
#include "threads.h"
#include "free_data.h"

int	main(int argc, char *argv[])
{
	t_shared_data	shared_data;
	t_data			*data;
	pthread_t		*philo_threads;
	pthread_t		*monitor_thread;

	if (validate_and_set_input_data(argc, argv, &shared_data) == false)
		return (-1);
	data = init_data(&shared_data);
	if (data == NULL)
		return (-1);
	philo_threads = start_philo_threads(data);
	if (philo_threads == NULL)
		return (-1);
	monitor_thread = start_monitoring_thread(data);
	if (monitor_thread == NULL)
		return (-1);
	if (!join_threads(&shared_data, philo_threads, monitor_thread))
		return (-1);
	free_data(data, philo_threads, monitor_thread);
	return (0);
}
