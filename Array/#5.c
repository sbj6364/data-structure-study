#include <stdio.h>

int main()
{
    int ar[100][100];
    int i, j, k, n, m, num = 0;

    scanf("%d %d", &n, &m);

    for (i = 0; i <= n + m; i++)
    {
        for (j = 0; j < n; j++)
        {
            k = i - j;
            if ((k < m) && (k >= 0))
            {
                num++;
                ar[j][k] = num;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            printf(" %d", ar[i][j]);
        printf("\n");
    }
    return 0;
}
