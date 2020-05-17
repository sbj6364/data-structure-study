#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main()
{
	char a[21];
	int i, len, cnt = 1, num = 0;
	scanf("%s", a);
	len = strlen(a);

	for (i = len - 1; i >= 0; i--)
	{
		if (a[i] >= '0' && a[i] <= '9')
		{
			num += (a[i] - '0') * cnt;
			cnt*=10;
		}
	}

	for (i = 1; i <= num; i++)
	{
		if (num % i == 0)
			printf("%d ", i);
	}
	return 0;
}
