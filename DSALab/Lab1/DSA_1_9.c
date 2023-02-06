#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k, n;
    
    scanf("%d %d", &k,&n);
    int *a = (int *)malloc(n*sizeof(int));
    

   for (int i = 0; i < n; i++)
   {
        scanf("%d",a+i);
   }

   for(int l=0;l<n;l++){
        for (int i = 0; i < n-l; i++)
        {
            int j = i+1;
            if(j<n){
                if(a[i]>a[j] && a[i]>((k+1)/2)  &&  a[j]<((k+1)/2)){

                    int temp = a[j];
                    a[j]=a[i];
                    a[i] = temp;


                }
                if(a[i]>a[j] && a[i]==((k+1)/2)  &&  a[j]<((k+1)/2)){

                    int temp = a[j];
                    a[j]=a[i];
                    a[i] = temp;


                }
                if(a[i]>a[j] && a[i]>((k+1)/2)  &&  a[j]==((k+1)/2)){

                    int temp = a[j];
                    a[j]=a[i];
                    a[i] = temp;


                }

                


            }
        }
   }

   for (int i = 0; i < n; i++)
   {
    printf("%d ",*(a+i));
   }
    
   
    free(a);
    return 0 ;
    
}