/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 10:54:51 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 17:22:03 by hyilmaz       ########   odam.nl         */
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

t_data	*init_data(t_input_data *input_data)
{
	size_t			i;
	t_data			*data;
	bool			*is_dead;
	pthread_mutex_t	*mutex_is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_print;
	t_milliseconds	*simulation_start_time;

	data = ft_calloc(input_data->number_of_philo, sizeof(t_data));
	if (data == NULL)
		return (NULL);

	is_dead = ft_calloc(1, sizeof(bool));
	if (is_dead == NULL)
		return (NULL);
	*is_dead = false;


	mutex_is_dead = ft_calloc(1, sizeof(pthread_mutex_t));
	if (mutex_is_dead == NULL)
		return (NULL);
	if (pthread_mutex_init(mutex_is_dead, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (NULL);
	}
	
	forks = create_mutexes(input_data->number_of_philo);
	if (forks == NULL)
		return (NULL);

	mutex_print = ft_calloc(1, sizeof(pthread_mutex_t));
	if (mutex_print == NULL)
		return (NULL);
	if (pthread_mutex_init(mutex_print, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (NULL);
	}

	simulation_start_time = ft_calloc(1, sizeof(t_milliseconds));
	if (simulation_start_time == NULL)
		return (NULL);
	*simulation_start_time = get_current_timestamp_in_ms();

	i = 0;
	while (i < input_data->number_of_philo)
	{
		data[i].input_data = input_data;
		data[i].simulation_start_time = simulation_start_time;
		data[i].is_dead = is_dead;
		data[i].mutex_is_dead = mutex_is_dead;
		data[i].forks = forks;
		data[i].mutex_print = mutex_print;
		data[i].philo = init_philo(i);
		if (data[i].philo == NULL)
			return (NULL);
		i++;
	}
	return (data);
}