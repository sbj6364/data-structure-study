#include <stdio.h>
#include <string.h>

int main()
{
	char st[100], cal[10];
	int i = 0, cnt = 0, cnt2 = 0;
	double num[10] = { 0 }, sum = 0;

	gets(st);
	while (st[i] != 0)
	{
		if (st[i] >= '0' && st[i] <= '9')
		{
			while (st[i] >= '0' && st[i] <= '9')
			{
				num[cnt] *= 10;
				num[cnt] += st[i] - '0';
				i++;
			}
			cnt++;
		}
		else if (st[i] == '-')
		{
			cal[cnt2] = st[i];
			cnt2++;
			while (st[i] < '0' || st[i] > '9')
				i++;
			while (st[i] >= '0' && st[i] <= '9')
			{
				num[cnt] *= 10;
				num[cnt] += st[i] - '0';
				i++;
			}
			num[cnt] *= -1;
			cnt++;
		}
		else if (st[i] == '+' || st[i] == '*' || st[i] == '/')
		{
			cal[cnt2] = st[i];
			cnt2++;
			i++;
		}
		else i++;
	}
	for (i = 0; i < cnt2; i++)
	{
		if (cal[i] == '*')
		{
			num[i + 1] *= num[i];
			num[i] = 0;
		}
		else if (cal[i] == '/')
		{
			num[i + 1] = num[i] / num[i + 1];
			num[i] = 0;
		}
	}
	for (i = 0; i < cnt; i++) sum += num[i];
	printf("%lf", sum);

	return 0;
}
