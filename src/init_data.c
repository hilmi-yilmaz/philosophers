/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 10:54:51 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 13:43:14 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_data.h"

static t_philo	*init_philo(size_t i)
{
	t_philo	*philo;

	philo = ft_calloc(1, sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = i + 1;
	philo->done_eating = false;
	if (pthread_mutex_init(&philo->mutex_done_eating, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (NULL);
	}
	philo->timestamp_last_meal = 0;
	if (pthread_mutex_init(&philo->mutex_timestamp_last_meal, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (NULL);
	}
	return (philo);
}

t_data	*init_data(t_shared_data *shared_data)
{
	size_t			i;
	t_data			*data;

	data = ft_calloc(shared_data->number_of_philo, sizeof(t_data));
	if (data == NULL)
		return (NULL);
	i = 0;
	while (i < shared_data->number_of_philo)
	{
		data[i].shared_data = shared_data;
		data[i].philo = init_philo(i);
		if (data[i].philo == NULL)
			return (NULL);
		i++;
	}
	return (data);
}
