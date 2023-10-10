#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, cnt, i, j;
    printf("Enter the size of the FI list: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the FI list for a country: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        cnt = 0;
        for (j = 0; j < n; j++)
        {
            if (a[i] == a[j])
            {
                cnt++;
            }
        }
        if (cnt > (n / 2))
        {
            printf("The FI value present in most of the people: %d\n", a[i]);
            return 0;
        }
    }
}