#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, sum = 0;
	int* score = NULL;
	scanf("%d", &n);

	score = (int*)malloc(n * sizeof(int));
	
	if (score == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}

	for (i = 0; i < n; i++)
	{
		scanf("%d", score + i);
		sum += *(score + i);
	}
	printf("%d", sum / n);

	return 0;
}
