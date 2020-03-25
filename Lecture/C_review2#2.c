#include <stdio.h>
#include <string.h>

int main(void)
{
	char a[100], b[100];
	int i, N, len, cnt = 1;

	gets(a);
	scanf("%d", &N);

	len = strlen(a);
	
	
	for (i = 0; i<len; i++)
	{
		if (a[i] == ' ') a[i] = NULL;
	}
	for (i = 0; i < len; i++)
	{
		if (cnt == N)
		{
			strcpy(b, a + i);
			break;
		}
		if (a[i] == NULL) cnt++;
	}
	printf("%s", b);

	return 0;
}
