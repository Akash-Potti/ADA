#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionsort(int a[1000], int n)
{
    int i, j, temp, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
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
    selectionsort(a, n);
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