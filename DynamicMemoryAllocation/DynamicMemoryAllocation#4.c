#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p;
	int size = 3;
	int num, i, index = 0;

	p = (int*)calloc(size, sizeof(int));

	if (p == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &num);
		if (index < size) p[index++] = num;
		else
		{
			size += 3;
			p = (int*)realloc(p, size * sizeof(int));
			p[index++] = num;
		}
	}
	free(p);

	return 0;
}