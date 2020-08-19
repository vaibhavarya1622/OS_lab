#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t cpid = fork();
    if (cpid == 0)
    {
        printf("This is the child process with id: %d\n", getpid());
    }
    else
    {
        printf("This is the parent process with id: %d\n", getpid());
    }
    return 0;
}