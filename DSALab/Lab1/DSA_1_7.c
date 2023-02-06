#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[100];
    char sstr[100];
    int flag;
    printf("Enter string");
    gets(str);
    printf("Enter substring");
    gets(sstr);
    int n = strlen(str);
    char estr[100];
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        a[i] = (int *)calloc(2, sizeof(int));

    int h = strlen(sstr);
    int count = 0;
    int m[n];
    for (int i = 0; i < n; i++)
    {
        count = 0;
        strcpy(estr, sstr);
        for (int j = i; j < n; j++)
        {
            flag = 0;

            for (int k = 0; k < h; k++)
            {
                if (estr[k] == str[j])
                {
                    if (flag == 0)
                    {
                        estr[k] = '\0';
                        count++;
                        flag = 1;
                    }
                }
            }
            if (count == h)
            {
                a[i][0] = i;
                a[i][1] = j;
                break;
            }
            if (j == (n - 1))
            {
                a[i][0] = -1;
                a[i][1] = -1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i][0] < 0)
        {
            m[i] = n + 1;
        }
        else
        {
            m[i] = a[i][1] - a[i][0];
        }
    }

    int index = 0;
    int temp = m[0];
    for (int i = 0; i < n; i++)
    {
        if (m[i] < temp)
        {
            temp = m[i];
            index = i;
        }
    }
    if (temp == n + 1)
    {
        printf("Not possible");
    }
    else
        printf("%d %d \n", a[index][0], a[index][1]);

    // for (int i = 0; i < n; i++)
    //     printf("i j at a[%d] is %d %d\n", i, a[i][0], a[i][1]);
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
}