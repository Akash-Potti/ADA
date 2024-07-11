#include <stdio.h>
#include <stdlib.h>
#define INF 999
void prims(int n, int cost[50][50], int source)
{
    int i, j, k, u, v, min, s[50], d[50], N[50], t[50][3], sum;
    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        d[i] = cost[source][i];
        N[i] = source;
    }
    s[source] = 1;
    sum = 0;
    k = 1;
    for (i = 1; i < n; i++)
    {
        min = INF;
        u = 0;
        for (j = 1; j <= n; j++)
        {
            if (s[j] == 0 && d[j] <= min)
            {
                min = d[j];
                u = j;
            }
        }
        t[k][1] = u;
        t[k][2] = N[u];
        k++;
        sum = sum + cost[u][N[u]];
        s[u] = 1;
        for (v = 1; v <= n; v++)
        {
            if (s[v] == 0 && cost[u][v] < d[v])
            {
                d[v] = cost[u][v];
                N[v] = u;
            }
        }
    }
    if (sum >= INF)
    {
        printf("no spanning tree\n");
    }
    else
    {
        printf("spanning tree is\n");
        for (i = 1; i < n; i++)
        {
            printf("%d->%d\n", t[i][1], t[i][2]);
        }
        printf("cost of spanning tree is %d\n", sum);
    }
}

void main()
{
    int i, j, cost[50][50], min, n, source;
    printf("enter number of nodes: ");
    scanf("%d", &n);
    printf("enter the cost matrix: ");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    source = 0;
    min = INF;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (cost[i][j] != 0 && cost[i][j] < min)
            {
                min = cost[i][j];
                source = i;
            }
        }
    }
    printf("source node is %d\n", source);
    prims(n, cost, source);
}