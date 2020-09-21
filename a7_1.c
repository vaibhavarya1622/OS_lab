/*Implementation of producer consumer problem*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t empty, full, sm;
#define BUFFER_SIZE 10
#define PROCESS 2
#define TRUE 1
#define FALSE 0
#define SHARED 1
int data;
int buffer[BUFFER_SIZE];
int in = 2;
int out = 0;
int count = 0;
int turn;
int interested[PROCESS];
int prev0 = 0;
int prev1 = 1;

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

void *producer()
{
    printf("Producer Created\n");
    printf("producer id is %ld\n", pthread_self());
    for (int in = 0; in < 100; ++in)
    {
        sem_wait(&empty);
        sem_wait(&sm);
        data = in;
        sem_post(&sm);
        sem_post(&full);
    }
}
void *consumer()
{
    int total = 0;
    printf("Consumer Created\n");
    printf("Consumer id is %ld\n", pthread_self());
    for (int out = 0; out < 100; ++out)
    {
        sem_wait(&full);
        sem_wait(&sm);
        total += data;
        sem_post(&sm);
        sem_post(&empty);
    }
    printf("%d\n", total);
}
int main()
{
    pthread_t ptid, ctid;
    sem_init(&empty, SHARED, 1);
    sem_init(&full, SHARED, 0);
    sem_init(&sm, SHARED, 1);
    pthread_create(&ptid, NULL, producer, NULL);
    pthread_create(&ctid, NULL, consumer, NULL);

    pthread_join(ptid, NULL);
    pthread_join(ctid, NULL);
    return 0;
}