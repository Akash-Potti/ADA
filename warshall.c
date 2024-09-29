#include <stdio.h>

void warshalls(int n, int a[20][20])
{
    int i, j, p[20][20], k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            p[i][j] = a[i][j];
        }
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (p[i][j] == 0)
                {
                    if (p[i][k] == 1 && p[k][j] == 1)
                    {
                        p[i][j] = 1;
                    }
                }
            }
        }
    }
    printf("warshalls matrix: \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("%d", p[i][j]);
        }
        printf("\n");
    }
}

void main()
{
    int i, n, j, a[20][20];
    printf("enter number of rows and coloumns: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    warshalls(n, a);
}