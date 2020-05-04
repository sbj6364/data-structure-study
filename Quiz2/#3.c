#include <stdio.h>

int main()
{
	int A[100][100] = { 0 };
	int n = 0, m = 0;
	int i = 0, j = 0, k = 0, l = 0, h = 0;
	int p = 0, q = 0;
	int cnt = 0, num = 1;

	scanf("%d %d", &n, &m);
	k = n - 1;
	l = m;
	while (1)
	{
		for (h = 0; h < l; h++)
		{
			A[i][j] = num;
			if (h == l - 1)
			{
				if (cnt % 2 == 0) i++;
				else i--;
			}
			else
			{
				if (cnt % 2 == 0) j++;
				else j--;
			}
			num++;
		}
		if (k == 0) break;
		for (h = 0; h < k; h++)
		{
			A[i][j] = num;
			if (h == k - 1)
			{
				if (cnt % 2 != 0) j++;
				else j--;
			}
			else
			{
				if (cnt % 2 == 0) i++;
				else i--;
			}
			num++;
		}
		k--; l--; cnt++;
		if (l == 0) break;
	}
	for (p = 0; p < n; p++)
	{
		for (q = 0; q < m; q++)
			printf(" %d", A[p][q]);
		printf("\n");
	}
	return 0;
}
