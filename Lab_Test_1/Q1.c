#include <stdio.h>
#include <stdlib.h>
int students(int mid, int prizes[], int p)
{
    int i, sum = 0;
    for (i = 0; i < p; i++)
    {
        if (prizes[i] % mid == 0)
            sum += prizes[i] / mid;
        else
            sum += (prizes[i] / mid) + 1;
    }
    return sum;
}

int main()
{
    int n, p, i, j, sum = 0, mid;
    printf("n= ");
    scanf("%d", &n);
    printf("no. of prizes= ");
    scanf("%d", &p);
    int prizes[p];
    printf("enter no. of prizes of each type: ");
    for (i = 0; i < p; i++)
    {
        scanf("%d", &prizes[i]);
        sum += prizes[i];
    }
    int s = 1;
    int e = sum;
    while (s < e)
    {
        mid = (s + e) / 2;
        if (students(mid, prizes, p) <= n)
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    printf("output: %d\n", e);
}
