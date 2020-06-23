#include<stdio.h>

int main()
{
    int a[100], b[100], cpy[100];
    int n, m, i, j, k, tmp = 0;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    scanf("%d", &m);
    for (i = 0; i < m; i++)
        scanf("%d", &b[i]);

    for (i = 0; i < m; i++)
        cpy[i] = a[b[i]];

    for (i = 0; i < m - 1; i++)
        a[b[i + 1]] = cpy[i];

    for (i = 0; i < n; i++)
        printf(" %d", a[i]);

    return 0;
}
