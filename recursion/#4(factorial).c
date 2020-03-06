#include <stdio.h>

int fac(int n)
{
	if (n == 0) return 1;
	else
	{
		return n * fac(n - 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d", fac(n));

	return 0;
}
