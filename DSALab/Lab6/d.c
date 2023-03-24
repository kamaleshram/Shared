#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    int f[n];
    memset(f, 0, sizeof(f));

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int minUnique = 0;
    for (int i = 0; i < n; i++)
    {
        f[a[i]]++;
        if (i == 0)
            printf("%d ", a[minUnique]);
        else
        {
            if (a[i] != a[minUnique] && f[a[minUnique]] == 1)
            {
                printf("%d ", a[minUnique]);
            }
            else
            {
                int ans = -1;
                for (int j = minUnique; j <= i; j++)
                {
                    if (f[a[j]] == 1)
                    {
                        minUnique = j;
                        ans = a[minUnique];
                        break;
                    }
                }
                printf("%d ", ans);
            }
        }
    }
    return 0;
}