#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
	int i;
	char** pch;
	pch = (char**)malloc(3 * sizeof(char*));
	for (i = 0; i < 3; i++)
		pch[i] = (char*)malloc(4 * sizeof(char));

	strcpy(pch[0], "aaa");
	strcpy(pch[1], "bbb");
	strcpy(pch[2], "ccc");

	for (i = 0; i < 3; i++)
		printf("%s\n",(pch[i]);
	for (i = 0; i < 3; i++)
		free(pch[i]);

	free(pch);

	return 0;
}