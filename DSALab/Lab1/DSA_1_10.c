#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char word1[30], word2[30];
    
    int *word1f = (int *)calloc(26, sizeof(int));
    int *word2f = (int *)calloc(26, sizeof(int));

    gets(word1); gets(word2);
    int indm[strlen(word1)];
    
    for(int i = 0; i < strlen(word1); i++)
    {
        word1f[((int)(word1[i])) - 97]++;
        word2f[((int)(word2[i])) - 97]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if (word1f[i] != word2f[i])
        {
            printf("NOT POSSIBLE");
            return 0;
        }
    }

    printf("POSSIBLE\n");

    for (int i = 0; i < strlen(word2); i++)
    {
        for (int j = 0; j < strlen(word1); j++)
        {
            if (word2[i] == word1[j])
                indm[i] = j+1;
        }
    }

    for (int i = 0; i < strlen(word1); i++)
        printf("%d ", indm[i]);

    return 0;
}