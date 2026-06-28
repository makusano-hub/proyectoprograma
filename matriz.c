#include <stdio.h>

#define N 25
#define M 40

void leerMatriz(char A[N][M]);
void imprimirMatriz(char A[N][M+2]);

int main()
{
    
    char A[N][M+2];

    FILE *fdata = fopen("matriz2.txt","r");

    for(int i = 0; i < N; i++) {
        fgets(A[i], M+2, fdata);
    }     

    fclose(fdata);
    printf("%c \n\n",A[N-1][M-1]);
    imprimirMatriz(A);    
}

void leerMatriz(char A[N][M]){
    FILE *fdata = fopen("matriz2.txt", "r");
    for(int i =0; i<N; i++ ){
        for (int j=0; j<M; j++)
        {
            fgetc(fdata);
        }
        
        
    }        
    fclose(fdata);       
}

void imprimirMatriz(char A[N][M+2]) {
    for(int i = 0; i < N; i++) {
        printf("%s", A[i]);
    }
    
}
void crearNivel(char A[N][M]){
    
}