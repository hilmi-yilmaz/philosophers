/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/31 14:05:34 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 15:35:45 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_data *data)
{
	bool	is_dead;

	pthread_mutex_lock(&data->shared_data->mutex_is_dead);
	is_dead = data->shared_data->is_dead;
	pthread_mutex_unlock(&data->shared_data->mutex_is_dead);
	return (is_dead);
}

void	print_status(t_data *data, char *status, char *colorcode)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(&data->shared_data->mutex_print);
	if (is_dead(data))
	{
		pthread_mutex_unlock(&data->shared_data->mutex_print);
		return ;
	}
	current_time_ms = get_simulation_timestamp_in_ms(
			data->shared_data->simulation_start_time);
	printf("%s%-6lu %lu %s%s\n", colorcode, current_time_ms, data->philo->id,
		status, RESET);
	pthread_mutex_unlock(&data->shared_data->mutex_print);
}

void	set_done_eating(t_data *data)
{
	pthread_mutex_lock(&data->philo->mutex_done_eating);
	data->philo->done_eating = true;
	pthread_mutex_unlock(&data->philo->mutex_done_eating);
}

void	eat(t_data *data)
{
	pthread_mutex_lock(&data->shared_data->forks[
		data->philo->id % data->shared_data->number_of_philo]);
	print_status(data, "has taken a fork", BLUE);
	pthread_mutex_lock(&data->shared_data->forks[data->philo->id - 1]);
	print_status(data, "has taken a fork", BLUE);
	pthread_mutex_lock(&data->philo->mutex_timestamp_last_meal);
	data->philo->timestamp_last_meal = get_simulation_timestamp_in_ms(
			data->shared_data->simulation_start_time);
	pthread_mutex_unlock(&data->philo->mutex_timestamp_last_meal);
	print_status(data, "is eating", GREEN);
	sleep_milliseconds(data->shared_data->time_to_eat);
	pthread_mutex_unlock(&data->shared_data->forks[
		data->philo->id % data->shared_data->number_of_philo]);
	pthread_mutex_unlock(&data->shared_data->forks[data->philo->id - 1]);
}

void	sleep_and_think(t_data *data)
{
	print_status(data, "is sleeping", CYAN);
	sleep_milliseconds(data->shared_data->time_to_sleep);
	print_status(data, "is thinking", PURPLE);
}
