#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i;
	float max = 0;
	scanf("%d", &n);

	float* p = (float*)malloc(n * sizeof(float));
	if (p == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i < n; i++)
	{
		scanf("%f", &p[i]);
		if (p[i] > max) max = p[i];
	}
	printf("%0.2f", max);

	free(p);
	return 0;
}