#include <stdio.h>

void input(int* p, int M)
{
	int* pi = p;
	for (pi = p; pi < p + M; pi++)
	{
		scanf("%d", pi);
	}
}

int* sel_max(int* p, int M)
{
	int max = 0, cnt = 0;
	int* pi, * pj, * m = NULL;
	for (pi = p; pi < p + M; pi++)
	{
		cnt = 0;
		for (pj = pi; pj < p + M; pj++)
		{
			if (*pi == *pj) cnt++;
		}
		if (cnt > max)
		{
			max = cnt;
			m = pi;
		}
	}
	return m;
}

void output(int* p, int N)
{
	int* pi = p;
	for (pi = p; pi < p + N; pi++)
	{
		printf(" %d", *pi);
	}
}

int main(void)
{
	int in[100], out[100], * max, i, N, M;

	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
	{
		input(in, M);
		max = sel_max(in, M);
		out[i] = *max;
	}
	output(out, N);
	return 0;
}
