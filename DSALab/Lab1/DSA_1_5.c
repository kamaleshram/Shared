#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void fun(int ** matrix,int n){
	int flag = 1 ;//r d
		for(int i =n;i>=1;i--){
			
			if(flag == 1){
				//Right print
				int count = 2*i*i;
				for(int k =0 ; k<i;k++){
					
					matrix[(n-i)/2][((n-i)/2 )+k] = count;
					count = count - 2;
				
				
				}
				
				
				//Down print
				count+=2;
				for(int k =0 ; k<i;k++){
					
					matrix[(n-i)/2 + k][((n+i)/2) -1] = count;
					count = count - 2;
				
				
				}
				
			
			
			}
			else {
				//left print
				int count = 2*i*i;
				for(int k =0 ; k<i;k++){
					
					matrix[(n+i-1)/2][((n+i-3)/2) - k] = count;
					count = count - 2;
				
				
				}
				
				
				//up print
				count+=2;
				for(int k =0 ; k<i;k++){
					
					matrix[((n+i-1)/2) - k][(n-i-1)/2] = count;
					count = count - 2;
				
				
				}
			
			
			}
			flag = flag*(-1);
		
		}
		
		
}

void printMatrix(int ** matrix,int n){
for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
		
		printf("%2d ",matrix[i][j]);
	
	}
	
	printf("\n");
	
	
	}
	
	

}


int main(){
	int n,**matrix;
	scanf("%d",&n);
	
	matrix = (int **)malloc(n*sizeof(int*));
	
	for(int i=0;i<n;i++){
		matrix[i]= (int *)calloc(n,sizeof(int));
		
	}
	
	
	if(n%2 ==0){
		fun(matrix,n);
		printMatrix(matrix,n);
	
	
	}
	else{
		int **m = (int **)malloc((n+1)*sizeof(int*));
	
		for(int i=0;i<(n+1);i++){
			m[i]= (int *)calloc(n+1,sizeof(int));
			
		}
		
		fun(m,n+1);
		
		for(int i =1;i<=n;i++){
			for(int j =0;j<n;j++){
				 matrix[i-1][j]= m[i][j];
		
		
			}
		
		
		}
		
		for(int i=0;i<n+1;i++){
		free(m[i]);
	
		}
		free(m);
		printMatrix(matrix,n);
		
		
		
		
		
		
		
		
		
	
	}
	
	
	int **hd = (int **)malloc(n*sizeof(int*));
	
	for(int i=0;i<n;i++){
		hd[i]= (int *)calloc(n-1,sizeof(int));
		
	}
	
	int **vd = (int **)malloc((n-1)*sizeof(int*));
	
	for(int i=0;i<n-1;i++){
		vd[i]= (int *)calloc(n,sizeof(int));
		
	}
	
	
	//filling hd
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if((matrix[i][j+1] - matrix[i][j])==2 || (matrix[i][j+1] - matrix[i][j])==-2){
				hd[i][j] =1;
			
			}
		
		}
		
	}
	
	
	//filling vd
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if((matrix[j+1][i] - matrix[j][i])==2 || (matrix[j+1][i] - matrix[j][i])==-2){
				vd[j][i] =1;
			
			}
		
		}
		
	}
	
	
	//printing
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			printf("%2d",matrix[i][j]);
			(hd[i][j])?printf("-"):printf(" ");
			
		
		}
		printf("%2d\n",matrix[i][n-1]);
		if(i!=n-1){
			for(int j=0;j<n;j++){
				(vd[i][j])?printf("|  "):printf("   ");
			
			}
			printf("\n");
		}
		
	}
	

	for(int i=0;i<n;i++){
		free(hd[i]);
		
	}
	for(int i=0;i<n;i++){
		free(matrix[i]);
	
	}
	free(matrix);
	
	free(hd);
	for(int i=0;i<n-1;i++){
		free(vd[i]);
		
	}
	free(vd);
	
	
	
	return 0;
	


}
