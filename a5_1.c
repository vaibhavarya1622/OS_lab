/*C program to show static global and local variables using thread*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
int g = 0;
void *test(void *arg)
{
    int id = (int)(intptr_t)arg;
    static int s = 0;
    ++s, ++g;
    printf("Thread_id: %d static: %d global: %d\n", id, s, g);
}
int main()
{
    pthread_t thread;
    for (int i = 0; i < 3; ++i)
    {
        printf("In main: creating thread id: %d \n", i);
        pthread_create(&thread, NULL, test, (void *)(intptr_t)i);
        //pthread_join(thread, NULL);
    }
    pthread_exit(NULL);
    return 0;
}