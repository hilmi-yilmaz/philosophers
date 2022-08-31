/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/06 16:38:47 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/25 17:07:12 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


// gcc -Wall -Wextra -Werror -fsanitize=address -g src/main.c src/init_data.c src/input_validation.c  src/set_data.c src/mutexes.c src/utils/* -lpthread && ./a.out 3 40 20 10

/* System headers */
#include <stdio.h>
#include <pthread.h>

/* User defined headers */
#include "set_data.h"
#include "init_data.h"
#include "threads.h"
#include "free_data.h"

// void	print_data(t_data *data)
// {
// 	size_t	i;
// 	size_t	number_of_philo;

// 	i = 0;
// 	number_of_philo = data[0].shared_data->number_of_philo;
// 	while (i < number_of_philo)
// 	{
// 		printf("shared_data = %p\n", data[i].shared_data);
// 		printf("simulation_start_time = %lu\n", data[i].shared_data->simulation_start_time);
// 		printf("is_dead = %d\n", data[i].shared_data->is_dead);
// 		printf("mutex_is_dead = %p\n", &data[i].shared_data->mutex_is_dead);
// 		printf("forks = %p\n", data[i].shared_data->forks);
// 		printf("mutex_print = %p\n", &data[i].shared_data->mutex_print);
// 		printf("---------------\n");
// 		printf("philo id = %lu\n", data[i].philo->id);
// 		printf("philo done eating = %d\n", data[i].philo->done_eating);
// 		printf("philo timestamp_last_meal = %lu\n", data[i].philo->timestamp_last_meal);
// 		printf("philo mutex_timestamp_last_meal = %p\n", &data[i].philo->mutex_timestamp_last_meal);
// 		printf("\n");
// 		i++;
// 	}
// }

// gcc src/main.c src/input_validation.c src/init_data.c src/set_data.c src/timing.c src/utils/*.c src/mutexes.c  -pthread && ./a.out 4 400 200 100

int	main(int argc, char *argv[])
{
	t_shared_data	shared_data;
	t_data			*data;
	pthread_t		*philo_threads;
	pthread_t		*monitor_thread;
	
	if (validate_and_set_input_data(argc, argv, &shared_data) == false)
		return (-1);
	data = init_data(&shared_data);
	if (data == NULL)
		return (-1);
	// print_data(data);
	philo_threads = start_philo_threads(data);
	if (philo_threads == NULL)
		return (-1);
	monitor_thread = start_monitoring_thread(data);
	if (monitor_thread == NULL)
		return (-1);

	// size_t	i = 0;
	// while (i < shared_data.number_of_philo)
	// {
	// 	if (pthread_join(philo_threads[i], NULL) != 0)
	// 	{
	// 		printf("Error with pthread_join\n");
	// 		return (-1);
	// 	}
	// 	i++;
	// }
	// if (pthread_join(*monitor_thread, NULL) != 0)
	// {
	// 	printf("Error with pthread_join\n");
	// 	return (-1);
	// }
	join_threads(&shared_data, philo_threads, monitor_thread);
	// if (!join_threads(shared_data, philo_threads, monitor_thread))
	// 	return (-1);
	free_data(data, philo_threads, monitor_thread);
	return (0);
}