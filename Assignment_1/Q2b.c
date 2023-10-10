#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, totsum = 0;
    printf("Enter the size of the FI list: ");
    scanf("%d", &n);
    int a[n], fwdsum[n + 1];
    fwdsum[0] = 0;
    printf("Enter the FI list for a country: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        totsum += a[i];
        fwdsum[i + 1] = fwdsum[i] + a[i];
    }
    printf("Stable indices in the list are: ");
    for (i = 0; i < n; i++)
    {
        if (fwdsum[i] == totsum - fwdsum[i + 1])
            printf("%d ", i);
    }
    printf("\n");
}