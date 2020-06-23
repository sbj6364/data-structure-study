#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* next;
	int elem;
}node;

typedef struct Stack
{
	node* top;
}stack;

void init(stack* s)
{
	s->top = NULL;
}

struct node* getnode()
{
	node* p = (node*)malloc(sizeof(node));
	p->elem = -1;
	p->next = NULL;
	return p;
}

void push(stack* st, int e)
{
	node* p = getnode();
	p->elem = e;
	p->next = st->top;
	st->top = p;
}

int isEmpty(stack* st)
{
	return (st->top == NULL);
}

void emptyStackException()
{
	printf("StackException\n");
}

void putnode(node* p)
{
	free(p);
	p = NULL;
}

int pop(stack* st)
{
	if (isEmpty(st))
	{
		emptyStackException();
		return -1;
	}
	int e = (st->top)->elem;
	node* tmp = st->top;
	st->top = (st->top)->next;
	putnode(tmp);

	return e;
}

void traverse(stack* st)
{
	node* p = st->top;
	while (p != NULL)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	printf("\n");
}

int isOperand(char elem)
{
	if (elem >= 'A' && elem <= 'Z')
	{
		return 1;
	}
	return 0;
}

int strfind(char* str, char elem)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == elem)
		{
			return i;
		}
	}
	return 0;
}

int getPrior(char elem)
{
	char Prior[12] = { '(', '|', '&', '>', '<', '+', '-', '*', '/', '!', '#' };
	char Prior_N[12] = { 0, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6 };

	return Prior_N[strfind(Prior, elem)];
}

char top(stack* st)
{
	if (st->top == NULL)
	{
		emptyStackException();
		return -1;
	}
	return st->top->elem;
}

void write(char st)
{
	if (st == '&' || st == '|')
	{
		printf("%c%c", st, st);
	}
	else if (st == '#')
	{
		printf("-");
	}
	else
	{
		printf("%c", st);
	}
}

void convert(char* infix_array)
{
	stack S;
	init(&S);

	int N = strlen(infix_array);
	int idx = 0;

	while (idx != N)
	{
		char s = infix_array[idx++];
		if (s == '&' || s == '|')
		{
			idx++;
		}
		if (s == '-')
		{
			if (infix_array[idx - 2] == '|' || infix_array[idx - 2] == '&' || infix_array[idx - 2] == '>'
				|| infix_array[idx - 2] == '<' || infix_array[idx - 2] == '+' || infix_array[idx - 2] == '-'
				|| infix_array[idx - 2] == '*' || infix_array[idx - 2] == '/' || infix_array[idx - 2] == '!'
				|| idx == 1)
			{
				s = '#';
			}
		}
		if (isOperand(s))
		{
			write(s);
		}
		else if (s == '(')
		{
			push(&S, s);
		}
		else if (s == ')')
		{
			while (top(&S) != '(')
			{
				write(pop(&S));
			}
			pop(&S);
		}
		else
		{
			while (!isEmpty(&S) && (getPrior(s) <= getPrior(top(&S))))
			{
				write(pop(&S));
			}
			push(&S, s);
		}
	}
	while (!isEmpty(&S))
	{
		write(pop(&S));
	}
}

int main()
{
	char A[100];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", A);
		convert(A);
		printf("\n");
	}

	return 0;
}
