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

// bool	philo_is_dead(t_philo_data philo)
// {
// 	pthread_mutex_lock(philo.mutex_is_dead);
// 	if (*philo.is_dead)
// 	{
// 		pthread_mutex_unlock(philo.mutex_is_dead);
// 		return (true);
// 	}
// 	pthread_mutex_unlock(philo.mutex_is_dead);
// 	return (false);
// }

// void	set_philo_dead(t_philo_data philo)
// {
// 	pthread_mutex_lock(philo.mutex_is_dead);
// 	*philo.is_dead = true;
// 	pthread_mutex_unlock(philo.mutex_is_dead);	
// }

// void	print_status(t_philo_data philo, char *status)
// {
// 	t_milliseconds	current_time_ms;

// 	if (philo_is_dead(philo))
// 		return ;
// 	pthread_mutex_lock(philo.mutex_print);
// 	current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 	printf("timestamp: %-6lu ms --> %lu %s\n", current_time_ms, philo.philo_id, status);
// 	pthread_mutex_unlock(philo.mutex_print);
// }

// void	pick_up_forks(t_philo_data philo)
// {
// 	pthread_mutex_lock(philo.right_fork);
// 	print_status(philo, "has taken a fork");
// 	pthread_mutex_lock(philo.left_fork);
// 	print_status(philo, "has taken a fork");
// }

// void	set_start_eating_time(t_philo_data *philo)
// {
// 	pthread_mutex_lock(philo->mutex_timestamp_last_meal);
// 	*philo->timestamp_last_meal = get_current_timestamp_in_ms(philo->simulation_start_time);
// 	pthread_mutex_unlock(philo->mutex_timestamp_last_meal);
// }

// void	eat(t_philo_data *philo)
// {

// 	// Set the eat_times variable
// 	// philo->times_ate += 1;

// 	print_status(*philo, "is eating");
// 	sleep_milliseconds_new(philo->input_data->time_to_eat);
// }

// void	release_forks(t_philo_data philo)
// {
// 	pthread_mutex_unlock(philo.left_fork);
// 	pthread_mutex_unlock(philo.right_fork);
// }

// void	_sleep(t_philo_data philo)
// {
// 	print_status(philo, "is sleeping");
// 	sleep_milliseconds_new(philo.input_data->time_to_sleep);
// }

// void	think(t_philo_data philo)
// {
// 	print_status(philo, "is thinking");
// }

// void	*philo_thread_routine(void *arg)
// {
// 	t_philo_data	philo = *(t_philo_data *)arg;

// 	if (philo.philo_id % 2 != 0)
// 		sleep_milliseconds_new(1);
// 	while (!*philo.is_dead)
// 	{
// 		pick_up_forks(philo);
// 		set_start_eating_time(&philo);
// 		eat(&philo);
// 		release_forks(philo);
// 		*philo.times_ate += 1;

// 		// Check if philosopher is done eating
// 		if (philo.input_data->number_of_times_to_eat != -1)
// 		{
// 			pthread_mutex_lock(philo.mutex_times_ate);
// 			if (*philo.times_ate == philo.input_data->number_of_times_to_eat)
// 			{
// 				t_milliseconds	current_time_ms;
// 				current_time_ms = get_current_timestamp_in_ms(philo.simulation_start_time);
// 				printf("timestamp: %-6lu ms --> %lu done eating, ate %d times\n", current_time_ms, philo.philo_id, *philo.times_ate);
// 				pthread_mutex_unlock(philo.mutex_times_ate);
// 				return (void *)(0);
// 			}
// 			pthread_mutex_unlock(philo.mutex_times_ate);
// 		}


// 		_sleep(philo);
// 		think(philo);
// 	}
// 	return (0);
// }

/*
** This thread will monitor whether a philosopher died.
** arg is an array of t_philo_data.
*/
// void	*monitor_thread_routine(void *arg)
// {
// 	size_t			i;
// 	t_philo_data	*philos = arg;
// 	t_milliseconds	current_timestamp;
// 	size_t			time_to_die = philos[0].input_data->time_to_die;
// 	size_t			times_ate_counter;

