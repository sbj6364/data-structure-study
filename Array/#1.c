#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int* x;
	int n, m, i, j, k = 0, tmp;
	int a, b;

	scanf("%d", &n);
	x = (int*)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", x + i);
	
	scanf("%d", &m);

	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b);
		for (j = a; j <= (a + b) / 2; j++, k++)
		{
			tmp = x[j];
			x[j] = x[b - k];
			x[b - k] = tmp;
		}
		k = 0;
	}
	for (i = 0; i < n; i++)
		printf(" %d", *(x + i));

	return 0;
}
