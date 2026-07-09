#include <stdio.h>
#include <stdlib.h>
#include "torre.h"

#define maxTorres 20
extern char mapa[FIL][COL]
void inicTorre(Torre *T, float x, float y);
void dibuTorre(Torre *T);
void disparoTorre(Torre *T, Enemigo *e);

void inicTorre(Torre *T, float x, float y){
    T->ejex = x;
    T->ejey = y;
    T->ancho = cuadrado;
    T->alto = cuadrado;
    T->vivo = true;
    
}
void dibuTorre(Torre *T){

}
