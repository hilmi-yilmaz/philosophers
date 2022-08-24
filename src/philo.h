/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 15:43:18 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROUTINE_H
# define ROUTINE_H

/* System headers */
# include <pthread.h>

/* User defined headers */
# include "data_structs.h"
# include "timing.h"

/* Macros */
# define RIGHT_FORK(i, number_of_philo) ((i + 1) % number_of_philo)
# define LEFT_FORK(i) (i)

/* Function prototypes */
void	*philo_routine(void *arg);

#endif

