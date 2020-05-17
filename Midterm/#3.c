#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ListNode
{
	int elem;
	struct ListNode* next;
}LN;

void add(LN* H, int e)
{
	LN* p = H;
	LN* q = (LN*)malloc(sizeof(LN));
	q->next = NULL;
	q->elem = e;

	while (p->next != NULL)
		p = p->next;
	p->next = q;
}
int main()
{
	int n, i, j, e, tmp;
	LN* H = (LN*)malloc(sizeof(LN));
	LN* p;
	H->next = NULL;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &e);
		add(H, e);
	}
	
	for (i = 0; i < n - 1; i++)
	{
		p = H->next;
		for (j = 0; j < n - 1; j++)
		{
			if (p->elem > p->next->elem)
			{
				tmp = p->elem;
				p->elem = p->next->elem;
				p->next->elem = tmp;
			}
			p = p->next;
		}
	}
	p = H->next;
	for (i = 0; i < n; i++)
	{
		printf("%d ", p->elem);
		p = p->next;
	}
	return 0;
}
