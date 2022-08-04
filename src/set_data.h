/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:05:19 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 12:49:35 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_DATA_H
# define SET_DATA_H

/* System headers */

/* User defined headers */
# include "data_structs.h"
# include "utils/utils.h"
# include "mutexes.h"

/* Function prototypes */
void	set_input_data(char *argv[], t_input_data *input_data);

#endif
