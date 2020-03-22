#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char name[7]; int k; int e; int m; float ave;
}student;


int main()
{
	int n, i;

	scanf("%d", &n);
	student* p = malloc(n * sizeof(student));

	for (i = 0; i < n; i++)
	{
		scanf("%s %d %d %d", &p[i].name, &p[i].k, &p[i].e, &p[i].m);
		p[i].ave = (float)(p[i].k + p[i].e + p[i].m) / 3;
	}
	for (i = 0; i < n; i++)
	{
		printf("%s %.1f", p[i].name, p[i].ave);
		if (p[i].k >= 90 || p[i].e >= 90 || p[i].m >= 90)
			printf(" GREAT");
		if (p[i].k < 70 || p[i].e < 70 || p[i].m < 70)
			printf(" BAD");
		printf("\n");
	}
	return 0;
}
