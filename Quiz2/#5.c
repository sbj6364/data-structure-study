#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n = 0;

typedef struct Node
{
	int coef;
	int exp;
	struct Node* next;
}Node;

Node* getnode()
{
	Node* tmp;
	tmp = (Node*)malloc(sizeof(Node));
	tmp->coef = 0;
	tmp->exp = 0;
	tmp->next = NULL;
	return tmp;
}

Node* Head1, * Head2;
void initList()
{
	Head1 = getnode();
	Head2 = getnode();
}

Node* AT(Node* k, int c, int e)
{
	Node* temp;
	temp = getnode();
	temp->coef = c;
	temp->exp = e;
	temp->next = NULL;
	k->next = temp;
	return k->next;
}

Node* AP(Node* x, Node* y)
{
	int sum = 0;
	Node* result = NULL;
	Node* i, * j, * k;
	result = getnode();
	i = x->next;
	j = y->next;
	k = result;
	
	while ((i != NULL) && (j != NULL))
	{
		if (i->exp > j->exp)
		{
			k = AT(k, i->coef, i->exp);
			i = i->next;
		}
		else if (i->exp < j->exp)
		{
			k = AT(k, j->coef, j->exp);
			j = j->next;
		}
		else
		{
			sum = (i->coef) + (j->coef);
			if (sum != 0) k = AT(k, sum, i->exp);
			i = i->next;
			j = j->next;
		}
	}
	while (i != NULL)
	{
		k = AT(k, i->coef, i->exp);
		i = i->next;
	}
	while (j != NULL)
	{
		k = AT(k, j->coef, j->exp);
		j = j->next;
	}
	return result;
}

int main()
{
	int x = 0, y = 0, cnt = 0;
	int i = 0;
	Node* result, * k;
	initList();
	for (i = 0; i < 2; i++)
	{
		cnt = 0;
		scanf("%d", &n);
		if (i == 0) k = Head1;
		else k = Head2;
		while (cnt < n)
		{
			scanf("%d", &x);
			scanf("%d", &y);
			k = AT(k, x, y);
			cnt++;
		}
	}
	result = AP(Head1, Head2);

	k = result->next;
	while (k != NULL)
	{
		printf(" %d %d", k->coef, k->exp);
		k = k->next;
	}
	return 0;
}
