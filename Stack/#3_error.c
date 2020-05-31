#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct Stack
{
    char exp[101];
    int top;
}stack;


/*void init(stack st)
{
    int i;
    for (i = 0; i < 101; i++)
        st.exp[i] = NULL;
}*/


void push(stack* st, char elem)
{
    st->top++;
    st->exp[st->top] = elem;
}

char pop(stack* st)
{
    char tmp;
    tmp = st->exp[st->top];
    st->top--;
    return tmp;
}

char peek(stack* st)
{
    return st->exp[st->top];
}

int com(char operation)
{
    switch (operation)
    {
    case '|': return 1;
    case '&': return 2;
    case '<': case'>': return 3;
    case '+': case'-': return 4;
    case '/': case'*': return 5;
    case '!': return 6;
    }
}


int main()
{
    stack A, B;

    int n, i, j;
    A.exp[101] = NULL;
    B.exp[101] = NULL;
    A.top = -1;
    B.top = -1;
    char tmp = NULL;

    scanf("%d", &n);
    getchar();

    for (i = 0; i < n; i++)
    {
        
        scanf("%s", A.exp);
      
        A.top = strlen(A.exp);
        //printf("strlen is %d\n", A.top);
        for (j = 0; j < A.top; j++)
        {
            if (A.exp[j] >= 'A' && A.exp[j] <= 'Z')
                printf("%c", A.exp[j]);
            else if (A.exp[j] == '(')
                push(&B, A.exp[j]);
            else if (A.exp[j] == ')')
            {
                while (peek(&B) != '(')
                    printf("%c", pop(&B));
                pop(&B);
            }
            else
            {
                while (B.top > -1 && com(A.exp[j]) <= com(peek(&B)))
                {
                    tmp = pop(&B);
                    printf("%c", tmp);
                }
                if (tmp == '&' || tmp == '|')
                {
                    printf("%c", tmp);
                    j++;
                    tmp = NULL;
                    continue;
                }
                push(&B, A.exp[j]);

            }
        }
        while (B.top > -1)
            printf("%c", pop(&B));

        printf("\n");
    }
    return 0;
}
