#include <stdio.h>
#include <stdlib.h>

int check_row(int** p, int M, int N)
{
    int cnt = 0, mc = 0, i, j, k;
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            k = 0;
            cnt = 0;
            while (p[i][j + k] == 0)
            {
                cnt++;
                k++;
                if (j + k == N) break;
            }
            mc = cnt > mc ? cnt : mc;
        }
    }
    return mc;
}

int check_col(int** p, int M, int N)
{
    int cnt = 0, mc = 0, i, j, k;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            k = 0;
            cnt = 0;
            while (p[j + k][i] == 0)
            {
                cnt++;
                k++;
                if (j + k == M) break;
            }
            mc = cnt > mc ? cnt : mc;
        }
    }
    return mc;
}

int main()
{
    int i, j, M, N;
    int **matrix, x = 0, y = 0, z = 0, a, b;
    scanf("%d %d", &M, &N);
    matrix = (int**)malloc(M * sizeof(int*));
    for (i = 0; i < M; i++)
        matrix[i] = (int*)calloc(N, sizeof(int));

    do{
        matrix[x][y] = z;
        scanf("%d %d %d", &x, &y, &z);
    } while (x || y || z);

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
            printf(" %d", matrix[i][j]);
        puts("");
    }

    a = check_row(matrix, M, N);
    b = check_col(matrix, M, N);
    printf("%d", a > b ? a : b);

    for (i = 0; i < M; i++)
        free(matrix[i]);
    free(matrix);
  
    return 0;
}
