#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "../src/timing.h"

int main(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	// int first = time.tv_usec;

	// usleep(1000);
	sleep_milliseconds(1000);

	gettimeofday(&time, NULL);
	// int second = time.tv_usec;

	// printf("%d\n", second - first);

	return (0);
}