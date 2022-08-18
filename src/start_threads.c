/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:35:37 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 16:30:51 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "start_threads.h"

// void	*philo_thread_routine(void *arg)
// {

// 	t_philo_data	philo = *(t_philo_data *)arg;

// 	// struct timeval 	start_time;
// 	// struct timeval 	current_time;
// 	// t_milliseconds	start_time_milliseconds;
// 	t_milliseconds	current_time_ms;


// 	// gettimeofday(&start_time, NULL);
// 	// start_time_milliseconds = timeval_to_milliseconds(start_time);

// 	size_t	times_ate = 0;

// 	if (philo.philo_id % 2 != 0) {
// 		sleep_milliseconds_new(1);
// 	}

// 	while (1)
// 	{

// 		pthread_mutex_lock(philo.right_fork);

// 		pthread_mutex_lock(philo.mutex_print);
// 		current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		printf("timestap: %-6lu ms --> %lu picked up right fork (%p)\n", current_time_ms, philo.philo_id, philo.right_fork);
// 		pthread_mutex_unlock(philo.mutex_print);
		

// 		// Pick up the left fork
// 		pthread_mutex_lock(philo.left_fork);

// 		pthread_mutex_lock(philo.mutex_print);
// 		current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		printf("timestap: %-6lu ms --> %lu picked up left fork  (%p)\n", current_time_ms, philo.philo_id, philo.left_fork);
// 		pthread_mutex_unlock(philo.mutex_print);

// 		// Set timestamp that philosopher has started eaten
// 		pthread_mutex_lock(philo.mutex_timestamp_last_meal);
// 		*philo.timestamp_last_meal = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		pthread_mutex_unlock(philo.mutex_timestamp_last_meal);

// 		// Now we can eat
// 		pthread_mutex_lock(philo.mutex_print);
// 		current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		printf("timestap: %-6lu ms --> %lu is eating\n", current_time_ms, philo.philo_id);
// 		pthread_mutex_unlock(philo.mutex_print);

// 		sleep_milliseconds(philo.input_data->time_to_eat);


// 		// // Release the left fork
// 		// printf("timestap: %-6lu ms --> %lu released left fork  (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.left_fork);
// 		pthread_mutex_unlock(philo.left_fork);

		
// 		// // Release the right fork
// 		// printf("timestap: %-6lu ms --> %lu released right fork (%p)\n", get_current_timestamp_in_ms(start_time_milliseconds), philo.philo_id, philo.right_fork);
// 		pthread_mutex_unlock(philo.right_fork);

// 		times_ate++;
// 		// printf("Ate %lu times\n", times_ate);
// 		if (philo.input_data->number_of_times_to_eat > 0 && times_ate == philo.input_data->number_of_times_to_eat) 
// 		{
// 			return 0;
// 		}

// 		// Now we can sleep
// 		pthread_mutex_lock(philo.mutex_print);
// 		current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		printf("timestap: %-6lu ms --> %lu is sleeping\n", current_time_ms, philo.philo_id);
// 		pthread_mutex_unlock(philo.mutex_print);

// 		sleep_milliseconds(philo.input_data->time_to_sleep);

// 		// Now we can think
// 		pthread_mutex_lock(philo.mutex_print);
// 		current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 		printf("timestap: %-6lu ms --> %lu is thinking\n", current_time_ms, philo.philo_id);
// 		pthread_mutex_unlock(philo.mutex_print);

// 	}
// 	return (0);
// }

void	pick_up_forks(t_philo_data philo)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(philo.right_fork);
	pthread_mutex_lock(philo.mutex_print);
	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
	printf("timestap: %-6lu ms --> %lu picked up right fork (%p)\n", current_time_ms, philo.philo_id, philo.right_fork);
	pthread_mutex_unlock(philo.mutex_print);
	
	// Pick up the left fork
	pthread_mutex_lock(philo.left_fork);
	pthread_mutex_lock(philo.mutex_print);
	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
	printf("timestap: %-6lu ms --> %lu picked up left fork  (%p)\n", current_time_ms, philo.philo_id, philo.left_fork);
	pthread_mutex_unlock(philo.mutex_print);
}

void	set_start_eating_time(t_philo_data *philo)
{
	pthread_mutex_lock(philo->mutex_timestamp_last_meal);
	*philo->timestamp_last_meal = get_current_timestamp_in_ms(philo->simulation_start_time);
	pthread_mutex_unlock(philo->mutex_timestamp_last_meal);
}

