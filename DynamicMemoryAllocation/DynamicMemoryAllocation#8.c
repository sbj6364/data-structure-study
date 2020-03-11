#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, tmp = 0;

	scanf("%d", &n);
	int* p = (int*)malloc(n * sizeof(int));

	scanf("%d", &p[0]);
	for (i = 1; i < n; i++)
	{
		scanf("%d", &p[i]);
		if (p[i] < p[i - 1])
		{
			tmp = p[i];
			p[i] = p[i - 1];
			p[i - 1] = tmp;
		}
	}
	for (i = 0; i < n; i++) printf("%d\n", p[i]);

	free(p);
	return 0;
}