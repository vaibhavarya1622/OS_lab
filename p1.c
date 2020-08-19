#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void fibonacci(int arr[], int n)
{
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; ++i)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    pid_t cpid = fork();
    if (cpid > 0)
    {
        printf("The parent process will wait for 10 seconds while child process computes fibonacci\n");
        sleep(10);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    else if (cpid == 0)
    {
        fibonacci(arr, n);
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
    }
}