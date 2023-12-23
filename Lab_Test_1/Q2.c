#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int n;
double distance(int x1, int y1, int x2, int y2)
{
    double sx = ((x1 - x2) * (x1 - x2));
    double sy = ((y1 - y2) * (y1 - y2));
    double d = sqrt(sx + sy);
    return d;
}
void choose(int idx, int vis[], double dist[][n], int ans[], int cnt, int n)
{
    if (cnt == n)
        return;
    int i, next;
    double mini = __INT_MAX__;
    for (i = 0; i < n; i++)
    {
        if (vis[i] == 0 && dist[idx][i] <= mini)
        {
            next = i;
            mini = dist[idx][i];
        }
    }
    vis[next] = 1;
    ans[cnt] = next;
    choose(next, vis, dist, ans, cnt + 1, n);
}
int main()
{
    int i, j;
    printf("n= ");
    scanf("%d", &n);
    int x[n];
    int y[n];
    int vis[n];
    int ans[n];
    double dist[n][n];
    double cost = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
        vis[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            dist[i][j] = distance(x[i], y[i], x[j], y[j]);
        }
    }
    vis[0] = 1;
    ans[0] = 0;
    choose(0, vis, dist, ans, 1, n);
    for (i = 0; i < n; i++)
    {
        printf("%d->", ans[i]);
    }
    printf("0\n");
    for (i = 0; i < n - 1; i++)
    {
        cost += dist[ans[i]][ans[i + 1]];
    }
    cost += dist[ans[n - 1]][ans[0]];
    printf("cost = %d\n", (int)cost);
}