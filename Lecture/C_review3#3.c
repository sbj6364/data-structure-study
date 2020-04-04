#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	int N, i, j, k, cnt1 = 0, cnt2 = 0;
	int xlen, ylen, max = 0, maxi = 0;
	char X[100];
	char tmp[100];
	char** Y;

	scanf("%d", &N);
	scanf("%s", X);
	getchar();

	xlen = strlen(X);
	Y = (char**)malloc(N * sizeof(char*));

	if (Y == NULL)
	{
		printf("Not Enough Memory!");
		return -1;
	}

	for (i = 0; i < N; i++)
	{
		gets(tmp);
		ylen = strlen(tmp);
		Y[i] = (char*)malloc(ylen * sizeof(char));
		strcpy(Y[i], tmp);
	}
	for (i = 0; i < N; i++)
	{
		cnt1 = 0;
		ylen = strlen(Y[i]);
		for (j = 0; j < ylen - xlen + 1; j++)
		{
			cnt2 = 0;
			for (k = 0; k < xlen; k++)
			{
				if (Y[i][j + k] == X[k]) cnt2++;
			}
			if (cnt2 == xlen)
			{
				cnt1++;
				j = j + xlen - 1;
			}
		}
		if (cnt1 > max)
		{
			max = cnt1;
			maxi = i;
		}
	}
	if (max == 0)
	{
		printf("NONE");
		return 0;
	}
	else printf("%s", Y[maxi]);
	
	for (i = 0; i < 3; i++)
		free(Y[i]);
	free(Y);

	return 0;
}
