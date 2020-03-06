#include <stdio.h>

void dig(int n)
{
	if (n == 0) return;
	
	else dig(n / 10);
	
	printf("%d\n", n % 10);
}

int main()
{
	int n;
	scanf("%d", &n);
	dig(n);

	return 0;
}
