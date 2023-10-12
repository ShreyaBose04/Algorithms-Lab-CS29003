#include <stdio.h>
#include <stdlib.h>
struct point
{
    double x, y;
};
double max(double a, double b)
{
    if (a > b)
        return a;
    else
        return b;
}
void mergey(struct point pt[], int start, int mid, int end)
{
    int n1, n2, i, j, k;
    struct point large;
    n1 = mid - start + 1;
    n2 = end - mid;
    struct point b[n1 + 1], c[n2 + 1];
    for (i = 0; i < n1; i++)
    {
        b[i] = pt[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = pt[mid + 1 + i];
    }
    if (b[n1 - 1].y > c[n2 - 1].y)
    {
        b[n1] = b[n1 - 1];
        c[n1] = b[n1 - 1];
    }
    else
    {
        b[n1] = c[n1 - 1];
        c[n1] = c[n1 - 1];
    }
    i = 0;
    j = 0;
    for (k = start; k <= end; k++)
    {
        if (b[i].y < c[j].y)
        {
            pt[k] = b[i];
            i++;
        }
        else
        {
            pt[k] = c[j];
            j++;
        }
    }
}
void merge_sorty(struct point pt[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sorty(pt, mid + 1, end);
    merge_sorty(pt, start, mid);
    mergey(pt, start, mid, end);
}
void mergex(struct point pt[], int start, int mid, int end)
{
    int n1, n2, i, j, k;
    double large;
    n1 = mid - start + 1;
    n2 = end - mid;
    struct point b[n1 + 1], c[n2 + 1];
    for (i = 0; i < n1; i++)
    {
        b[i] = pt[start + i];
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = pt[mid + 1 + i];
    }
    if (b[n1 - 1].x > c[n2 - 1].x)
    {
        b[n1] = b[n1 - 1];
        c[n1] = b[n1 - 1];
    }
    else
    {
        b[n1] = c[n1 - 1];
        c[n1] = c[n1 - 1];
    }
    i = 0;
    j = 0;
    for (k = start; k <= end; k++)
    {
        if (b[i].x < c[j].x)
        {
            pt[k] = b[i];
            i++;
        }
        else
        {
            pt[k] = c[j];
            j++;
        }
    }
}
void merge_sortx(struct point pt[], int start, int end)
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    merge_sortx(pt, mid + 1, end);
    merge_sortx(pt, start, mid);
    mergex(pt, start, mid, end);
}
int BinarySearch(struct point c[], int size, double key)
{
    int s = 0;
    int e = size;
    int mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        if (e == s)
            break;
        if (c[mid].x > key)
            e = mid - 1;
        else
            s = mid;
    }
    if (c[mid].x > key)
        return -1;
    return mid;
}
void join(struct point pt[], int start, int mid, int end, int domidx[])
{
    int i;
    // for (i = 0; i < 4; i++)
    // {
    //     printf("%d ", domidx[i]);
    // }
    // printf("\n");
    int n1, n2, j, k;
    n1 = mid - start + 1;
    n2 = end - mid;
    struct point b[n1], c[n2];
    for (i = 0; i < n1; i++)
    {
        b[i] = pt[start + i];
        printf("%d", pt[start + i].x);
    }
    for (i = 0; i < n2; i++)
    {
        c[i] = pt[mid + 1 + i];
    }
    for (i = 0; i < n2; i++)
    {
        printf("%lf %lf \n", c[i].x, c[i].y);
    }
    printf("\n");
    // merge_sortx(b, 0, n1 - 1);
    merge_sortx(c, 0, n2 - 1);

    for (k = start; k <= mid; k++)
    {
        domidx[k] += BinarySearch(c, n2, b[k - start].x) + 1;
    }
}
void dom(struct point pt[], int start, int end, int domidx[])
{
    if (start == end)
        return;
    int mid = (start + end) / 2;
    dom(pt, mid + 1, end, domidx);
    dom(pt, start, mid, domidx);
    join(pt, start, mid, end, domidx);
}
int main()
{
    int n, i;
    printf("enter number of points: ");
    scanf("%d", &n);
    struct point pt[n];
    int domidx[n];
    for (i = 0; i < n; i++)
    {
        domidx[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &pt[i].x, &pt[i].y);
    }
    merge_sorty(pt, 0, n - 1);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%lf %lf\n", pt[i].x, pt[i].y);
    // }
    // printf("\n");
    dom(pt, 0, n - 1, domidx);
    // for (i = 0; i < n; i++)
    // {
    //     printf("%d ", domidx[i]);
    // }
    // printf("\n");
}