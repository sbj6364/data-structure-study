#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct treeNode
{
	int data;
	int id;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* insertNode(int id, int data, treeNode* left, treeNode* right)
{
	treeNode* newNode = (treeNode*)malloc(sizeof(treeNode));

	newNode->id = id;
	newNode->data = data;
	newNode->left = left;
	newNode->right = right;

	return newNode;
}

treeNode* treeBuild()
{
	treeNode* n7 = insertNode(7, 130, NULL, NULL);
	treeNode* n8 = insertNode(8, 80, NULL, NULL);
	treeNode* n6 = insertNode(6, 120, n7, n8);

	treeNode* n4 = insertNode(4, 70, NULL, NULL);
	treeNode* n5 = insertNode(5, 90,  NULL, NULL);
	
	treeNode* n2 = insertNode(2, 30, n4, n5);
	treeNode* n3 = insertNode(3, 50, NULL, n6);

	treeNode* n1 = insertNode(1, 20, n2, n3);

	return n1;
}

void visit(treeNode* v)
{
	printf("%d ", v->data);
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

void binaryPreOrder(treeNode* v, int n)
{
	if (v->id == n)
	{
		visit(v);
		if (v->left != NULL)	visit(v->left);
		if (v->right != NULL)	visit(v->right);
		return;
	}
	if (isInternal(v))
	{
		if (v->left != NULL)
			binaryPreOrder(leftChild(v), n);
		if (v->right != NULL)
			binaryPreOrder(rightChild(v), n);
	}
}


/*
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
*/

int main()
{
	int n;
	treeNode* root = treeBuild();

	scanf("%d", &n);

	if (n < 1 || n > 8)
	{
		printf("-1");
		return 0;
	}

	binaryPreOrder(root, n);

	return 0;
}
