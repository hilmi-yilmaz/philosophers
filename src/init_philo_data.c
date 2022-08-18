/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo_data.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 10:54:51 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 16:30:27 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "init_philo_data.h"


static bool	set_philo_data(t_philo_data *philo, pthread_mutex_t *forks, t_input_data *input_data, size_t i)
{
	philo->philo_id = i + 1;
	philo->input_data = input_data;
	// philo->is_dead = ft_calloc(1, sizeof(bool));
	// if (philo->is_dead == NULL)
	// 	return (false);
	// *philo->is_dead = false;
	// pthread_mutex_init(philo->is_dead, NULL);
	philo->forks = forks;
	philo->left_fork = &forks[i];
	philo->right_fork = &forks[(i + 1) % input_data->number_of_philo];
	philo->timestamp_last_meal = ft_calloc(1, sizeof(t_milliseconds));
	if (philo->timestamp_last_meal == NULL)
		return (false);
	*philo->timestamp_last_meal = 0;
	philo->mutex_timestamp_last_meal = ft_calloc(1, sizeof(pthread_mutex_t));
	if (philo->mutex_timestamp_last_meal == NULL)
		return (false);
	pthread_mutex_init(philo->mutex_timestamp_last_meal, NULL);
	philo->mutex_print = ft_calloc(1, sizeof(pthread_mutex_t));
	if (philo->mutex_print == NULL)
		return (false);
	pthread_mutex_init(philo->mutex_print, NULL);
	// printf("%lu right_fork = %p -- left_fork = %p\n", i, philos[i].right_fork, philos[i].left_fork);
	return (true);
}

t_philo_data	*init_philo_data(t_input_data *input_data)
{
	pthread_mutex_t	*forks;
	t_philo_data	*philos;
	size_t			i;
	bool			*is_dead;
	pthread_mutex_t	*mutex_is_dead;

	forks = create_mutexes(input_data->number_of_philo);
	if (forks == NULL)
		return (NULL);
	philos = ft_calloc(input_data->number_of_philo, sizeof(*philos));
	if (philos == NULL)
		return (NULL);


	is_dead = ft_calloc(1, sizeof(bool));
	if (is_dead == NULL)
		return (false);
	*is_dead = false;

	mutex_is_dead = ft_calloc(1, sizeof(pthread_mutex_t));
	if (mutex_is_dead == NULL)
		return (false);
	pthread_mutex_init(mutex_is_dead, NULL);


	i = 0;
	while (i < input_data->number_of_philo)
	{
		philos[i].is_dead = is_dead;
		philos[i].mutex_is_dead = mutex_is_dead;
		if (set_philo_data(&philos[i], forks, input_data, i) == false)
			return (NULL);
		i++;
	}
	return (philos);
}