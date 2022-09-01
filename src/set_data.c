/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_data.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/07 17:04:42 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/31 16:53:22 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "set_data.h"

static bool	only_numeric_characters(char *str_number)
{
	size_t	i;

	i = 0;
	while (str_number[i])
	{
		if (!ft_isdigit(str_number[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_command_line_arg(char **argv, size_t i)
{
	int	err;

	if (argv[i][0] == '\0')
	{
		printf("No empty strings allowed\n");
		return (false);
	}
	if (!only_numeric_characters(argv[i]))
	{
		printf("Only numeric characters are accepted\n");
		return (false);
	}
	atoi_with_int_overflow_check(argv[i], &err);
	if (err == 1)
	{
		printf("Error: over- or underflow in one of the input values\n");
		return (false);
	}
	return (true);
}

bool	validate_input(int argc, char *argv[])
{
	size_t	i;

	if (argc != 5 && argc != 6)
	{
		printf("You have to provide 4 or 5 arguments!\n");
		return (false);
	}
	i = 0;
	while (argv[i] != NULL)
	{
		if (check_command_line_arg(argv, i) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	set_input_data(char *argv[], t_shared_data *shared_data)
{
	int	err;

	shared_data->number_of_philo = atoi_with_int_overflow_check(argv[0], &err);
	shared_data->time_to_die = atoi_with_int_overflow_check(argv[1], &err);
	shared_data->time_to_eat = atoi_with_int_overflow_check(argv[2], &err);
	shared_data->time_to_sleep = atoi_with_int_overflow_check(argv[3], &err);
	if (argv[4])
		shared_data->number_of_times_to_eat = atoi_with_int_overflow_check(
				argv[4], &err);
	else
		shared_data->number_of_times_to_eat = -1;
	shared_data->is_dead = false;
	shared_data->forks = create_mutexes(shared_data->number_of_philo);
	if (shared_data->forks == NULL)
		return (false);
	if (pthread_mutex_init(&shared_data->mutex_is_dead, NULL) != 0 || \
		pthread_mutex_init(&shared_data->mutex_print, NULL) != 0)
	{
		printf("Error with pthread_mutex_init\n");
		return (false);
	}
	return (true);
}

bool	validate_and_set_input_data(int argc, char *argv[],
			t_shared_data *shared_data)
{
	if (!validate_input(argc, argv + 1))
		return (false);
	ft_memset(shared_data, 0, sizeof(t_shared_data));
	if (!set_input_data(argv + 1, shared_data))
		return (false);
	if (shared_data->number_of_philo == 0)
		return (false);
	return (true);
}
