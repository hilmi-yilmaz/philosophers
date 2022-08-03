/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutexes.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/03 17:02:56 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/03 17:07:11 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTEXES_H
# define MUTEXES_H

/* System headers */
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

/* User defined headers */
#include "utils/utils.h"

/* Function prototypes */
pthread_mutex_t	*create_mutexes(size_t number_of_forks);
void			destroy_mutexes(pthread_mutex_t *forks, size_t number_of_forks);

#endif /* MUTEXES_H */