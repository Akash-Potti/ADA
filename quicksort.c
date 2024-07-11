#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int a[100000], int low, int high)
{
    int i, j, key, temp;
    key = a[low];
    i = low + 1;
    j = high;
    while (i <= high && key >= a[i])
    {
        i++;
    }
    while (key < a[j])
    {
        j--;
    }
    if (i < j)
    {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    else
    {
        temp = a[low];
        a[low] = a[j];
        a[j] = temp;
    }
    return j;
}

void quicksort(int a[100000], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

void main()
{
    int a[100000], n, i;
    float time;
    clock_t start, end;
    printf("enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    start = clock();
    quicksort(a, 0, n - 1);
    end = clock();
    time = (end - start) / CLOCKS_PER_SEC;
    printf("sorted elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    printf("time taken is %f\n", time);
}