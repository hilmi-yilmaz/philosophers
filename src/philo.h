/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 16:32:01 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* System headers */
# include <pthread.h>

/* User defined headers */
# include "data_structs.h"
# include "timing.h"

/* Function prototypes */
void	set_done_eating(t_data *data);
void	eat(t_data *data);
void	sleep_and_think(t_data *data);
bool	is_dead(t_data *data);
void	print_status(t_data *data, char *status, char *colorcode);
void	*philo_routine(void *arg);

#endif
