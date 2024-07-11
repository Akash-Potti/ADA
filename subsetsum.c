#include <stdio.h>
#include <stdlib.h>

void subsetsum(int n, int a[50], int d)
{
    int x[50], i, j, sum, k, count;
    count = 0;
    sum = 0;
    for (i = 0; i < n; i++)
    {
        x[i] = 0;
    }
    k = 1;
    x[k] = 1;
    while (1)
    {
        if (k <= n)
        {
            if (sum + a[k] == d)
            {
                count++;
                printf("Subset %d is: ", count);
                for (i = 1; i <= k; i++)
                {
                    if (x[i] == 1)
                    {
                        printf("%d ", a[i]);
                    }
                }
                x[k] = 0;
                k++;
                x[k] = 1;
            }
            else if (sum + a[k] < d)
            {
                sum = sum + a[k];
                k++;
                x[k] = 1;
            }
            else
            {
                x[k] = 0;
                k++;
                x[k] = 1;
            }
        }
        else
        {
            x[k] = 0;
            k--;
            while (k != 0 && x[k] == 0)
            {
                k--;
            }
            if (k == 0)
            {
                return;
            }
            x[k] = 0;
            sum = sum - a[k];
            k++;
            x[k] = 1;
        }
    }
}
void main()
{
    int a[50], n, d, i;
    printf("enter the number of elements: ");
    scanf("%d", &n);
    printf("enter the elements: ");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("enter the sum: ");
    scanf("%d", &d);
    subsetsum(n, a, d);
}