#include <stdio.h>
#include <string.h>

int main()
{
    char strin[100], *token,
    strstr[100], strpal[100][100] = {};
    gets(strin);
    int count = 0;
    char *s = " ";
    token = strtok(strin, s);

    while(token != NULL)
    {
        char strtemp[100] = {};
        for(int i = strlen(token)-1; i>=0; i--)
        {
            strncat(strtemp, &(token[i]), 1);
        }
        
        if (strcmp(token, strtemp) == 0 && strlen(token) != 1)
        {
            strcat(strpal[count], strtemp);
            count++;
        }

        strncat(strtemp, s, 1);
        strcat(strstr, strtemp);
        

        token = strtok(NULL, s);
    }

    printf("%s\n", strstr);

    if (count == 0)
        printf("NO PALINDROMES");

    else
    {
        for (int i = 0; i < count; i++){
            printf("%s ", strpal[i]);
        }
    }

    return 0;
}
