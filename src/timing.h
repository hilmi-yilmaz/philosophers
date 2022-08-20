/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:50:22 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/17 15:54:55 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_H
# define TIMING_H

/* System headers */
#include <sys/time.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

/* User defined headers */
#include "data_structs.h"

/* Macros */
#define INTERVAL_IN_MICROSECONDS 10

/* Function prototypes */
t_milliseconds	timeval_to_milliseconds(struct timeval time);
t_milliseconds	get_simulation_timestamp_in_ms(t_milliseconds start_time);
t_milliseconds	get_current_timestamp_in_ms(void);
bool            sleep_milliseconds(useconds_t milliseconds);

#endif

