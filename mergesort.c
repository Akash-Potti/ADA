#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mergesort(int a[100000], int low, int mid, int high)
{
    int i, j, k, temp[100000];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        a[i] = temp[i];
    }
}

void merge(int a[100000], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge(a, low, mid);
        merge(a, mid + 1, high);
        mergesort(a, low, mid, high);
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
    merge(a, 0, n - 1);
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