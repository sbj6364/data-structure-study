#include <stdio.h>

int sum(int n)
{
	if (n == 0) 
		return 0;
	int a = 0, i;
	for (i = 1; i <= n; i++)
		a += i;
	return a;
}

int main()
{
	int n, i, s = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
		s += sum(i);

	printf("%d", s);
	return 0;
}
