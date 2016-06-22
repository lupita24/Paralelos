#include <stdio.h>
#include <time.h>
#define max( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define min( a, b ) ( ((a) < (b)) ? (a) : (b) )


#define n 1000
#define BlockSize  100
void matrix_product_simple()
{

    int row1, col1, row2, col2;
    printf("Ingrese fila y columna de la primera matriz: ");
    scanf("%d%d", &row1, &col1);
    printf("Ingrese fila y columna de la segunda matriz: ");
    scanf("%d%d",&row2, &col2);
   
    if(col1 == row2)
    {
    
        int A[row1][col1],B[row2][col2],C[col1][row2],i,j,k;
       for(i=0; i<row1; ++i)
       {
           for(j=0; j<col1; ++j)
            {
                A[i][j]=rand()%10;
            }
       }
       
       for(i=0; i<row2; ++i)
       {
           for(j=0; j<col2; ++j)
            {
                B[i][j]=rand()%10;
            }
       }
        
       for(i=0; i<row1; ++i)
       {
         for(j=0; j<col2; ++j)
         {
           for(k=0; k<col1; ++k)
           {
             C[i][j]+=A[i][k]*B[k][j];
           }    
         }
       }
    }
    else
    {
       printf("Column of first matrix is different to row of second matrix");
    }
}

void matrix_product_bloked()
{
    int a[n][n],b[n][n],c[n][n];
    c[0][0]=0;
    for(int i1=0;i1<(n/BlockSize);++i1)
    {
        for(int j1=0;j1<(n/BlockSize);++j1)
        {
            for(int k1=0;k1<(n/BlockSize);++k1)
            {
                for(int i=i1=0;i<min(i1+BlockSize-1);++i)
                {
                    for(int j=j1=0;j<min(j1+BlockSize-1);++j)
                    {
                        for(int k=k1;k<min(k1+BlockSize-1);++k)
                        {               
                            c[i][j] = c[i][j] + a[i][k] * b[k][j];
                        }
                    }
                }
            }
        }          
     }
}


int main(){
    clock_t start = clock();
    matrix_product_bloked();
    printf("Tiempo transcurrido: %f", ((double)clock() - start) / CLOCKS_PER_SEC);
    printf("\n\n");
    return 0;
    
}
