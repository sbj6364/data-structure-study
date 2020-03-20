#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
	char n[9]; int s;
} student;

int main()
{
	student a[5];
	int i, sum = 0, avg;

	for (i = 0; i < 5; i++)
	{
		scanf("%s %d", &a[i].n, &a[i].s);
		sum += a[i].s;
	}
	avg = sum / 5;
	for (i = 0; i < 5; i++)
	{
		if (a[i].s <= avg)
			printf("%s\n", a[i].n);
	}
	return 0;
}
