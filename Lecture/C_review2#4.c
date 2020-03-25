#include <stdio.h>
#include <string.h>

typedef struct st
{
	char name[10];
	char book[5][20];
	int score[5];
	int cnt, pcnt;
}st;

int main()
{
	st a[100];
	int n, i, j;

	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%s", a[i].name);
		
		a[i].pcnt = 0;
		a[i].cnt = 0;
		j = 0;
		while (j<6)
		{
			
			scanf("%s", &a[i].book[j]);
			if (a[i].book[j][0] == '0') break;
			scanf("%d", &a[i].score[j]);
			if (a[i].score[j] >= 50) a[i].pcnt++;
			a[i].cnt++;
			j++;
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %d%%\n", a[i].name, a[i].pcnt*20);
	}
	return 0;
}
