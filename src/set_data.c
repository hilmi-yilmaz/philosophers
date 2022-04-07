/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:04:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/04/07 17:09:42 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set_data.h"

void	set_data(char *argv[], t_data *data)
{
	int	err;

	data->number_of_philo = atoi_with_int_overflow_check(argv[0], &err);
	data->time_to_die = atoi_with_int_overflow_check(argv[1], &err);
	data->time_to_eat = atoi_with_int_overflow_check(argv[2], &err);
	data->time_to_sleep = atoi_with_int_overflow_check(argv[3], &err);
	if (argv[4])
		data->number_of_times_to_eat = atoi_with_int_overflow_check(argv[4], &err);
	else
		data->number_of_times_to_eat = -1;
}