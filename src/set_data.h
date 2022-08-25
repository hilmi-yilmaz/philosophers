/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/25 13:13:17 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_DATA_H
# define SET_DATA_H

/* System headers */

/* User defined headers */
# include "data_structs.h"
# include "timing.h"
# include "utils/utils.h"
# include "mutexes.h"

/* Function prototypes */
bool	validate_input(int argc, char *argv[]);
bool	set_input_data(char *argv[], t_shared_data *shared_data);
bool	validate_and_set_input_data(int argc, char *argv[], t_shared_data *shared_data);

#endif

