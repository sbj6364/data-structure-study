#include <stdio.h>

int binary(int n)
{
	if (n < 2)
		printf("%d", n);
	else
	{
		binary(n / 2);
		printf("%d", n % 2);
	}
}
int main()
{
	int a;
	scanf("%d", &a);
	binary(a);
	
	return 0;
}
