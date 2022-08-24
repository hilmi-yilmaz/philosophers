/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 11:35:50 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 16:09:57 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

/* System headers */
# include <pthread.h>
# include <stdio.h>

/* User defined headers */
# include "data_structs.h"
# include "philo.h"
# include "monitor.h"
# include "utils/utils.h"

/* Function prototypes */
pthread_t	*start_philo_threads(t_data *data);
pthread_t	*start_monitoring_thread(t_data *data);
void		join_threads(t_input_data input_data, pthread_t *philo_threads,\
						pthread_t *monitor_thread);




#endif /* START_THREADS_H */