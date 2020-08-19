#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void swap(int *a, int *b)
{
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}
int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int j = l - 1;
    for (int i = l; i < h; ++i)
    {
        if (arr[i] <= x)
        {
            ++j;
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[j + 1], &arr[h]);
    return j + 1;
}
void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, h);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int arr1[n1 + 1];
    int arr2[n2 + 1];
    for (int i = 0; i < n1; ++i)
    {
        arr1[i] = arr[l + i];
    }
    arr1[n1] = INT_MAX;
    for (int i = 0; i < n2; ++i)
    {
        arr2[i] = arr[m + i + 1];
    }
    arr2[n2] = INT_MAX;
    int i1 = 0, i2 = 0;
    for (int i = l; i <= r; ++i)
    {
        if (arr1[i1] <= arr2[i2])
        {
            arr[i] = arr1[i1++];
        }
        else
        {
            arr[i] = arr2[i2++];
        }
    }
}
void mergeSort(int arr[], int p, int q)
{
    if (p < q)
    {
        int mid = p + (q - p) / 2;
        mergeSort(arr, p, mid);
        mergeSort(arr, mid + 1, q);
        merge(arr, p, mid, q);
    }
}
int main(void)
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }
    pid_t cpid = fork();
    if (cpid > 0)
    {
        //sleep(15);
        /* uncommment the upper line to halt parent process while the child process
        execution completes.This is the example of zombies state.Child process will be in process
        table even after it finished its execution*/
        mergeSort(arr, 0, n - 1);
        printf("The is the parent process: (after merge Sort) ");
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        wait(NULL);
        printf("The child process is terminated\n");
    }
    else if (cpid == 0)
    {
        //sleep(15);
        /* uncomment this upper line to halt child process while parent process finishes exection.
        This is the example of orphan state.The parent process finished its execution while child process is 
        still running.*/
        quickSort(arr, 0, n - 1);
        printf("This is the child process(after quickSort): ");
        for (int i = 0; i < n; ++i)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
        exit(0);
        //printf("The child process\n");
    }
    return 0;
}
