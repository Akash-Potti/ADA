#include <stdio.h>
int dijsktras(int n, int cost[][20], int source, int dest, int s[], int d[], int p[])
{
    int v, u, i, j, min;
    s[source] = 1;
    for (i = 1; i < n; i++)
    {
        min = 999;
        u = 0;
        for (j = 1; j <= n; j++)
        {
            if (s[j] == 0 && d[j] <= min)
            {
                min = d[j];
                u = j;
            }
        }
        s[u] = 1;

        for (v = 1; v <= n; v++)
        {
            if (s[v] == 0 && d[u] + cost[u][v] < d[v])
            {
                d[v] = d[u] + cost[u][v];
                p[v] = u;
            }
        }
    }
    return 0;
}
int printpath(int source, int dest, int d[], int p[])
{
    int i;
    if (d[dest] == 999)
    {
        printf("no path to print");
        return 0;
    }
    i = dest;
    while (i != source)
    {
        printf("%d <-", i);
        i = p[i];
    }
    printf(" %d is = %d\n", source, d[dest]);
    return 0;
}
int main()
{
    int n, i, j, cost[20][20], source, dest, s[20], d[20], p[20], min;
    printf("enter the number of noded in the graph : ");
    scanf("%d", &n);
    printf("enter the cost matrix of the graph : \n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }
    printf("enter the source to the given graph : ");
    scanf("%d", &source);

    for (i = 1; i <= n; i++)
    {
        s[i] = 0;
        d[i] = cost[source][i];
        p[i] = source;
    }
    dijsktras(n, cost, source, dest, s, d, p);
    printf("the shortest path is ");
    for (dest = 1; dest <= n; dest++)
    {
        if (dest != source)
        {
            printpath(source, dest, d, p);
        }
    }
    return 0;
}