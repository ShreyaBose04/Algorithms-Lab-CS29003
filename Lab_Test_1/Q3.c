#include <stdio.h>
#include <stdlib.h>
float max(float a, float b)
{
    if (a > b)
        return a;
    else
        return b;
}
float solve(float a, char c, float b)
{
    if (c == '+')
        return a + b;
    if (c == '*')
        return a * b;
}
int main()
{
    int n, i, s, j, k;
    printf("no. of positive numbers: ");
    scanf("%d", &n);
    float a[n + 1];
    char op[n - 1];
    float dp[n + 1][n + 1];
    printf("Enter %d numbers from left to right: ", n);
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &a[i]);
        dp[i][i] = a[i];
    }
    printf("Enter %d operators from left to right as a string : ", n - 1);
    scanf("%s", op);
    for (s = 1; s <= n - 1; s++)
    {
        for (i = 1; i <= n - s; i++)
        {

            dp[i][i + s] = solve(dp[i][i], op[i - 1], dp[i + 1][i + s]);
            for (k = 1; k < s; k++)
            {
                dp[i][i + s] = max(dp[i][i + s], solve(dp[i][i + k], op[i + k - 1], dp[i + k + 1][i + s]));
            }
        }
    }
    printf("max value of the expression is: %f\n", dp[1][n]);
}