// 	while (1)
// 	{
// 		i = 0;
// 		times_ate_counter = 0;
// 		while (i < philos[0].input_data->number_of_philo)
// 		{

// 			// If philosopher is done eating, increment times_ate_counter
// 			if (philos[0].input_data->number_of_times_to_eat != -1)
// 			{
// 				pthread_mutex_lock(philos[i].mutex_times_ate);
// 				// printf("philos[%lu].times_ate = %d\n", i, *philos[i].times_ate);
// 				if (*philos[i].times_ate == philos[0].input_data->number_of_times_to_eat)
// 					times_ate_counter++;
// 				pthread_mutex_unlock(philos[i].mutex_times_ate);
// 			}

// 			// Check whether a philosopher died
// 			pthread_mutex_lock(philos[i].mutex_timestamp_last_meal);
// 			current_timestamp = get_current_timestamp_in_ms(philos[i].simulation_start_time);
// 			if (*philos[i].timestamp_last_meal + time_to_die < current_timestamp)
// 			{
// 				print_status(philos[i], "died");
// 				set_philo_dead(philos[i]);
// 				pthread_mutex_unlock(philos[i].mutex_timestamp_last_meal);
// 				return (void *)0;
// 			}
// 			pthread_mutex_unlock(philos[i].mutex_timestamp_last_meal);

// 			i++;
// 		}
// 		// Check whether all philosophers finished eating (number_of_times_each_philosopher_must_eat argument supplied to program)
// 		printf("times_ate_counter = %lu\n", times_ate_counter);
// 		if (times_ate_counter == philos[0].input_data->number_of_philo)
// 			return (0);
// 		sleep_milliseconds_new(1);
// 	}
// 	return (0);
// }

// pthread_t	*start_philo_threads(t_philo_data *philos)
// {

// 	size_t			i;
// 	pthread_t		*threads;
// 	t_milliseconds	simulation_start_time;
	
// 	i = 0;
// 	threads = ft_calloc(philos->input_data->number_of_philo, sizeof(*threads));
// 	if (threads == NULL)
// 		return (NULL);
// 	simulation_start_time = get_current_timestamp_in_ms_new();
// 	while (i < philos->input_data->number_of_philo)
// 	{
// 		philos[i].simulation_start_time = simulation_start_time;
// 		if (pthread_create(&threads[i], NULL, philo_thread_routine, &philos[i]) != 0)
// 		{
// 			printf("Error with pthread_create");
// 			return (NULL);
// 		}
// 		pthread_detach(threads[i]);
// 		i++;
// 	}
// 	return threads;
// }
void print_status(t_data *data, char *status, char *colorcode);

bool	is_dead(t_data *data)
{
	bool	is_dead;

	pthread_mutex_lock(data->mutex_is_dead);
	is_dead = *data->is_dead;
	// if (is_dead == true)
	// {
	// 	printf("someone dies!!! so philo %lu should stop printing\n", data->philo->id);
	// }
	pthread_mutex_unlock(data->mutex_is_dead);
	return (is_dead);
}

void print_status(t_data *data, char *status, char *colorcode)
{
	t_milliseconds	current_time_ms;

	// if (is_dead(data))
	// 	return ;
	pthread_mutex_lock(data->mutex_print);
	if (is_dead(data))
	{
		pthread_mutex_unlock(data->mutex_print);
		return ;
	}
	current_time_ms = get_simulation_timestamp_in_ms(*data->simulation_start_time);

	// Print with color
	// printf("%s%-6lu %lu %s%s\n", colorcode, current_time_ms, data->philo->id, status, RESET);
	
	// Print wihtout color
	(void)colorcode;
	printf("%-6lu %lu %s\n", current_time_ms, data->philo->id, status);

	pthread_mutex_unlock(data->mutex_print);
}

void	set_dead(t_data *data)
{
	pthread_mutex_lock(data->mutex_is_dead);
	*data->is_dead = true;
	pthread_mutex_unlock(data->mutex_is_dead);

}

