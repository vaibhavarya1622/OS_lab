/*Implementation of peterson's solution.In this program there is race condition between parent thread and child thread*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#define FALSE 0
#define TRUE 1
#define N 2
#define size 10
typedef struct fun_arg
{
    int *arr;
    int n;
} parameter;
int arr[size];
int turn;
int interested[N];

void enter_region(int process)
{
    int other;
    other = 1 - process;
    interested[process] = TRUE;
    turn = process;
    while (turn == process && interested[other] == TRUE)
        ; //Do nothing
}
void exit_region(int process)
{
    interested[process] = FALSE;
}

void *fibonacci(void *pr)
{
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < size; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    enter_region(0);
    printf("In the fibonacci thread\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    exit_region(0);
    pthread_exit(NULL); //terminate the thread;
}

int main()
{
    pthread_t thread_id;
    int rc = pthread_create(&thread_id, NULL, fibonacci, NULL);
    if (rc)
    {
        printf("ERROR:return code from pthread_create: %d\n", rc);
        exit(1);
    }
    enter_region(1);
    printf("In parent thread\n");
    for (int i = 0; i < size; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    exit_region(1);
    pthread_exit(NULL); //terminate the thread
    return 0;
}