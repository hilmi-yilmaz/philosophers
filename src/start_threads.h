/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   start_threads.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:35:50 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 12:05:17 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef START_THREADS_H
# define START_THREADS_H

/* System headers */
#include <pthread.h>
#include <stdio.h>

/* User defined headers */
#include "data_structs.h"
#include "timing.h"
#include "utils/utils.h"


/* Function prototypes */
pthread_t	*start_philo_threads(t_philo_data *philos);
pthread_t	*start_monitoring_thread(t_philo_data *philos);


#endif /* START_THREADS_H */