void	pick_up_forks(t_data *data)
{
	pthread_mutex_lock(&data->forks[RIGHT_FORK(data->philo->id - 1, data->input_data->number_of_philo)]);
	print_status(data, "has taken a fork", BLUE);
	pthread_mutex_lock(&data->forks[LEFT_FORK(data->philo->id - 1)]);
	print_status(data, "has taken a fork", BLUE);


	// if (data->philo->id % 2 == 0)
	// {
	// 	pthread_mutex_lock(&data->forks[RIGHT_FORK(data->philo->id - 1, data->input_data->number_of_philo)]);
	// 	print_status(data, "has taken a fork", BLUE);
	// 	pthread_mutex_lock(&data->forks[LEFT_FORK(data->philo->id - 1)]);
	// 	print_status(data, "has taken a fork", BLUE);
	// 	return ;
	// }
	// pthread_mutex_lock(&data->forks[LEFT_FORK(data->philo->id - 1)]);
	// print_status(data, "has taken a fork", BLUE);
	// pthread_mutex_lock(&data->forks[RIGHT_FORK(data->philo->id - 1, data->input_data->number_of_philo)]);
	// print_status(data, "has taken a fork", BLUE);

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
	size_t	i;

	data = arg;
	times_ate = 0;
	i = 0;
	// if (data->philo->id % 2 == 0)
	// 	sleep_milliseconds(1);
	while (!is_dead(data))
	{
		if (!(i == 0 && data->philo->id % 2 == 0))
		{
			pick_up_forks(data);
			set_start_eating_time(data);
			eat(data);
			release_forks(data);
			times_ate++;
		}

		// pick_up_forks(data);
		// set_start_eating_time(data);
		// eat(data);
		// release_forks(data);
		// times_ate++;
		if (data->input_data->number_of_times_to_eat != -1 &&\
			times_ate == data->input_data->number_of_times_to_eat)
		{
			// print_status(data, "done eating");
			set_done_eating(data);
			return (NULL);
		}
		_sleep(data);
		think(data);
		i++;
	}
	return (NULL); 
}

void	*monitor_routine(void *arg)
{
	size_t			i;
	t_data			*data = arg;
	t_milliseconds	current_timestamp;
	size_t			time_to_die = data->input_data->time_to_die;
	size_t			total_finished_eating;

	while (1)
	{
		// printf("Monitoring\n");
		// Check if all philosophers are done eating
		i = 0;
		total_finished_eating = 0;
		while (i < data->input_data->number_of_philo)
		{
			pthread_mutex_lock(&data[i].philo->mutex_done_eating);
			if (data[i].philo->done_eating == true)
				total_finished_eating += 1;
			pthread_mutex_unlock(&data[i].philo->mutex_done_eating);
			i++;
		}
		if (total_finished_eating == data->input_data->number_of_philo)
		{
			// print_status(data, "all philo's done eating\n");
			return (NULL);
		}

		// Check if philosopher i died
		i = 0;
		while (i < data->input_data->number_of_philo)
		{
			pthread_mutex_lock(&data[i].philo->mutex_timestamp_last_meal);
			current_timestamp = get_simulation_timestamp_in_ms(*data->simulation_start_time);
			if (data[i].philo->timestamp_last_meal + time_to_die < current_timestamp)
			{
				print_status(&data[i], "died", RED);
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

pthread_t	*start_philo_threads(t_data *data)
{
	size_t		i;
	pthread_t	*threads;

	i = 0;
	threads = ft_calloc(data->input_data->number_of_philo + 1, sizeof(pthread_t));
	if (threads == NULL)
		return (NULL);
	while (i < data->input_data->number_of_philo)
	{
		if (pthread_create(&threads[i], NULL, philo_routine, &data[i]) != 0)
		{
			printf("Error with pthread_create");
			return (NULL);
		}
		i++;
	}
	return (threads);
}

pthread_t	*start_monitoring_thread(t_data *data)
{
	// Start monitoring thread
	pthread_t	*thread;
	thread = ft_calloc(1, sizeof(*thread));
	if (thread == NULL)
		return (NULL);
	if (pthread_create(thread, NULL, monitor_routine, data) != 0)
	{
		printf("Error with pthread_create");
		return (NULL);
	}
	return (thread);
}