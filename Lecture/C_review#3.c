#include <stdio.h>

int swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int n, i, x, y;
	int* a;

	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	scanf("%d %d", &x, &y);
	swap(a + x, a + y);

	for (i = 0; i < n; i++)
		printf(" %d", a[i]);
	
	return 0;
}
