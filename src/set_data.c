/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:04:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 16:23:19 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set_data.h"

void	set_input_data(char *argv[], t_input_data *input_data)
{
	int	err;

	input_data->number_of_philo = atoi_with_int_overflow_check(argv[0], &err);
	input_data->time_to_die = atoi_with_int_overflow_check(argv[1], &err);
	input_data->time_to_eat = atoi_with_int_overflow_check(argv[2], &err);
	input_data->time_to_sleep = atoi_with_int_overflow_check(argv[3], &err);
	if (argv[4])
		input_data->number_of_times_to_eat = atoi_with_int_overflow_check(argv[4], &err);
	else
		input_data->number_of_times_to_eat = -1;
}

bool	validate_and_set_input_data(int argc, char *argv[], t_input_data *input_data)
{	
	// Validate input and save the data
	if (!validate_input(argc, argv + 1))
		return (false);
	ft_memset(input_data, 0, sizeof(t_input_data));
	set_input_data(argv + 1, input_data);
	return (true);
}