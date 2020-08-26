/*C program to create a zombie process*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid > 0)
    {
        printf("The parent process is going to sleep for 5 seconds\n");
        sleep(5); //while parent sleeps child will finish its execution but still has entry in process table
        printf("The process have finised the execution by now\n");
    }
    else if (pid == 0)
    {
        printf("The child process has finised exection and is about to exit\n");
        exit(0); //The child process has become zombie process
    }
    return 0;
}