#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int start, end, dur;
} program;
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}
void merge(program a[], int start, int mid, int end)
{
    int n1, n2, i, j, k;
    program large;
    n1 = mid - start + 1;
    n2 = end - mid;
    program b[n1 + 1], c[n2 + 1];
    for (i = 0; i < n1; i++)
    {
        b[i] = a[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = a[mid + 1 + i];
    }
    if (b[n1 - 1].end <= c[n2 - 1].end)
    {
        large = c[n2 - 1];
    }
    else
    {
        large = b[n1 - 1];
    }
    b[n1] = large;
    c[n2] = large;
    i = 0;
    j = 0;
    for (k = start; k <= end; k++)
    {
        if (b[i].end < c[j].end)
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
    }
}
void merge_sort(program a[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sort(a, mid + 1, end);
    merge_sort(a, start, mid);
    merge(a, start, mid, end);
}
int main()
{
    int n, i, j, k, time = 0, minstart = 10e8, n1;
    printf("enter number of programs: ");
    scanf("%d", &n);
    program p[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d %d %d", &p[i].start, &p[i].end, &p[i].dur);
        minstart = min(minstart, p[i].start);
    }
    merge_sort(p, 0, n - 1);
    n1 = p[n - 1].end - minstart + 2;
    int check[n1];
    for (i = 1; i < n1; i++)
    {
        check[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = p[i].start; j <= p[i].end; j++)
        {
            if (p[i].dur == 0)
                break;
            if (check[j] == 1)
                p[i].dur--;
        }
        for (j = p[i].end; j >= p[i].start; j--)
        {
            if (p[i].dur == 0)
                break;
            check[j] = 1;
            p[i].dur--;
        }
    }
    for (i = 1; i < n1; i++)
    {
        time += check[i];
    }
    printf("time = %d\n", time);
}