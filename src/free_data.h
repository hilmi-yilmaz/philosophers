/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_data.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 12:18:35 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 12:19:26 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_DATA_H
# define FREE_DATA_H

/* System headers */
#include <pthread.h>

/* User defined headers */
#include "data_structs.h"
#include "mutexes.h"
#include "utils/utils.h"

/* Function prototypes */
void	free_data(t_philo_data *philos, pthread_t *philo_threads, pthread_t *monitor_thread);

#endif /* FREE_DATA_H */