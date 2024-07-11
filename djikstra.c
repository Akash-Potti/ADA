#include <stdio.h>
#define INF 999
void djikstra(int n, int cost[50][50], int s[50], int d[50], int p[50], int source)
{
    int i, j, u, v, min;

    s[source] = 1;
    for (i = 1; i < n; i++)
    {
        min = INF;
        u = 0;
        for (j = 1; j <= n; j++)
        {
            if (s[j] == 0 && d[j] < min)
            {
                min = d[j];
                u = j;
            }
        }
        s[u] = 1;
        for (v = 1; v < n; v++)
        {
            if (s[v] == 0 && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }
}
void print_path(int source, int n, int d[50], int p[50])
{
    int i, j;
    for (i = 1; i <= n; i++)
    {
        if (i != source)
        {
            printf("Shortest path from %d to %d is %d with path: ", source, i, d[i]);
            j = i;
            while (j != source)
            {
                printf("%d <- ", j);
                j = p[j];
            }
            printf("%d\n", source);
        }
    }
}
void main()
{
    int i, j, n, s[50], d[50], p[50], cost[50][50], source;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    printf("enter the source node: ");
    scanf("%d", &source);
    printf("enter the cost matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        d[i] = cost[1][i];
        p[i] = source;
    }
    djikstra(n, cost, s, d, p, source);
    print_path(source, n, d, p);
}