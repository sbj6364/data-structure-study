#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, d, m, i;
	scanf("%d", &n);

	int* p = (int*)malloc(n * sizeof(int));

	if (p == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i < n; i++) scanf("%d", &p[i]);
	
	scanf("%d", &d);

	m = n - d;
	p = (int*)realloc(p, m*sizeof(int));

	for (i = 0; i < m; i++) printf("%d\n", p[i]);

	free(p);
}