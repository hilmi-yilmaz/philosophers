/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 12:18:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/25 12:26:49 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free_data.h"

void	free_data(t_data *data, pthread_t *philo_threads, pthread_t *monitor_thread)
{
	size_t	i;

	// Destroy mutexes
	destroy_mutexes(data->shared_data->forks, data->shared_data->number_of_philo);
	pthread_mutex_destroy(&data->shared_data->mutex_print);
	pthread_mutex_destroy(&data->shared_data->mutex_is_dead);
	i = 0;
	while (i < data->shared_data->number_of_philo)
	{
		pthread_mutex_destroy(&data[i].philo->mutex_done_eating);
		pthread_mutex_destroy(&data[i].philo->mutex_timestamp_last_meal);
		free(data[i].philo);
		i++;
	}

	// Free all data
	free(data->shared_data->forks);
	free(data);
	free(philo_threads);
	free(monitor_thread);
}