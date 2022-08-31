/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:38:35 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 16:58:29 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static void	set_dead(t_data *data, char *status, char *colorcode)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(&data->shared_data->mutex_print);
	current_time_ms = get_simulation_timestamp_in_ms(
			data->shared_data->simulation_start_time);
	printf("%s%-6lu %lu %s%s\n", colorcode, current_time_ms,
		data->philo->id, status, RESET);
	pthread_mutex_lock(&data->shared_data->mutex_is_dead);
	data->shared_data->is_dead = true;
	pthread_mutex_unlock(&data->shared_data->mutex_is_dead);
	pthread_mutex_unlock(&data->shared_data->mutex_print);
}

static bool	all_philos_finished_eating(t_data *data)
{
	size_t	i;
	size_t	total_finished_eating;

	i = 0;
	total_finished_eating = 0;
	while (i < data->shared_data->number_of_philo)
	{
		pthread_mutex_lock(&data[i].philo->mutex_done_eating);
		if (data[i].philo->done_eating == true)
			total_finished_eating += 1;
		pthread_mutex_unlock(&data[i].philo->mutex_done_eating);
		i++;
	}
	if (total_finished_eating == data->shared_data->number_of_philo)
		return (true);
	return (false);
}

static bool	a_philo_died(t_data *data)
{
	size_t			i;
	t_milliseconds	current_timestamp;
	size_t			time_to_die;

	i = 0;
	time_to_die = data->shared_data->time_to_die;
	while (i < data->shared_data->number_of_philo)
	{
		pthread_mutex_lock(&data[i].philo->mutex_timestamp_last_meal);
		current_timestamp = get_simulation_timestamp_in_ms(
				data->shared_data->simulation_start_time);
		if (data[i].philo->timestamp_last_meal + time_to_die < \
				current_timestamp)
		{
			set_dead(&data[i], "died", RED);
			pthread_mutex_unlock(&data[i].philo->mutex_timestamp_last_meal);
			return (true);
		}
		pthread_mutex_unlock(&data[i].philo->mutex_timestamp_last_meal);
		i++;
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = arg;
	while (1)
	{
		if (all_philos_finished_eating(data))
			return (NULL);
		if (a_philo_died(data))
			return (NULL);
		sleep_milliseconds(1);
	}
	return (NULL);
}
