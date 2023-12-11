#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int main()
{
    int n, m, i, j, len, cnt;

    printf("length of X: ");
    scanf("%d", &n);
    char x[n];
    if (n != 0)
    {
        printf("X: ");
        scanf("%s", x);
    }

    printf("length of Y: ");
    scanf("%d", &m);
    char y[m];
    if (m != 0)
    {
        printf("Y: ");
        scanf("%s", y);
    }

    if (n == 0)
    {
        for (i = 0; i < m; i++)
        {
            printf("+%c ", y[i]);
        }
        return 0;
    }
    if (m == 0)
    {
        for (i = 0; i < n; i++)
        {
            printf("-%c ", x[i]);
        }
        return 0;
    }

    int dp[n + 1][m + 1];
    for (i = 0; i <= n; i++)
    {
        for (j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    len = dp[n][m];
    char ans[len];
    ans[len] = '\0';
    cnt = len - 1;
    i = n;
    j = m;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            ans[cnt--] = x[i - 1];
            x[i - 1] = '0';
            y[j - 1] = '0';
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1])
            i--;
        else
            j--;
    }

    cnt = 0;
    i = 0;
    j = 0;
    while (i < n && j < m)
    {
        while (x[i] != '0')
        {
            printf("-%c ", x[i]);
            i++;
        }
        while (y[j] != '0')
        {
            printf("+%c ", y[j]);
            j++;
        }
        printf("%c ", ans[cnt++]);
        j++;
        i++;
    }
    if (i == n)
    {
        while (j < m)
        {
            printf("+%c ", y[j]);
            j++;
        }
    }
    if (j == m)
    {
        while (i < n)
        {
            printf("-%c ", x[i]);
            i++;
        }
    }
}