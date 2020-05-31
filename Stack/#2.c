#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack
{
    char* st;
    int top;
    int size;
}stack;

void push(stack* s, char elem)
{
    if (s->top == s->size - 1) printf("Stack FULL\n");
    else s->st[++(s->top)] = elem;
}

char pop(stack* s)
{
    if (s->top == -1) /*printf("Stack Empty\n")*/;
    else return s->st[(s->top)--];
}

void peek(stack* s)
{
    if (s->top == -1) printf("Stack Empty\n");
    else printf("%c\n", s->st[s->top]);
}

char duplicate(stack* s)
{
    char tmp = pop(s);
    push(s, tmp);
    push(s, tmp);
}

void upRotate(stack* s, int n)
{
    int i;
    char tmp = s->st[s->top];
    if (n > s->top + 1) return;
    for (i = 0; i < n - 1; i++)
        s->st[s->top - i] = s->st[s->top - 1 - i];
    s->st[s->top - i] = tmp;
}

void downRotate(stack* s, int n)
{
    int i;
    char tmp = s->st[s->top - n + 1];
    if (n > s->top + 1) return;
    for (i = 0; i < n - 1; i++)
        s->st[s->top - n + 1 + i] = s->st[s->top - n + 2 + i];
    s->st[s->top] = tmp;
}

void print(stack* s)
{
    int i;
    for (i = s->top; i > -1; i--)
        printf("%c", s->st[i]);
    printf("\n");
}

int main()
{
    stack A = { 0, -1 };
    int cnt = 0, i, j;
    int check = 0;
    char exp[1001];
    
    A.st = (char*)malloc(sizeof(char) * 1001);
    A.size = 1001;

    gets(exp);

    for (i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == '[' || exp[i] == '{' || exp[i] == '(')
        {
            push(&A, exp[i]);
            cnt++;
        }
        else switch (exp[i])
        {
        case ']':
            if (pop(&A) != '[') check = 1;
            cnt++;
            break;
        case '}':
            if (pop(&A) != '{') check = 1;
            cnt++;
            break;
        case ')':
            if (pop(&A) != '(') check = 1;
            cnt++;
            break;
        default:
            break;
        }
    }
    if (A.top > -1) check = 1;

    if (check == 1) printf("Wrong_%d", cnt);
    else printf("OK_%d", cnt);

    return 0;
}
