#include <stdio.h>
#include <stdlib.h>

typedef struct time
{
	int h; int m; int s;
} time;

int main()
{
	time a, b, c;

	scanf("%d %d %d", &a.h, &a.m, &a.s);
	scanf("%d %d %d", &b.h, &b.m, &b.s);

	c.h = b.h - a.h;
	c.m = b.m - a.m;
	c.s = b.s - a.s;

	if (c.m < 0)
	{
		c.m += 60;
		c.h -= 1;
	}
	if (c.s < 0)
	{
		c.s += 60;
		c.m -= 1;
	}
	
	printf("%d %d %d", c.h, c.m, c.s);
	return 0;
}
