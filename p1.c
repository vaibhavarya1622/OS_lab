#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct fun_arg
{
    int *arr;
    int n;
} parameter;

void *fibonacci(void *pr)
{
    parameter *arg = (parameter *)pr;
    int *arr = arg->arr;
    int n = arg->n;
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    printf("terminating the fibonacci thread\n");
    pthread_exit(NULL); //terminate the thread;
}

int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    parameter *arg;
    arg->arr = arr;
    arg->n = n;
    pthread_t thread_id;
    int rc = pthread_create(&thread_id, NULL, fibonacci, (void *)arg);
    if (rc)
    {
        printf("ERROR:return code from pthread_create: %d\n", rc);
        exit(1);
    }
    printf("Created new thread with id: %lu\n", thread_id);
    pthread_join(thread_id, NULL); /*The pthread_join() function suspends execution of the calling thread 
    until the target thread terminates, unless the target thread has already terminated*/
    for (int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    pthread_exit(NULL); //terminate the thread
    return 0;
}