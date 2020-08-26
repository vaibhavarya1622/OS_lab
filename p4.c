#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t child_pid;
    child_pid = fork();
    if (child_pid == 0)
    {
        child_pid = fork();
        if (child_pid == 0)
        {
            child_pid = fork();
        }
    }
    else
    {
        child_pid = 0;
        child_pid = fork();
        if (child_pid == 0)
        {
            child_pid = fork();
            if (child_pid > 0)
            {
                fork();
            }
        }
    }
}
/*Construct the complete binary tree using fork() system call and return the height of the tree*/