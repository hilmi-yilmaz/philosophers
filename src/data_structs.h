/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_structs.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:00:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 13:10:07 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

/* System headers */
# include <stddef.h>
# include <pthread.h>

/* User defined headers */
// # include "timing.h"

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
	size_t			number_of_times_to_eat;
}		t_input_data;

typedef struct s_philo_data
{
	size_t			philo_id;
	t_input_data	*input_data;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	unsigned long	*timestamp_last_meal;
	pthread_mutex_t	*mutex_last_meal;
}		t_philo_data;

#endif