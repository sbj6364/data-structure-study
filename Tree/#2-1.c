#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treeNode
{
	int id;
	int data;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* insertNode(int id, int data, treeNode* left, treeNode* right)
{
	treeNode* v = (treeNode*)malloc(sizeof(treeNode));

	v->id = id;
	v->data = data;
	v->left = left;
	v->right = right;

	return v;
}

treeNode* treeBuild()
{
	treeNode* n7 = insertNode(7, 130, NULL, NULL);
	treeNode* n8 = insertNode(8, 80, NULL, NULL);
	treeNode* n6 = insertNode(6, 120, n7, n8);
	treeNode* n4 = insertNode(4, 70, NULL, NULL);
	treeNode* n5 = insertNode(5, 90, NULL, NULL);
	treeNode* n2 = insertNode(2, 30, n4, n5);
	treeNode* n3 = insertNode(3, 50, NULL, n6);
	treeNode* n1 = insertNode(1, 20, n2, n3);

	return n1;
}

void visit(treeNode* v)
{
	printf(" %d", v->data);
}

int isInternal(treeNode* v)
{
	if ((v->left == NULL) && (v->right == NULL))
		return 0;
	else
		return 1;
}

treeNode* leftChild(treeNode* v)
{
	return v->left;
}

treeNode* rightChild(treeNode* v)
{
	return v->right;
}

void binaryPreOrder(treeNode* v)
{
	if (v != NULL)
	{
		visit(v);
		binaryPreOrder(leftChild(v));
		binaryPreOrder(rightChild(v));
	}
}

void binaryPostOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryPostOrder(leftChild(v));
		binaryPostOrder(rightChild(v));
		visit(v);
	}
}

void binaryInOrder(treeNode* v)
{
	if (v != NULL)
	{
		binaryInOrder(leftChild(v));
		visit(v);
		binaryInOrder(rightChild(v));
	}
}

treeNode* findId(treeNode* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id)
			return v;

		treeNode* p = NULL;

		p = findId(leftChild(v), id);
		
		if (p != NULL)
			return p;
		
		p = findId(rightChild(v), id);
		
		if (p != NULL)
			return p;
	}
	return NULL;
}

int main()
{
	treeNode* root = treeBuild();

	int type, id;
	scanf("%d %d", &type, &id);

	treeNode* p = (findId(root, id));

	if (p != NULL)
	{
		if (type == 1)
			binaryPreOrder(p);
		else if (type == 2)
			binaryInOrder(p);
		else if (type == 3)
			binaryPostOrder(p);
	}
	else printf("-1");

	printf("\n");

	return 0;
}
