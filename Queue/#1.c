#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Que
{
	int f;
	int r;
	int* Q;
}Que;

int isEmpty(Que* q, int n)
{
	return ((q->r + 1) % n == q->f);
}

int isFull(Que* q, int n)
{
	return ((q->r + 2) % n == q->f);
}

void initQue(Que* q, int n)
{
	q->Q = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) q->Q[i] = 0;
	q->f = 1;
	q->r = 0;
}

void fullQueueException(Que q, int n)
{
	printf("overflow");
}

void traverse(Que* q, int n)
{
	for (int i = 0; i < n; i++)
	{
		int e = q->Q[i];
		printf(" %d", e);
	}
	printf("\n");
}

int enqueue(Que* q, int n, int e)
{
	if (isFull(q, n))
	{
		fullQueueException(*q, n);
		traverse(q, n);
		return -1;
	}
	q->r = (q->r + 1) % n;
	q->Q[q->r] = e;
}

void emptyQueueException()
{
	printf("underflow\n");
}

int dequeue(Que* q, int n)
{
	if (isEmpty(q, n))
	{
		emptyQueueException();
		return -1;
	}
	int e = q->Q[q->f];
	q->Q[q->f] = 0;
	q->f = (q->f + 1) % n;
	return e;
}

int main()
{
	Que q;
	int num, n, e;
	char com;

	scanf("%d", &n);
	scanf("%d", &num);

	initQue(&q, n);

	for (int i = 0; i < num; i++)
	{
		getchar();
		scanf("%c", &com);

		switch (com)
		{
		case 'I':
			scanf("%d", &e);
			if (enqueue(&q, n, e) == -1) return 0;
			break;
		case 'D':
			if (dequeue(&q, n) == -1) return 0;
			break;
		case 'P':
			traverse(&q, n);
			break;
		}
	}
	return 0;
}
