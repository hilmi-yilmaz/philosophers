/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   timing.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: hyilmaz <hyilmaz@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/04 15:51:01 by hyilmaz       #+#    #+#                 */
/*   Updated: 2022/08/04 17:11:57 by hyilmaz       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "timing.h"

int sleep_milliseconds(useconds_t milliseconds)
{
	struct timeval time;
	int final_time;

	if (gettimeofday(&time, NULL) != 0)
	{
		printf("Error with gettimeofday function");
		return (false);
	}
	final_time = time.tv_usec + milliseconds * 1000;
	printf("final_time = %d\n", final_time);
	while (1)
	{
		if (usleep(INTERVAL_IN_MICROSECONDS) != 0)
		{
			printf("Error with usleep function");
			return (false);
		}
		if (gettimeofday(&time, NULL) != 0)
		{
			printf("Error with gettimeofday function");
			return (false);
		}
		// printf("%d\n", time.tv_usec);
		if (time.tv_usec >= final_time)
			return (true);
	}
	return (true);
}