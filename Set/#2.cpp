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
		if (n == 0)	return 1;
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
	void initialize()
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
		for (int i = 0; i < r - 1; i++)
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
	int member(int e)
	{
		if (n == 0)	return 0;

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
	int subset(struct List B)
	{
		if (n == 0)	return 1;
		Node* p = H->next;

		while (1)
		{
			if (B.member(p->elem))
			{
				if (p->next == NULL)
					return 1;
				else p = p->next;
			}
			else return 0;
		}
	}
}Set;

Set subtract(Set A, Set B)
{
	Set X;
	X.initialize();

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
			B.removeFirst();
		else
		{
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
		B.removeFirst();

	return X;
}

int main()
{
	int n, e;
	Set A, B;

	A.initialize();
	B.initialize();

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		A.addElem(e);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		B.addElem(e);
	}

	if (A.subset(B) == 1) printf("0");
	else printf("%d", subtract(A, B).get(1));

	return 0;
}
