#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, sumr, suml, i, j;
    printf("Enter the size of the FI list: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the FI list for a country: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Stable indices in the list are: ");
    for (i = 0; i < n; i++)
    {
        sumr = 0;
        suml = 0;
        for (j = 0; j < n; j++)
        {
            if (j < i)
                suml += a[j];
            else if (j > i)
                sumr += a[j];
            else
                continue;
        }
        if (suml == sumr)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}