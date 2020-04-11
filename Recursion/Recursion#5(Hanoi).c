#include <stdio.h>

int hanoi(int n, char from, char to, char other)
{
	if (n == 0) return 0;
	hanoi(n - 1, from, other, to);
	printf("%c %c\n", from, to);
	hanoi(n - 1, other, to, from);
}

int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 'A','C','B');
	return 0;
}

//참고자료: (https://www.youtube.com/watch?v=aPYE0anPZqI)
