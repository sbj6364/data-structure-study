#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, cnt = 0;

	scanf("%d", &n);
	char* p = (char*)malloc((n+1) * sizeof(char));

	scanf("%s", p);
	for (i = 2; i < n; i++)
	{
		if (p[i - 2] == 'c' && p[i - 1] == 'a' && p[i] == 't')
			cnt++;
	}
	printf("%d\n", cnt);

	free(p);
	return 0;
}