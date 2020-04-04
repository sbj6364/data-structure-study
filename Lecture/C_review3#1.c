#include <stdio.h>

void input(int* p, int N)
{
	int* pi;
	for (pi = p; pi < p + N; pi++)
		scanf("%d", pi);
}

void output(int* p, int N)
{
	int* pi;
	for (pi = p; pi < p + N; pi++)
		printf(" %d", *pi);
}

int main()
{
	int X[100], Y[100];
	int M, N, K;
	int i, j;

	int* px = X;
	int* py = Y;
	scanf("%d %d", &M, &N);

	input(px, M);
	input(py, N);

	scanf("%d", &K);

	i = 0, j = 0;
	while (1)
	{
		if (i == M / K || j == N / K) break;
		output(px + i*K, K);
		output(py + j*K, K);
		i++; j++;
	}
	if (i == M / K && j == N / K) return 0;
	else if (i == M / K)
	{
		while (j < N / K)
		{
			output(py + j * K, K);
			j++;
		}
	}
	else if (j == N / K)
	{
		while (i < M / K)
		{
			output(px + i * K, K);
			i++;
		}
	}
	return 0;
}
