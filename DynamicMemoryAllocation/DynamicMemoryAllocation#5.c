#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, sum = 0;
	scanf("%d", &n);

	int* p = (int*)malloc(n * sizeof(int));

	if (p == NULL)
	{
		printf("Not Enough Memory!");
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		sum += p[i];
	}
	printf("%d", sum);

	free(p);
	return 0;
}