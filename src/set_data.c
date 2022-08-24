/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:04:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 17:50:15 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set_data.h"

static bool	set_input_data(char *argv[], t_shared_data *shared_data)
{
	int	err;

	shared_data->number_of_philo = atoi_with_int_overflow_check(argv[0], &err);
	shared_data->time_to_die = atoi_with_int_overflow_check(argv[1], &err);
	shared_data->time_to_eat = atoi_with_int_overflow_check(argv[2], &err);
	shared_data->time_to_sleep = atoi_with_int_overflow_check(argv[3], &err);
	if (argv[4])
		shared_data->number_of_times_to_eat = atoi_with_int_overflow_check(argv[4], &err);
	else
		shared_data->number_of_times_to_eat = -1;
	shared_data->is_dead = false;
	shared_data->forks = create_mutexes(shared_data->number_of_philo);
	if (shared_data->forks == NULL)
		return (false);
	if (pthread_mutex_init(&shared_data->mutex_is_dead, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (false);
	}
	if (pthread_mutex_init(&shared_data->mutex_print, NULL))
	{
		printf("Error with pthread_mutex_init");
		return (false);
	}
	shared_data->simulation_start_time = get_current_timestamp_in_ms();
	return (true);
}

bool	validate_and_set_input_data(int argc, char *argv[], t_shared_data *shared_data)
{
	if (!validate_input(argc, argv + 1))
		return (false);
	ft_memset(shared_data, 0, sizeof(t_shared_data));
	if (!set_input_data(argv + 1, shared_data))
		return (false);
	return (true);
}