/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:51:01 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/10 16:10:21 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

/*
** The data is stored in end argument.
*/

void	add_milliseconds_to_timeval(struct timeval *start, struct timeval *end, useconds_t milliseconds)
{
	// convert milliseconds to microseconds
	suseconds_t microseconds = milliseconds * 1000;

	// Extract seconds and microseconds from microseconds
	time_t	seconds = microseconds / 1000000;
	microseconds = microseconds % 1000000;

	end->tv_sec = start->tv_sec + seconds;
	end->tv_usec = start->tv_usec + microseconds;
}

t_milliseconds timeval_to_milliseconds(struct timeval time)
{
	return time.tv_sec * 1000 + time.tv_usec / 1000;
}

int sleep_milliseconds(useconds_t milliseconds)
{
	struct timeval	current_time;
	struct timeval	final_time;
	t_milliseconds	current_time_milliseconds;
	t_milliseconds	final_time_milliseconds;
	useconds_t		sleep_interval_microseconds;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		printf("Error with gettimeofday function");
		return (false);
	}
	add_milliseconds_to_timeval(&current_time, &final_time, milliseconds);
	final_time_milliseconds = timeval_to_milliseconds(final_time);
	sleep_interval_microseconds = 10;

	// sleep_interval_microseconds = milliseconds * 1000 / 4;
	// if (sleep_interval_microseconds > 1000)
	// 	sleep_interval_microseconds = 1000;
	while (1)
	{
		if (usleep(sleep_interval_microseconds) != 0)
		{
			printf("Error with usleep function");
			return (false);
		}
		if (gettimeofday(&current_time, NULL) != 0)
		{
			printf("Error with gettimeofday function");
			return (false);
		}
		current_time_milliseconds = timeval_to_milliseconds(current_time);
		if (current_time_milliseconds >= final_time_milliseconds)
			return (true);
	}
	return (true);
}