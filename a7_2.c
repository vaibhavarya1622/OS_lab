/*Implementation of Readers-writers problem*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define SHARED 0
sem_t mutex;
sem_t wrt;
int data;
int readcnt = 0;

void *write(void *id)
{
    int c = 0;
    int i = *(int *)id;
    while (c < 5)
    {
        sem_wait(&wrt);
        printf("writer is writing %d \n", i);
        sem_post(&wrt);
        ++c;
    }
}
void *read(void *id)
{
    int i = *(int *)id;
    sem_wait(&mutex);
    readcnt++;
    if (readcnt == 1)
    {
        sem_wait(&wrt);
    }
    sem_post(&mutex);

    printf("reader is reading %d\n", i);
    sem_wait(&mutex);
    readcnt--;
    if (readcnt == 0)
    {
        sem_post(&wrt);
    }
    sem_post(&mutex);
}
int main()
{
    pthread_t wtid[5], rtid[5];
    int id[5];
    sem_init(&mutex, SHARED, 1);
    sem_init(&wrt, SHARED, 1);
    for (int i = 0; i < 5; ++i)
    {
        id[i] = i;
        pthread_create(&wtid[i], NULL, write, &id[i]);
        pthread_create(&rtid[i], NULL, read, &id[i]);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(wtid[i], NULL);
    }
    for (int i = 0; i < 5; ++i)
    {
        pthread_join(rtid[i], NULL);
    }
    return 0;
}