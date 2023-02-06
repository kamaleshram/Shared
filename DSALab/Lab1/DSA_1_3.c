#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int * decimalToBinary(int num, int n) {   
   // Stores binary representation of number.
   int *binaryNum = (int *)calloc(n, sizeof(int));
   int i=0;

   if (num == 0) {
       return binaryNum;
    }
   
   for ( ;num > 0; ){
      binaryNum[i++] = num % 2;
      num /= 2;
   }
   return binaryNum;
}

int main()
{
    int n;
    scanf("%d",&n);

    int a[n];
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }

    int s;
    scanf("%d", &s);

    int power = pow(2,n);
    int **a2d;
    a2d = (int **)calloc(power, sizeof(int *));

    for(int i = 0; i<power; i++)
    {
        a2d[i] = decimalToBinary(i, n);
    }

    for (int i = 0; i < power; i++)
    {
      int y = 0;
      for(int j=0;j<n;j++)
      {
        if(a2d[i][j]==1)
        {
            y+=a[j];
        }

      }  
      if (y == s)
      {
        printf("POSSIBLE\n");
        for(int j=0;j<n;j++)
        {
        if(a2d[i][j]==1)
        {
            printf("%d\t", j);
        }

        }
        
        free(a2d);
        return 0;
      }

    }
    printf("NOT POSSIBLE");
    
    free(a2d);
    return 0;

}