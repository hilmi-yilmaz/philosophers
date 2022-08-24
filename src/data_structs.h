/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_structs.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:00:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 17:29:01 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

/* System headers */
# include <stddef.h>
# include <pthread.h>
# include <stdbool.h>

/* Macros */
# define RED "\033[0;31m"
# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"
# define CYAN "\033[0;36m"
# define PURPLE "\033[0;35m"
# define RESET "\033[0m"

/* User defined types */
typedef unsigned long t_milliseconds;

/* Holds all data relevant for this project */
typedef enum e_state
{
	EATING,
	SLEEPING,
	THINKING,
	DIED,
}	t_state;

typedef struct s_input_data
{
	size_t			number_of_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				number_of_times_to_eat;
}		t_input_data;

typedef struct s_philo
{
	size_t			id;
	bool			done_eating;
	pthread_mutex_t	mutex_done_eating;
	t_milliseconds	timestamp_last_meal;
	pthread_mutex_t	mutex_timestamp_last_meal;

}	t_philo;

typedef struct s_data
{
	// Shared data
	t_input_data	*input_data;
	size_t			*simulation_start_time;
	bool			*is_dead;
	pthread_mutex_t	*mutex_is_dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*mutex_print;

	// Unique data
	t_philo			*philo;

}	t_data;

#endif