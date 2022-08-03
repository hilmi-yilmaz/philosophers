#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct test_struct
{
	char	*name;
	int		age;
};

static void *thread_func(void *arg)
{

	struct test_struct *Person;

	Person = malloc(sizeof(*Person));
	Person->age = 24;
	Person->name = strdup(arg);

	return (void *)Person;

    // char    *s = arg;
    // // exit(10);
    // printf("%s", s);
    // return (void *)strlen(s);
}

int main(void)
{
    pthread_t	t1;
    void        *res;
    int         s;


    s = pthread_create(&t1, NULL, thread_func, "Hilmi");
	printf("main thread tid = %ld\n", (long)t1);
    if (s != 0)
        exit(1);
    printf("Message from main()\n");
    s = pthread_join(t1, &res); // return-value of the thread
    if (s != 0)
        exit(1);

	struct test_struct *Person = res;
	printf("main: name = %s\n", Person->name);
	printf("main: age = %d\n", Person->age);

    
    // printf("Thread returned %d\n", (int)res);
    exit(EXIT_SUCCESS);
}