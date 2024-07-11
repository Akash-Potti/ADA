#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubblesort(int a[50], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}
void main()
{
    int a[10000], n, i;
    float time;
    clock_t start,
        end;
    printf("enter number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % n;
    }
    start = clock();
    bubblesort(a, n);
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