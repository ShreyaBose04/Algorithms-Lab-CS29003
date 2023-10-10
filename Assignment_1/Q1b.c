#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, cnt = 1, idx = 0, i;
    printf("Enter the size of the FI list: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the FI list for a country: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        if (a[idx] == a[i])
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
        if (cnt == 0)
        {
            idx = i;
            cnt++;
        }
    }
    printf("The FI value present in most of the people: %d\n", a[idx]);
    return 0;
}