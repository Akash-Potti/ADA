#include <stdio.h>
#include <stdlib.h>
#define INF 999

struct edge
{
    int u;
    int v;
    int wt;
};
typedef struct edge EDGE;

int create_edge_list(int n, int cost[50][50], EDGE e[50])
{
    int i, j, min, k;
    min = INF;
    k = 1;
    for (i = 1; i <= n; i++)
    {
        for (j = i + 1; j <= n; j++)
        {
            if (cost[i][j] < min)
            {
                e[k].u = i;
                e[k].v = j;
                e[k].wt = cost[i][j];
                k++;
            }
        }
    }
    return k - 1;
}
int min_edge(int n, EDGE e[50])
{
    int i, min, pos;
    min = INF;
    pos = -1;
    for (i = 1; i <= n; i++)
    {
        if (e[i].wt < min)
        {
            min = e[i].wt;
            pos = i;
        }
    }
    return pos;
}
int find(int p, int s[50])
{
    while (p != s[p])
    {
        p = s[p];
    }
    return p;
}

void unionij(int i, int j, int s[50])
{
    if (i < j)
    {
        s[j] = i;
    }
    else
    {
        s[i] = j;
    }
}

void kruskal(int n, int cost[50][50])
{
    int m, pos, i, j, k, u, v, sum, s[50], t[50][3], count, wt;
    EDGE e[50];
    for (i = 1; i <= n; i++)
    {
        s[i] = i;
    }
    m = create_edge_list(n, cost, e);
    k = 1;
    sum = 0;
    count = 0;
    while (count != n - 1)
    {
        pos = min_edge(m, e);
        if (pos == -1)
        {
            return;
        }
        u = e[pos].u;
        v = e[pos].v;
        wt = e[pos].wt;
        e[pos].wt = INF;
        i = find(u, s);
        j = find(v, s);
        if (i != j)
        {
            t[k][1] = u;
            t[k][2] = v;
            k = k + 1;
            sum = sum + cost[u][v];
            count = count + 1;
            unionij(i, j, s);
        }
    }
    if (count == n - 1)
    {
        printf("spanning tree is\n");
        for (i = 1; i <= n - 1; i++)
        {
            printf("%d->%d\n", t[i][1], t[i][2]);
        }
        printf("cost of spanning tree is %d\n", sum);
    }
    else
    {
        printf("no spanning tree\n");
    }
}

void main()
{
    int i, j, n, cost[50][50];
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
    kruskal(n, cost);
}