/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:50:22 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 16:03:39 by hyilmaz       ########   odam.nl         */
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

/* Macros */
#define INTERVAL_IN_MICROSECONDS 10

/* Function prototypes */
int sleep_milliseconds(useconds_t microseconds);

#endif

