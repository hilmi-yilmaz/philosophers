#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void *thread_func(void *arg)
{
    char    *s = arg;
    exit(10);
    printf("%s", s);
    return (void *)strlen(s);
}

int main(int argc, char *argv[])
{
    pthread_t  t1;
    void        *res;
    int         s;

    s = pthread_create(&t1, NULL, thread_func, "Hilmi\n");
    if (s != 0)
        exit(1);
    printf("Message from main()\n");
    s = pthread_join(t1, &res); // return-value of the thread
    if (s != 0)
        exit(1);
    
    printf("Thread returned %ld\n", (long)res);
    exit(EXIT_SUCCESS);
}