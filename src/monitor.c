/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/24 15:38:35 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/25 12:23:23 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "monitor.h"

static void	set_dead(t_data *data)
{
	pthread_mutex_lock(&data->shared_data->mutex_is_dead);
	data->shared_data->is_dead = true;
	pthread_mutex_unlock(&data->shared_data->mutex_is_dead);
}

void	print_died(t_data *data, char *status, char *colorcode)
{
	t_milliseconds	current_time_ms;

	// if (is_dead(data))
	// 	return ;
	pthread_mutex_lock(&data->shared_data->mutex_print);
	current_time_ms = get_simulation_timestamp_in_ms(data->shared_data->simulation_start_time);

	// Print with color
	printf("%s%-6lu %lu %s%s\n", colorcode, current_time_ms, data->philo->id, status, RESET);
	
	// Print wihtout color
	// (void)colorcode;
	// printf("%-6lu %lu %s\n", current_time_ms, data->philo->id, status);
	pthread_mutex_unlock(&data->shared_data->mutex_print);
}

void	*monitor_routine(void *arg)
{
	size_t			i;
	t_data			*data = arg;
	t_milliseconds	current_timestamp;
	size_t			time_to_die = data->shared_data->time_to_die;
	size_t			total_finished_eating;

	while (1)
	{
		// printf("Monitoring\n");
		// Check if all philosophers are done eating
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
		{
			// print_status(data, "all philo's done eating\n");
			return (NULL);
		}

		// Check if philosopher i died
		i = 0;
		while (i < data->shared_data->number_of_philo)
		{
			pthread_mutex_lock(&data[i].philo->mutex_timestamp_last_meal);
			current_timestamp = get_simulation_timestamp_in_ms(data->shared_data->simulation_start_time);
			if (data[i].philo->timestamp_last_meal + time_to_die < current_timestamp)
			{
				print_died(&data[i], "died", RED);
				set_dead(data);
				pthread_mutex_unlock(&data[i].philo->mutex_timestamp_last_meal);
				return (NULL);
			}
			pthread_mutex_unlock(&data[i].philo->mutex_timestamp_last_meal);
			i++;
		}

		sleep_milliseconds(1);
	}
	return (0);
}