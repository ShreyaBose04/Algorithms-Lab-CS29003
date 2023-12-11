#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int gamble(int mach, int n, int points[], int skip[], int dp[])
{
    if (mach >= n)
        return 0;
    if (dp[mach] != -1)
        return dp[mach];
    dp[mach] = max(gamble(mach + 1, n, points, skip, dp), points[mach] + gamble(mach + skip[mach] + 1, n, points, skip, dp));
    return dp[mach];
}
int main()
{
    int n, i;
    printf("no. of machines: ");
    scanf("%d", &n);
    int points[n], skip[n], dp[n];
    printf("enter machine attributes\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &points[i], &skip[i]);
        dp[i] = -1;
    }
    dp[0] = gamble(0, n, points, skip, dp);
    printf("output = %d\n", dp[0]);
}