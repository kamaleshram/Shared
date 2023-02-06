#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, ra, ca;
    scanf("%d %d", &ra, &ca);

    p = (int *)malloc(ra * ca * sizeof(int));

    int rb, cb;
    scanf("%d %d", &rb, &cb);

    int *q = (int *)malloc(rb * cb * sizeof(int));

    int x = 0;
    for (int i = 0; i < ra; i++)
    {
        printf("Enter value of %d row for first matrix\n", i + 1);
        for (int j = 0; j < ca; j++)
        {
            scanf("%d", &x);
            p[i * ca + j] = x;
        }
    }

    for (int i = 0; i < rb; i++)
    {
        printf("Enter value of %d row for second matrix\n", i + 1);
        for (int j = 0; j < cb; j++)
        {
            scanf("%d", &x);
            p[i * cb + j] = x;
        }
    }

    int flag = 1;
    for (int m = 0; m < ra; m++)
    {
        for (int n = 0; n < ca; n++)
        {
            if (p[m * ca + n] == q[0])
            {
                if (m + rb > ra)
                {
                    if (n + cb > ca)
                    {
                        int h = m * ca + n;

                        for (int i = 0; i < rb; i++)
                        {
                            for (int j = 0; j < cb; j++)
                            {
                                if (p[h + ((i * ra) + j)] == q[i * cb + j])
                                {
                                    flag = 0;
                                }
                                else
                                {
                                    flag = 1;
                                }
                                if (flag == 1)
                                    break;
                            }
                            if (flag == 1)
                                break;
                        }
                    }
                }
            }
            if (flag == 0)
                break;
        }
        if (flag == 0)
            break;
    }
    if (flag == 0)
        printf("Second matrix is a submatrix of the first one");
    else
        printf("Psych");
}
