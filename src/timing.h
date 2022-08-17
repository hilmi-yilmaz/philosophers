/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:50:22 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/10 14:40:11 by hyilmaz       ########   odam.nl         */
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
typedef unsigned long t_milliseconds;

/* Macros */
#define INTERVAL_IN_MICROSECONDS 10

/* Function prototypes */
t_milliseconds	timeval_to_milliseconds(struct timeval time);
t_milliseconds	get_current_timestamp_in_ms(t_milliseconds start_time);
void			add_milliseconds_to_timeval(struct timeval *start, struct timeval *end, useconds_t milliseconds);
int 			sleep_milliseconds(useconds_t microseconds);

// New timing functions
t_milliseconds	get_current_timestamp_in_ms_new(void);
bool sleep_milliseconds_new(useconds_t milliseconds);

#endif

