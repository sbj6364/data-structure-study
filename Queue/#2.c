#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{
	int elem;
	struct node* prev;
	struct node* next;
}node;

typedef struct deque
{
	struct node* r;
	struct node* f;
}deque;

void initDeque(deque* q)
{
	q->r = NULL;
	q->f = NULL;
}

int isEmpty(deque* q)
{
	return (q->f == NULL);
}

struct node* getnode()
{
	struct node* p = (node*)malloc(sizeof(node));
	p->elem = -1;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

void putnode(node* p)
{
	free(p);
	p = NULL;
}

void add_front(deque* q, int x)
{
	node* p = getnode();

	p->elem = x;
	p->prev = NULL;
	p->next = NULL;

	if (isEmpty(q))
	{
		q->f = p;
		q->r = p;
	}
	else
	{
		p->next = q->f;
		q->f->prev = p;
		q->f = p;
	}
}

void add_rear(deque* q, int x)
{
	node* p = getnode();

	p->elem = x;
	p->prev = NULL;
	p->next = NULL;

	if (isEmpty(q))
	{
		q->f = p;
		q->r = p;
	}
	else
	{
		p->prev = q->r;
		q->r->next = p;
		q->r = p;
	}
}

void emptyQueueException()
{
	printf("underflow\n");
}

int delete_front(deque* q)
{
	int e;

	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}
	e = q->f->elem;
	node* p = q->f;
	q->f = q->f->next;

	if (q->f == NULL) q->r = NULL;
	else q->f->prev = NULL;

	putnode(p);
	return e;
}

int delete_rear(deque* q)
{
	int e;

	if (isEmpty(q))
	{
		emptyQueueException();
		return -1;
	}
	e = q->r->elem;
	node* p = q->r;
	q->r = q->r->prev;

	if (q->r == NULL) q->f = NULL;
	else q->r->next = NULL;

	putnode(p);
	return e;
}

void traverse(deque* q)
{
	node* p = q->f;
	while (p != NULL)
	{
		printf(" %d", p->elem);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	deque q;
	int n, e;
	char com;
	initDeque(&q);

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c", &com);

		switch (com)
		{
		case 'A':
			scanf("%c", &com);
			switch (com)
			{
			case 'F':
				scanf("%d", &e);
				add_front(&q, e);
				break;
			case 'R':
				scanf("%d", &e);
				add_rear(&q, e);
				break;
			}
			break;
		case'D':
			scanf("%c", &com);
			switch (com)
			{
			case'F':
				if (delete_front(&q) == -1) return 0;
				break;
			case 'R':
				if (delete_rear(&q) == -1) return 0;
				break;
			}
			break;
		case 'P':
			traverse(&q);
			break;
		}
	}
	return 0;
}
