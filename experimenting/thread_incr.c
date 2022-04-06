#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

static int glob = 0;

static void *thread_func(void *arg)
{
    int loops = *((int *)arg);
    int loc, j;

    for (j = 0; j < loops; j++)
    {
        loc = glob;
        loc++;
        glob = loc;
    }
    return (NULL);
}

int main(int argc, char *argv[])
{
    pthread_t   t1, t2;
    int         loops, s;

    if (argc > 1)
        loops = atoi(argv[1]);
    else
        loops = 10000000;
    
    s = pthread_create(&t1, NULL, thread_func, &loops);
    if (s != 0)
        exit(1);
    
    s = pthread_create(&t2, NULL, thread_func, &loops);
    if (s != 0)
        exit (1);

    s = pthread_join(t1, NULL); // because second argument is NULL, we are not catching the return value of the function executed by the thread
    if (s != 0)                 // which is obvious because the thread_func returns NULL.
        exit (1);

    s = pthread_join(t2, NULL);
    if (s != 0)
        exit (1);

    printf("glob = %d\n", glob);
    exit(EXIT_SUCCESS);
}