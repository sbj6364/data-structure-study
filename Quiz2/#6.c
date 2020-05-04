#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode
{
	char elem;
	struct ListNode* prev;
	struct ListNode* next;
}LN;

typedef struct ListType
{
	int len;
	LN* h;
	LN* t;
}LT;

LT* initList(LT* L)
{
	L = (LT*)malloc(sizeof(LT));
	L->h = (LN*)malloc(sizeof(LN));
	L->t = (LN*)malloc(sizeof(LN));
	L->h->next = L->t;
	L->t->prev = L->h;

	L->len = 0;
	return L;
}

LN* trav(LT* L, int i)
{
	int j;
	LN* tmp;
	tmp = (LN*)malloc(sizeof(LN));
	tmp = L->h;
	for (j = 0; j < i - 1; j++)
		tmp = tmp->next;
	return tmp;
}

void add(LT* L, int p, char item)
{
	LN* node;
	LN* tmp;
	node = (LN*)malloc(sizeof(LN));

	if (L->len + 1 < p)
	{
		printf("invalid position\n");
		return;
	}
	node->elem = item;
	tmp = trav(L, p);
	node->prev = tmp;
	node->next = tmp->next;
	tmp->next->prev = node;
	tmp->next = node;
	L->len++;
}

void delete(LT* L, int p)
{
	LN* a;
	if (L->len < p)
	{
		printf("invalid position\n");
		return;
	}
	a = trav(L, p);
	a->next->next->prev = a;
	a->next = a->next->next;
	L->len--;
}
void get_entry(LT* L, int p)
{
	LN* a;
	if (L->len < p)
	{
		printf("invalid position\n");
		return;
	}
	a = trav(L, p);

	printf("%c\n", a->next->elem);
}
void print(LT* L)
{
	LN* tmp;
	tmp = L->h->next;
	while (tmp != L->t)
	{
		printf("%c ", tmp->elem);
		tmp = tmp->next;
	}
	printf("\n");
}

int main()
{
	LT* L = NULL;
	int n, i, pos;
	char com, data;
	scanf("%d", &n);

	L = initList(L);

	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &com);

		switch (com)
		{
		case 'A':
			scanf("%d %c", &pos, &data);
			add(L, pos, data);
			break;
		case 'D':
			scanf("%d", &pos);
			delete(L, pos);
			break;
		case 'G':
			scanf("%d", &pos);
			get_entry(L, pos);
			break;
		case 'P':
			print(L);
			break;
		}
	}
}
