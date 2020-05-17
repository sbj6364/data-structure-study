#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	int a[100][100];
	int n;
	int i, j, ans = 0;
	scanf("%d", &n);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	j = 0;
	for (i = 0; i < n; i++)
	{
		while (j < n)
		{
			if (a[i][j] == 1)
			{
				ans = i;
				j++;
			}
			else break;
		}
	}
	printf("%d", ans);
	
	return 0;
}
