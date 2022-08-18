/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_philo_data.h                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/18 10:55:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/18 11:41:48 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_PHILO_DATA_H
# define INIT_PHILO_DATA_H

/* System headers */
#include <stdbool.h>

/* User defined headers */
#include "data_structs.h"
#include "mutexes.h"
#include "utils/utils.h"

/* Function prototypes */
t_philo_data	*init_philo_data(t_input_data *input_data);

#endif /* INIT_PHILO_DATA_H */