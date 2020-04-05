#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct
{
	int stn;
	int sc1;
	int sc2;
	float total;
	int r;
}st;

int main()
{
	int n;
	int i, j, cnt = 0, pcnt = 0;
	st tmp;
	scanf("%d", &n);

	st* a = NULL;
	st* pass = NULL;
	a = (st*)malloc(n * sizeof(st));
	pass = (st*)malloc(n * sizeof(st));
	for (i = 0; i < n; i++)
	{
		scanf("%d %d %d", &a[i].stn, &a[i].sc1, &a[i].sc2);
		a[i].total = a[i].sc1 * 0.4 + a[i].sc2 * 0.6;
	}
	for (i = 0; i < n; i++)
	{
		cnt = 1;
		for (j = 0; j < n; j++)
		{
			if (a[i].total < a[j].total) cnt++;
		}
		a[i].r = cnt;
	}
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (a[j].r > a[j + 1].r)
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	pcnt = n * 0.6;
	
	for (i = pcnt; i < n; i++)
	{
		cnt = pcnt + 1;
		for (j = pcnt; j < n; j++)
		{
			if (a[i].sc2 < a[j].sc2) cnt++;
		}
		a[i].r = cnt;
	}

	pcnt = 0;

	for (i = 0; i < n; i++)
	{
		if (a[i].r <= n * 0.8)
		{
			pass[pcnt] = a[i];
			pcnt++;
		}
	}
	for (i = 0; i < pcnt - 1; i++)
	{
		for (j = 0; j < pcnt - 1; j++)
		{
			if (pass[j].stn > pass[j + 1].stn)
			{
				tmp = pass[j];
				pass[j] = pass[j + 1];
				pass[j + 1] = tmp;
			}
		}
	}
	for (i = 0; i < pcnt; i++)
		printf("%d\n", pass[i].stn);

	free(a);
	free(pass);

	return 0;
}
