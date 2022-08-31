/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:26:24 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 14:37:36 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	only_one_philo(t_data *data)
{
	if (data->shared_data->number_of_philo == 1)
	{
		pthread_mutex_lock(&data->shared_data->mutex_print);
		printf("%s%-6d %lu %s%s\n", BLUE, 0, data->philo->id,
			"has taken a fork", RESET);
		pthread_mutex_unlock(&data->shared_data->mutex_print);
		return (true);
	}
	return (false);
}

void	*philo_routine(void *arg)
{
	t_data	*data;
	int		times_ate;

	data = arg;
	if (only_one_philo(data))
		return (NULL);
	times_ate = 0;
	if (data->philo->id % 2 == 0)
		sleep_and_think(data);
	while (!is_dead(data))
	{
		eat(data);
		times_ate++;
		if (data->shared_data->number_of_times_to_eat != -1 && \
			times_ate == data->shared_data->number_of_times_to_eat)
		{
			set_done_eating(data);
			return (NULL);
		}
		sleep_and_think(data);
	}
	return (NULL);
}
