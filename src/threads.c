/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:35:37 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 16:17:26 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "threads.h"

pthread_t	*start_philo_threads(t_data *data)
{
	size_t		i;
	pthread_t	*threads;

	i = 0;
	threads = ft_calloc(data->input_data->number_of_philo, sizeof(pthread_t));
	if (threads == NULL)
		return (NULL);
	while (i < data->input_data->number_of_philo)
	{
		if (pthread_create(&threads[i], NULL, philo_routine, &data[i]) != 0)
		{
			printf("Error with pthread_create");
			return (NULL);
		}
		i++;
	}
	return (threads);
}

pthread_t	*start_monitoring_thread(t_data *data)
{
	// Start monitoring thread
	pthread_t	*thread;
	thread = ft_calloc(1, sizeof(*thread));
	if (thread == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, monitor_routine, data) != 0)
	{
		printf("Error with pthread_create");
		return (NULL);
	}
	return (thread);
}

void	join_threads(t_input_data input_data, pthread_t *philo_threads,
					pthread_t *monitor_thread)
{
	size_t i;

	i = 0;
	while (i < input_data.number_of_philo)
	{
		pthread_join(philo_threads[i], NULL);
		i++;
	}
	pthread_join(*monitor_thread, NULL);
}