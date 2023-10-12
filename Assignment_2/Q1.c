#include <stdio.h>
#include <stdlib.h>
int box(int a[], int start, int n, int m, int out, int sum)
{
    if (out == n - 1)
    {
        return (((n * (n - 1)) / 2) - sum);
    }
    int cnt = 0, i = start % n;
    while (cnt < m)
    {
        i = i % n;
        if (a[i] != -1)
        {
            cnt++;
        }
        i++;
    }
    i--;
    sum += a[i % n];
    a[i % n] = -1;
    return box(a, ((i + 1) % n), n, m, (out + 1), sum);
}
int main()
{
    int n, m, i;
    printf("enter n and m: ");
    scanf("%d %d", &n, &m);
    int a[n];
    for (i = 0; i < n; i++)
        a[i] = i;
    int ans = box(a, 0, n, m, 0, 0) + 1;
    printf("final box: %d\n", ans);
}