void	eat(t_philo_data philo)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(philo.mutex_print);
	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
	printf("timestap: %-6lu ms --> %lu is eating\n", current_time_ms, philo.philo_id);
	pthread_mutex_unlock(philo.mutex_print);

	sleep_milliseconds_new(philo.input_data->time_to_eat);
}

void	release_forks(t_philo_data philo)
{
	pthread_mutex_unlock(philo.left_fork);
	pthread_mutex_unlock(philo.right_fork);
}

void	_sleep(t_philo_data philo)
{
	t_milliseconds	current_time_ms;

	pthread_mutex_lock(philo.mutex_print);
	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
	printf("timestap: %-6lu ms --> %lu is sleeping\n", current_time_ms, philo.philo_id);
	pthread_mutex_unlock(philo.mutex_print);

	sleep_milliseconds_new(philo.input_data->time_to_sleep);
}

bool	think(t_philo_data philo)
{
	t_milliseconds	current_time_ms;

	// printf("philo_id = %lu -> %p\n", philo.philo_id, philo.mutex_is_dead);
	pthread_mutex_lock(philo.mutex_is_dead);
	if (philo.is_dead)
	{
		pthread_mutex_unlock(philo.mutex_is_dead);
		return (false);
	}
	pthread_mutex_unlock(philo.mutex_is_dead);


	pthread_mutex_lock(philo.mutex_print);
	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
	printf("timestap: %-6lu ms --> %lu is thinking\n", current_time_ms, philo.philo_id);
	pthread_mutex_unlock(philo.mutex_print);
	return (true);
}

void	*philo_thread_routine(void *arg)
{
	t_philo_data	philo = *(t_philo_data *)arg;
	size_t			times_ate;

	times_ate = 0;
	if (philo.philo_id % 2 != 0)
		sleep_milliseconds_new(1);
	while (1)
	{
		pick_up_forks(philo);
		set_start_eating_time(&philo);
		eat(philo);
		release_forks(philo);
		times_ate++;
		if (philo.input_data->number_of_times_to_eat > 0 && times_ate == philo.input_data->number_of_times_to_eat) 
			return (0);
		_sleep(philo);
		if (think(philo) == false)
		{
			// philo dead
			return (void *)(1);
		}
	}
	return (0);
}

/*
** This thread will monitor whether a philosopher died.
** arg is an array of t_philo_data.
*/
void	*monitor_thread_routine(void *arg)
{
	size_t			i;
	t_philo_data	*philos = arg;
	t_milliseconds	current_timestamp;
	size_t			time_to_die = philos[0].input_data->time_to_die;

	while (1)
	{
		i = 0;
		while (i < philos[0].input_data->number_of_philo)
		{
			pthread_mutex_lock(philos[i].mutex_timestamp_last_meal);
			current_timestamp = get_current_timestamp_in_ms(philos[0].simulation_start_time);
			if (*philos[i].timestamp_last_meal + time_to_die < current_timestamp)
			{

				// set is dead
				pthread_mutex_lock(philos[i].mutex_is_dead);
				*philos[i].is_dead = true;
				pthread_mutex_unlock(philos[i].mutex_is_dead);

				pthread_mutex_lock(philos[i].mutex_print);
				printf("timestap: %-6lu ms --> %lu died\n", current_timestamp, i);
				pthread_mutex_unlock(philos[i].mutex_print);

				pthread_mutex_unlock(philos[i].mutex_timestamp_last_meal);
				return (void *)0;
			}
			pthread_mutex_unlock(philos[i].mutex_timestamp_last_meal);
			sleep_milliseconds_new(1);
		}
	}
	return (0);
}

pthread_t	*start_philo_threads(t_philo_data *philos)
{

	size_t			i;
	pthread_t		*threads;
	t_milliseconds	simulation_start_time;
	
	i = 0;
	threads = ft_calloc(philos->input_data->number_of_philo, sizeof(*threads));
	if (threads == NULL)
		return (NULL);
	simulation_start_time = get_current_timestamp_in_ms_new();
	while (i < philos->input_data->number_of_philo)
	{
		philos[i].simulation_start_time = simulation_start_time;
		if (pthread_create(&threads[i], NULL, philo_thread_routine, &philos[i]) != 0)
		{
			printf("Error with pthread_create");
			return (NULL);
		}
		i++;
	}
	return threads;
}

pthread_t	*start_monitoring_thread(t_philo_data *philos)
{
	// Start monitoring thread
	pthread_t	*thread;
	thread = ft_calloc(1, sizeof(*thread));
	if (thread == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, monitor_thread_routine, philos) != 0)
	{
		printf("Error with pthread_create");
		return (NULL);
	}
	return (thread);
}