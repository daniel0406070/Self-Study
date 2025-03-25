#include <stdio.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int a[100002];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int min = 0x7fffffff;
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum = a[i - 1] + a[i];

        if (sum * m < min)
        {
            min = sum * m;
        }
    }

    printf("%d\n", min);
}