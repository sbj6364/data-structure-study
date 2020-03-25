#include <stdio.h>
#include <string.h>

typedef struct st
{
	char maj[50];
	int num;
}st;

int main()
{
	st a[100], tmp;
	int n, i, j;

	scanf("%d", &n);
	getchar();
	for (i = 0; i < n; i++)
	{
		gets(a[i].maj);
		scanf("%d", &a[i].num);
		getchar();
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strcmp(a[j].maj, a[j + 1].maj) > 0)
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (strcmp(a[j].maj, a[j + 1].maj) == 0)
			{
				if (a[j].num > a[j + 1].num)
				{
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
			
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %d\n", a[i].maj, a[i].num);
	}
	return 0;
}
