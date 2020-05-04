#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct rank
{
	int data;
	int rank;
}rk;

int main()
{
	int n, i, j;
	rk x[100];
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &x[i].data);
		x[i].rank = 0;
	}
		
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (x[i].data > x[j].data) x[i].rank++;
		}
		printf("%d ", x[i].rank);
	}
	return 0;
}
