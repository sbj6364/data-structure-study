#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
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
	if (s->top == -1) printf("Stack Empty\n");
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
	int N, i, j, n;
	char com[6], elem;
	char comkind[][6] = { "POP", "PUSH" , "PEEK", "DUP", "UpR", "DownR", "PRINT" };

	scanf("%d", &A.size);
	scanf("%d", &N);

	A.st = (char*)malloc(sizeof(char) * A.size);

	for (i = 0; i < N; i++)
	{
		scanf("%s", com);
		
		for (j = 0; j < 7; j++)
			if (strcmp(com, comkind[j]) == 0) break;
		
		switch (j)
		{
		case 0:
			pop(&A);
			break;
		case 1:
			getchar();
			scanf("%c", &elem);
			push(&A, elem);
			break;
		case 2:
			peek(&A);
			break;
		case 3:
			duplicate(&A);
			break;
		case 4:
			scanf("%d", &n);
			upRotate(&A, n);
			break;
		case 5:
			scanf("%d", &n);
			downRotate(&A, n);
			break;
		case 6:
			print(&A);
			break;
		default:
			break;
		}
	}
	return 0;
}
