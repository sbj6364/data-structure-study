#include <stdio.h>

int main()
{
    int a[100][100];
    int i, j = 1, k = 1, l = 1, n, m;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m * n; i++)
    {
        a[j - 1][k - 1] = i + 1;

        if (j == l && k != m - l + 1) k++;
        else if (j != n - l + 1 && k == m - l + 1) j++;
        else if (j == n - l + 1 && k != l) k--;
        else j--;
        if (j == k && k == l)
        {
            l++;
            j++;
            k++;
        }
    }

    for (j = 0; j < n; j++)
    {
        for (k = 0; k < m; k++)
            printf(" %d", a[j][k]);
        printf("\n");
    }
}
