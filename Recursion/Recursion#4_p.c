#include <stdio.h>

int max(int* p, int i, int m)
{
	int mx;
	if (i == 0) return m;
	else
	{
		mx = max(p, i - 1, m);
		if (p[i] > mx)
			return p[i];
		else return mx;

	}
}

int main()
{
	int n, i, a[20];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);
	printf("%d", max(a, n - 1, a[0]));
	return 0;
}
