/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_structs.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:00:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 17:09:49 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

/* System headers */
# include <stddef.h>

/* Holds all data relevant for this project */
typedef struct s_data
{
	size_t	number_of_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		number_of_times_to_eat;
}		t_data;

#endif