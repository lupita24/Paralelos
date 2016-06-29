#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define n 800
#define nbloque 100

#define MIN(a,b) ((a) < (b) ? (a) : (b))
inline int min ( int a, int b ) { return a < b ? a : b; }

void matrix_product_simple(int A[n][n],int B[n][n],int C[n][n])
{        
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            for(int k=0; k<n; ++k)
            {
                C[i][j]+=A[i][k]*B[k][j];
            }    
        }
    }
}

void matrix_product_bloked(int A[n][n],int B[n][n],int C[n][n]){


	for(int i1=1;i1<n;i1=i1+nbloque){
		for(int j1=1;j1<n;j1=j1+nbloque){
			for(int k1=1;k1<n;k1=k1+nbloque){
				for(int i=i1;i<MIN(i1+nbloque-1,n);i++){
					for(int j=j1;j<MIN(j1+nbloque-1,n);j++){
						for(int k=k1;k<MIN(k1+nbloque-1,n);k++){
							C[i][j]+=A[i][k]*B[k][j];
						}
					}
				}
			}
		}
	}
}	

int main(){

    int A[n][n];
	int B[n][n];
	int C[n][n];

	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			A[i][j]=rand()%10;
			
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			B[i][j]=rand()%10;
			
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<n;j++){
			C[i][j]=0;
			
		}
	}
	//printf("matrix_product_bloked: tamanio de matriz - 800");
	printf("matrix_product_simple: tamanio de matriz - 800");
    printf("\n\n");
    clock_t start = clock();
    matrix_product_simple(A,B,C);
    //matrix_product_bloked(A,B,C);
    printf("Tiempo transcurrido: %f", ((double)clock() - start) / CLOCKS_PER_SEC);
    printf("\n\n");

    return 0;
    
}
