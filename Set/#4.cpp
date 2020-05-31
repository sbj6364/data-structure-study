#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

typedef struct Node
{
	int elem;
	struct Node* next;
}Node;

typedef struct List
{
	int n;

	Node* H = NULL;

	int isEmpty()
	{
		if (n == 0) return 1;
		else return 0;
	}
	int size()
	{
		return n;
	}
	int get(int r)
	{
		Node* p = H;
		for (int i = 0; i < r; i++)
			p = p->next;
		return p->elem;
	}
	void init()
	{
		H = (Node*)malloc(sizeof(Node));
		H->next = NULL;
		n = 0;
	}
	
	void addNodeAfter(Node* p, int e)
	{
		Node* q = (Node*)malloc(sizeof(Node));
		q->next = NULL;
		q->elem = e;

		q->next = p->next;
		p->next = q;
	}
	void add(int r, int e)
	{
		Node* p = H;
		for (int i = 0; i < r; i++)
			p = p->next;
		addNodeAfter(p, e);
		n++;
	}
	void addLast(int e)
	{
		Node* p = H;
		while (p->next != NULL)
			p = p->next;
		addNodeAfter(p, e);
		n++;
	}
	void addFirst(int e)
	{
		Node* p = H;
		addNodeAfter(p, e);
		n++;
	}
	void addElem(int e)
	{
		addLast(e);
	}
	int removeNode(Node* p)
	{
		Node* tmp = NULL;
		int e = (p->next)->elem;
		tmp = p->next;
		p->next = (p->next)->next;
		free(tmp);
		tmp = NULL;

		return e;
	}
	int remove(int r)
	{
		Node* p = H;
		for (int i = 0; i < r - 1; i++)
			p = p->next;
		int e = removeNode(p);
		n--;

		return e;
	}
	void removeLast()
	{
		remove(n);
	}
	void removeFirst()
	{
		remove(1);
	}
	void removeElem()
	{
		removeFirst();
	}
	void visit(int e)
	{
		printf(" %d", e);
	}
	void trav()
	{
		Node* p = H->next;
		while (p != NULL)
		{
			visit(p->elem);
			p = p->next;
		}
		printf("\n");
	}
	int member(int e)
	{
		if (n == 0) return 0;

		Node* p = H->next;
		while (1)
		{
			int a = p->elem;
			if (a < e)
			{
				if (p->next == NULL) return 0;
				else p = p->next;
			}
			else if (a > e) return 0;
			else return 1;
		}
	}
}Set;

Set uni(Set A, Set B)
{
	Set X;
	X.init();

	while (!A.isEmpty() && !B.isEmpty())
	{
		int a = A.get(1);
		int b = B.get(1);

		if (a < b)
		{
			X.addLast(a);
			A.removeFirst();
		}
		else if (a > b)
		{
			X.addLast(b);
			B.removeFirst();
		}
		else
		{
			X.addLast(a);
			A.removeFirst();
			B.removeFirst();
		}
	}
	while (!A.isEmpty())
	{
		int a = A.get(1);
		X.addLast(a);
		A.removeFirst();
	}
	while (!B.isEmpty())
	{
		int b = B.get(1);
		X.addLast(b);
		B.removeFirst();
	}
	return X;
}

Set intsec(Set A, Set B)
{
	Set X;
	X.init();

	while (!A.isEmpty() && !B.isEmpty())
	{
		int a = A.get(1);
		int b = B.get(1);

		if (a < b) A.removeFirst();
		else if (a > b)	B.removeFirst();
		else
		{
			X.addLast(a);
			A.removeFirst();
			B.removeFirst();
		}
	}
	while (!A.isEmpty()) A.removeFirst();
	while (!B.isEmpty()) B.removeFirst();

	return X;
}

int main()
{
	int n, e;
	Set A, a, B, b, C, c;

	A.init();
	a.init();
	B.init();
	b.init();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		A.addElem(e);
		a.addElem(e);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		B.addElem(e);
		b.addElem(e);
	}

	C = uni(A, B);
	if (C.isEmpty() == 1) printf(" 0\n");
	else C.trav();
	c = intsec(a, b);
	if (c.isEmpty() == 1) printf(" 0\n");
	else c.trav();

	return 0;
}
