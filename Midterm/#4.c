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
	LN* head;
	LN* tail;
}LT;

LT* init(LT* L, int n)
{
	L = (LT*)malloc(n * sizeof(LT));
	L->head = (LN*)malloc(sizeof(LN));
	L->tail = (LN*)malloc(sizeof(LN));

	L->head->next = L->tail;
	L->tail->prev = L->head;
	return L;
}

LN* trav(LT* L, int pos)
{
	int i;
	LN* pre = (LN*)malloc(sizeof(LN));
	pre = L->head;
	for (i = 0; i < pos - 1; i++)
		pre = pre->next;
	return pre;
}

void add(LT* L, int pos, char item)
{
	int i;
	if (L->len + 1 < pos || pos < 0)
	{
		printf("invalid position\n");
		return;
	}
	LN* node = (LN*)malloc(sizeof(LN));
	LN* pre = (LN*)malloc(sizeof(LN));

	pre = trav(L, pos);

	node->elem = item;

	node->next = pre->next;
	node->prev = pre;
	pre->next->prev = node;
	pre->next = node;
	L->len++;
}

void del(LT* L, int pos)
{
	if (L->len < pos || pos < 0)
	{
		printf("invalid position\n");
		return;
	}
	LN* node = (LN*)malloc(sizeof(LN));
	LN* pre = (LN*)malloc(sizeof(LN));

	pre = trav(L, pos);

	node = pre->next;
	pre->next = node->next;
	node->next->prev = pre;
	free(node);
	L->len--;
}
void get_entry(LT* L, int pos)
{
	if (L->len < pos || pos < 0)
	{
		printf("invalid position\n");
		return;
	}
	LN* pre = (LN*)malloc(sizeof(LN));
	pre = trav(L, pos);
	printf("%c\n", pre->next->elem);
}
void print(LT* L)
{
	int i;
	LN* pre = (LN*)malloc(sizeof(LN));
	pre = L->head->next;
	for (i = 0; i < L->len; i++)
	{
		printf("%c", pre->elem);
		pre = pre->next;
	}
	printf("\n");
}
int main()
{
	LN* pre = (LN*)malloc(sizeof(LN));
	LT* A = NULL;
	int n, i, tmp, pos;
	char com, data;
	scanf("%d", &n);

	A = init(A, n);

	pre = A->head;
	A->len = 0;
	for (i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &com);
		switch (com)
		{
		case 'A':
			scanf("%d %c", &pos, &data);
			add(A, pos, data);
			break;
		case 'D':
			scanf("%d", &pos);
			del(A, pos);
			break;
		case 'G':
			scanf("%d", &pos);
			get_entry(A, pos);
			break;
		case 'P':
			print(A);
			break;
		}
	}
	return 0;
}
