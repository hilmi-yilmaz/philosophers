/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:51:01 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/24 15:14:39 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

/*
** Convert timeval struct to millisconds.
*/
t_milliseconds timeval_to_milliseconds(struct timeval time)
{
	return time.tv_sec * 1000 + time.tv_usec / 1000;
}

/*
** Returns timestamp beginning from start_time.
** If start_time = 10 (timestamp in ms)
** and 2 ms have passed, then the function returns 12 ms.
*/
t_milliseconds	get_simulation_timestamp_in_ms(t_milliseconds start_time)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (timeval_to_milliseconds(current_time) - start_time);
}

/*
** Get the current timestamp in milliseconds.
*/
t_milliseconds	get_current_timestamp_in_ms(void)
{
	struct timeval current_time;

	if (gettimeofday(&current_time, NULL) != 0)
	{
		printf("Error with gettimeofday function");
		return (0);
	}
	return (timeval_to_milliseconds(current_time));
}

bool sleep_milliseconds(useconds_t milliseconds)
{
	// Get current time
	t_milliseconds current_time;

	current_time = get_current_timestamp_in_ms();
	if (current_time == 0)
	{
		// handle error
		return (false);
	}

	// Sleep in steps in a loop
	// If 'milliseconds' passed, break
	while (get_current_timestamp_in_ms() - current_time < milliseconds)
		usleep(250);
	return (true);
}