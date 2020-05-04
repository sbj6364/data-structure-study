#include <stdio.h>

int main()
{
	int A[100][100] = { 0 };
	int num = 1, n = 0, m = 0, i = 0, j = 0, p = 0, q = 0;
	scanf("%d %d", &n, &m);

	while (1)
	{
		for (i = 0; i <= j; i++)
		{
			if (i >= n || (j - i) >= m) continue;
			else
			{
				A[i][j - i] = num;
				num++;
			}
		}
		j++;
		if (j > (n + m) - 2) break;
	}
	for (p = 0; p < n; p++)
	{
		for (q = 0; q < m; q++)
			printf(" %d", A[p][q]);
		printf("\n");
	}
	return 0;
}
