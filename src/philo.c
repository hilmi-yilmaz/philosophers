/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:26:24 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 15:45:36 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_dead(t_data *data)
{
	bool	is_dead;

	pthread_mutex_lock(data->mutex_is_dead);
	is_dead = *data->is_dead;
	pthread_mutex_unlock(data->mutex_is_dead);
	return (is_dead);
}

void print_status(t_data *data, char *status, char *colorcode)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(data->mutex_print);
	if (is_dead(data))
	{
		pthread_mutex_unlock(data->mutex_print);
		return ;
	}
	current_time_ms = get_simulation_timestamp_in_ms(*data->simulation_start_time);

	// Print with color
	printf("%s%-6lu %lu %s%s\n", colorcode, current_time_ms, data->philo->id, status, RESET);
	
	// Print wihtout color
	// (void)colorcode;
	// printf("%-6lu %lu %s\n", current_time_ms, data->philo->id, status);

	pthread_mutex_unlock(data->mutex_print);
}

void	pick_up_forks(t_data *data)
{
	pthread_mutex_lock(&data->forks[RIGHT_FORK(data->philo->id - 1, data->input_data->number_of_philo)]);
	print_status(data, "has taken a fork", BLUE);
	pthread_mutex_lock(&data->forks[LEFT_FORK(data->philo->id - 1)]);
	print_status(data, "has taken a fork", BLUE);
}

void	set_start_eating_time(t_data *data)
{
	pthread_mutex_lock(&data->philo->mutex_timestamp_last_meal);
	data->philo->timestamp_last_meal = get_simulation_timestamp_in_ms(*data->simulation_start_time);
	pthread_mutex_unlock(&data->philo->mutex_timestamp_last_meal);
}

void	set_done_eating(t_data *data)
{
	pthread_mutex_lock(&data->philo->mutex_done_eating);
	data->philo->done_eating = true;
	pthread_mutex_unlock(&data->philo->mutex_done_eating);
}

void	eat(t_data *data)
{
	print_status(data, "is eating", GREEN);
	sleep_milliseconds(data->input_data->time_to_eat);
}

void	release_forks(t_data *data)
{
	pthread_mutex_unlock(&data->forks[RIGHT_FORK(data->philo->id - 1, data->input_data->number_of_philo)]);
	pthread_mutex_unlock(&data->forks[LEFT_FORK(data->philo->id - 1)]);
}

void	_sleep(t_data *data)
{
	print_status(data, "is sleeping", CYAN);
	sleep_milliseconds(data->input_data->time_to_sleep);
}

void	think(t_data *data)
{
	print_status(data, "is thinking", PURPLE);
}


void	*philo_routine(void *arg)
{
	t_data	*data;
	int		times_ate;

	data = arg;
	times_ate = 0;
	if (data->philo->id % 2 == 0)
	{
		_sleep(data);
		think(data);
	}
	while (!is_dead(data))
	{
		pick_up_forks(data);
		set_start_eating_time(data);
		eat(data);
		release_forks(data);
		times_ate++;
		if (data->input_data->number_of_times_to_eat != -1 &&\
			times_ate == data->input_data->number_of_times_to_eat)
		{
			set_done_eating(data);
			return (NULL);
		}
		_sleep(data);
		think(data);
	}
	return (NULL); 
}