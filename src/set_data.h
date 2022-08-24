/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 17:51:05 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_DATA_H
# define SET_DATA_H

/* System headers */

/* User defined headers */
# include "data_structs.h"
# include "input_validation.h"
# include "timing.h"
# include "utils/utils.h"
# include "mutexes.h"

/* Function prototypes */
bool	validate_and_set_input_data(int argc, char *argv[], t_shared_data *shared_data);

#endif

