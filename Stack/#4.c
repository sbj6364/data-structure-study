#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    int st[100];
    int top;
}stack;


void push(stack* st, int elem)
{

    if (st->top == 99) puts("Stack FULL");
    else st->st[++(st->top)] = elem;
}

char pop(stack* st)
{

    if (st->top == -1) puts("Stack Empty");
    return st->top == -1 ? -1 : st->st[(st->top)--];
}

int com(char operation, int a, int b)
{
    switch (operation)
    {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: break;
    }
}

int com_eq(char equation[])
{
    int a, b;
    stack A = { {0, }, -1 };
    char* ch;

    for (ch = equation; *ch; ++ch)
    {
        if (*ch >= '0' && *ch <= '9')
            push(&A, *ch - '0');
        else
        {
            a = pop(&A);
            b = pop(&A);
            push(&A, com(*ch, b, a));
        }
    }
    return pop(&A);
}
int main()
{
    int n;
    char eq[101];

    scanf("%d\n", &n);

    for (int i = 0; i < n; ++i)
    {
        gets(eq);
        printf("%d\n", com_eq(eq));
    }
    return 0;
}
