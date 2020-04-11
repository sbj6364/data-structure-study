#include <stdio.h>
#include <string.h>


int check(char* p, char c, int n)
{
	int cnt = 0;
	if (n < 0) return cnt;
	if (p[n] == c) cnt++;
	return cnt += check(p, c, n - 1);
}

int main()
{
	char a[100], b;
	scanf("%s", a);
	getchar();
	scanf("%c", &b);
	printf("%d", check(a,b,strlen(a)));
	return 0;
}
