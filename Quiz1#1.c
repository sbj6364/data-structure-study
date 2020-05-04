#include <stdio.h>
#include <string.h>

void del(char *p)
{
	int i = 0, j = 0;
	int len = strlen(p);
	for (i = 0; i < len; i++)
		if (p[i] == ' ')
		{
			for (j = i; j < len; j++)
				p[j] = p[j + 1];
			i--;
			len--;
		}
}

int main()
{
	char x[200];
	int i = 0;
	gets(x);
	del(x);
	printf("%s", x);

	return 0;
}
