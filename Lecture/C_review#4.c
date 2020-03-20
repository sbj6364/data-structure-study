#include <stdio.h>
#include <string.h>

int main()
{
	char a[100];
	int i, j, n;
	char tmp;

	scanf("%s", a);
	n = strlen(a);

	printf("%s\n", a);
	for (i = 0; i < n-1; i++)
	{
		tmp = *a;
		for (j = 0; j < n-1; j++)
		{
			a[j] = a[j + 1];
		}		
		a[n-1] = tmp;
		printf("%s\n", a);
	}
}
