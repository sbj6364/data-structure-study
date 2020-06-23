#include <stdio.h>

int main()
{
    int n, i, j, check = 1;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            check = n * i + 1;
            for (j = check; j < check + n; j++)
                printf(" %d", j);
        }
        else
        {
            check = n * (i+1);
            for (j = check; j > check - n; j--)
                printf(" %d", j);
        }
        printf("\n");
    }
    return 0;
}
