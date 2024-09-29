#include <stdio.h>

void main()
{
    int n, i, j, a[20][20], d[20][20], k;
    printf("enter the number of vertices: ");
    scanf("%d", &n);
    printf("enter elements into the matrix: ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            d[i][j] = a[i][j];
        }
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    printf("Floyds Matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d \t", d[i][j]);
        }
        printf("\n");
    }
}