#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int id;
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
}Node;

void visit(Node* v)
{
	printf(" %d", v->id);
}

int isInternal(Node* v)
{
	return ((v->left != NULL) && (v->right != NULL));
}

Node* L_Child(Node* v)
{
	return v->left;
}

Node* R_Child(Node* v)
{
	return v->right;
}

void binaryPreOrder(Node* v)
{
	if (v != NULL)
	{
		visit(v);
		binaryPreOrder(L_Child(v));
		binaryPreOrder(R_Child(v));
	}
}
void binaryPostOrder(Node* v)
{
	if (v != NULL)
	{
		binaryPreOrder(L_Child(v));
		binaryPreOrder(R_Child(v));
		visit(v);
	}
}
void binaryInOrder(Node* v)
{
	if (v != NULL)
	{
		binaryPreOrder(L_Child(v));
		visit(v);
		binaryPreOrder(R_Child(v));
	}
}

Node* findID(Node* v, int id)
{
	if (v != NULL)
	{
		if (v->id == id) return v;

		Node* p = NULL;
		p = findID(L_Child(v), id);
		if (p != NULL) return p;
		p = findID(R_Child(v), id);
		if (p != NULL) return p;
	}
	return NULL;
}

void insertNode(Node* v, char type, int id)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	newNode->id = id;
	newNode->right = NULL;
	newNode->left = NULL;

	if (type == 'L') v->left = newNode;
	else if (type == 'R') v->right = newNode;
	else printf("Invalid!\n");
}

Node* TreeBuild()
{
	Node* root = (Node*)malloc(sizeof(Node));

	int n;
	int id;
	int l_id;
	int r_id;
	int flag = 1;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d", &id, &l_id, &r_id);

		if (flag == 1)
		{
			root->id = id;
			if (l_id != 0) insertNode(root, 'L', l_id);
			if (r_id != 0) insertNode(root, 'R', r_id);
			flag = 0;
		}
		else
		{
			Node* v = findID(root, id);
			if (l_id != 0) insertNode(v, 'L', l_id);
			if (r_id != 0) insertNode(v, 'R', r_id);
		}
	}
	return root;
}

void TreeSearch(Node* R)
{
	int n;
	scanf("%d", &n);
	char str[100] = { 0 };

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		Node* v = R;
		printf(" %d", v->id);

		for (int j = 0; j < strlen(str); j++)
		{
			if (str[j] == 'L') v = L_Child(v);
			else if (str[j] == 'R') v = R_Child(v);
			printf(" %d", v->id);
		}
		printf("\n");
	}
}


int main()
{
	Node* root = (Node*)malloc(sizeof(Node));
	root = TreeBuild();
	TreeSearch(root);

	return 0;
}
