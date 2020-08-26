/*Create a multi-process program with one parent and 3 children. Implement the cascade execution
order of process with ID and Name.*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    //parent
    pid_t pid = fork();
    if (pid == 0)
    {
        //child1
        pid_t pid1 = fork();
        if (pid1 == 0)
        {
            //child2
            pid_t pid2 = fork();
            if (pid2 == 0)
            {
                //child3
                printf("Child 3:child.id= %d\t parent.id= %d\n", getpid(), getppid());
                exit(0);
            }
            else if (pid2 > 0)
            {
                sleep(2);
                printf("Child 2:child.id = %d\tparent.id = %d\n", getpid(), getppid());
                exit(0);
            }
            else if (pid2 < 0)
            {
                printf("Error creating child 3\n");
            }
        }
        else if (pid1 > 0)
        {
            sleep(5);
            printf("Child 1:child.id = %d\tparent.id = %d\n", getpid(), getppid());
            exit(0);
        }
        else if (pid < 0)
        {
            printf("Error creating child 2\n");
        }
    }
    else if (pid > 0)
    {
        sleep(8);
        printf("Parent: process ID: %d\n", getpid());
    }
    return 0;
}