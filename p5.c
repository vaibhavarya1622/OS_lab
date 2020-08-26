/* C program for orphan process*/
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid > 0)
    {
        printf("PP:In parent process\n");
        printf("PP:The process is about to exit\n");
    }
    else if (pid == 0)
    {
        sleep(5); //while child process sleeps parent will finished its exection and exits.Thus child has become orphan.
        printf("CP:In child process\n");
        printf("CP:The parent process has exited\n");
    }
    return 0;
}