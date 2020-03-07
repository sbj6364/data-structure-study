#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct book_title
{
	char* title;
} BINFO;


int main()
{
	BINFO* bp = NULL;
	int n, i;
	char tmp[100];

	scanf("%d\n", &n);

	bp = (BINFO*)malloc(n * sizeof(BINFO));
	
	if (bp == NULL)
	{
		printf("Not enough memory!");
		return -1;
	}

	for (i = 0; i < n; i++)
	{
		gets(tmp);
		bp[i].title = (char*)malloc((strlen(tmp) + 1) * sizeof(char));

		if (bp[i].title == NULL)
		{
			printf("Not enough memory!");
			return -1;
		}
		strcpy(bp[i].title, tmp);
	}
	for (i = 0; i < n; i++)
	{
		printf("%s \n", bp[i].title);
	}
	for (i = 0; i < n; i++) free(bp[i].title);
		
	return 0;
}