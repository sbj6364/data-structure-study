#include <stdio.h>

int main()
{
	int n, answer = 0;
	int i, j;
	int A[100][100];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	j = 0;
	
	for (i = 0; i < n; i++)
	{
		while (j < n)
		{
			if (A[i][j] == 1)
			{
				answer = i;
				j++;
			}
			else break;
		}
	}

	printf("%d", answer);

	return 0;
}
