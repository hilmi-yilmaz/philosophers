/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:35:37 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/25 17:09:41 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

pthread_t	*start_philo_threads(t_data *data)
{
	size_t		i;
	pthread_t	*threads;

	i = 0;
	threads = ft_calloc(data->shared_data->number_of_philo, sizeof(pthread_t));
	if (threads == NULL)
		return (NULL);
	data->shared_data->simulation_start_time = get_current_timestamp_in_ms();
	while (i < data->shared_data->number_of_philo)
	{
		if (pthread_create(&threads[i], NULL, philo_routine, &data[i]) != 0)
		{
			printf("Error with pthread_create\n");
			return (NULL);
		}
		i++;
	}
	return (threads);
}

pthread_t	*start_monitoring_thread(t_data *data)
{
	pthread_t	*thread;
	
	thread = ft_calloc(1, sizeof(*thread));
	if (thread == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, monitor_routine, data) != 0)
	{
		printf("Error with pthread_create\n");
		return (NULL);
	}
	return (thread);
}

bool	join_threads(t_shared_data shared_data, pthread_t *philo_threads,
					pthread_t *monitor_thread)
{
	size_t i;

	i = 0;
	while (i < shared_data.number_of_philo)
	{
		if (pthread_join(philo_threads[i], NULL) != 0)
		{
			printf("Error with pthread_join\n");
			return (false);
		}
		i++;
	}
	if (pthread_join(*monitor_thread, NULL) != 0)
	{
		printf("Error with pthread_join\n");
		return (false);
	}
	return (true);
}