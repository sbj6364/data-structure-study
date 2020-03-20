#include <stdio.h>

int ABC(int a[10], int k)
{
	int i, max = a[k], maxi = k;
	int tmp;
	for (i = k; i < 10; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
			maxi = i;
		}
	}
	tmp = a[k];
	a[k] = max;
	a[maxi] = tmp;
}
	
int main()	
{
	int a[10], i;

	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);

	for (i = 0; i < 10; i++)
		ABC(a, i);

	for (i = 0; i < 10; i++)
		printf(" %d", a[i]);

	return 0;
}
