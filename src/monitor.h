/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 15:40:09 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MONITOR_H
# define MONITOR_H

/* System headers */
# include <pthread.h>

/* User defined headers */
# include "data_structs.h"
# include "timing.h"

/* Function prototypes */
void	*monitor_routine(void *arg);

#endif

