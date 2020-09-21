/*demonstration of race condition using fork() system call*/
/*Here parent and child will be interleaved*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int i, j;
    i = fork();
    if (i == 0) //child process
    {
        for (j = 1; j <= 10; j++)
            printf("\nChild here\n");
        exit(0);
    }
    else //parent process
    {
        for (j = 1; j <= 10; j++)
            printf("\nParent here\n");
    }
    return 0;
}