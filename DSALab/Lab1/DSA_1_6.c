#include <stdio.h>
#include <stdlib.h>

int isPrime(int n)
{
    int flag = 1;
    for(int i = 2; i < n/2; i++)
    {
        if(n%i == 0)
            flag = 0;
        
    }

    return flag;
}

int main()
{
    int n1, n2, max, maxi;
    printf("Enter the two numbers: ");
    scanf("%d", &n1);
    scanf("%d", &n2);

    int count = 0; 
    int *arr = calloc(10, sizeof(int));
    int *a = (int *)malloc(sizeof(int));

    for(int i = n1; i <= n2; i++){
        if(isPrime(i) == 1)
        {
            count+=1;
            a = (int *)realloc(a, count*sizeof(int));
            a[count-1] = i;
        }
    }

    for (int i = 0; i < count; i++)
    {
        int temp = a[i];
        int c;
        while (temp != 0)
        {
            c = temp%10;
            temp /= 10;
            arr[c]++;
        }
    }

    int i = 0;
    max = arr[i];
    maxi = i;
    for (i = 1; i < 10; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxi = i;
        }
    }

    printf("%d %d", maxi, max);
    
    return 0;
}