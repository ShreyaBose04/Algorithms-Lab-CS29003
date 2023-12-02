#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100
typedef struct
{
    char element[MAXLEN];
    int top;
} stack;
stack init()
{
    stack S;
    S.top = -1;
    return S;
}
int isEmpty(stack S)
{
    return (S.top == -1);
}
int isFull(stack S)
{
    return (S.top == MAXLEN - 1);
}
char top(stack S)
{
    if (isEmpty(S))
    {
        printf("top: Empty stack\n");
        return '\0';
    }
    return S.element[S.top];
}
stack push(stack S, char ch)
{
    if (isFull(S))
    {
        printf("push: Full stack\n");
        return S;
    }
    ++S.top;
    S.element[S.top] = ch;
    return S;
}
stack pop(stack S)
{
    if (isEmpty(S))
    {
        printf("pop: Empty stack");
        return S;
    }
    --S.top;
    return S;
}
void print(stack S)
{
    int i;
    for (i = 0; i <= S.top; i++)
        printf("%c", S.element[i]);
}
int main()
{
    int n, i, min = 26;
    printf("enter length of string: ");
    scanf("%d", &n);
    stack r, p;
    char s[n];
    r = init();
    p = init();
    printf("enter string: ");
    scanf("%s", s);
    for (i = 0; i < n; i++)
    {
        if ((s[i] - 'a') < min)
        {
            min = s[i] - 'a';
        }
    }
    i = 0;
    while (i < n && (s[i] - 'a') != min)
    {
        r = push(r, s[i]);
        i++;
    }
    p = push(p, s[i]);
    i++;
    while (i < n && isEmpty(r) == 0)
    {
        if ((s[i] - 'a') <= (top(r) - 'a'))
        {
            p = push(p, s[i]);
            i++;
        }
        else
        {
            p = push(p, top(r));
            r = pop(r);
        }
    }
    if (i < n)
    {
        while (i < n)
        {
            p = push(p, s[i]);
            i++;
        }
    }
    else
    {
        while (isEmpty(r) == 0)
        {
            p = push(p, top(r));
            r = pop(r);
        }
    }
    printf("output: ");
    print(p);
    printf("\n");
}