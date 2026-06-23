#include <stdio.h>

#define N 3
#define M 4

void leerMatriz(char A[N][M]);


void leerMatriz(char A[N][M]){

    for(int i =0; i<N; i++ ){
        for (int j=0; j<M; j++)
        {
            printf("%c",A[i][j]);
        }
        printf("\n");
    }            
}