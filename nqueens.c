#include <stdio.h>
#include <stdlib.h>

int place(int x[], int k, int n)
{
    int i;
    for (i = 1; i < k; i++)
    {
        if (x[i] == x[k] || abs(x[i] - x[k]) == abs(i - k))
        {
            return 0;
        }
    }
    return 1;
}

void main()
{
    int n, x[50], k, count = 0, i;
    printf("enter number of queens: ");
    scanf("%d", &n);
    k = 1;
    x[k] = 0;
    while (k != 0)
    {
        x[k]++;
        while (x[k] <= n && !place(x, k, n))
        {
            x[k]++;
        }
        if (x[k] <= n)
        {
            if (k == n)
            {
                count++;
                printf("solution %d is\n", count);
                for (i = 1; i <= n; i++)
                {
                    printf("%d ", x[i]);
                }
                printf("\n");
            }
            else
            {
                k++;
                x[k] = 0;
            }
        }
        else
        {
            k--;
        }
    }
    if (count == 0)
    {
        printf("no solution\n");
    }
}