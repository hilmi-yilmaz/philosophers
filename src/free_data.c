/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 12:18:54 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 12:18:59 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "free_data.h"

void	free_data(t_philo_data *philos, pthread_t *philo_threads, pthread_t *monitor_thread)
{
	// Destroy mutexes
	destroy_mutexes(philos->forks, philos->input_data->number_of_philo);

	// Destroy last meal mutex

	// Free all data
	free(philos);
	free(philos->forks);
	free(philo_threads);
	free(monitor_thread);
}