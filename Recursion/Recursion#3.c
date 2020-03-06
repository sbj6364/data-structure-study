#include <stdio.h>

void dig(int n)
{
	if (n == 0) return;
	
	else printf("%d\n", n % 10);

	dig(n / 10);
}

int main()
{
	int n;
	scanf("%d", &n);
	dig(n);

	return 0;
}
