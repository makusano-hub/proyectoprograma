#include <stdio.h>
#include <stdlib.h>
#include "torre.h"

#define maxTorres 20
extern char mapa[FIL][COL];
void inicTorres(Torre torres[], int cantidad);
//void dibuTorres(Torre torre[MaxTorres]);
//void disparoTorre(Torre *T, Enemigo *e);

void inicTorre(Torre *T){
    T->ejex = 0;
    T->ejey = 0;
    T->ancho = cuadrado;
    T->alto = cuadrado;
    T->activo = true;
    T->sprite = al_load_bitmap("../imagenes/castelo.png");
    buscarPosicion('k',&T->ejex,&T->ejey);
    
}
void dibuTorre(Torre *T){
     al_draw_scaled_bitmap(T->sprite,0,0,al_get_bitmap_width(T->sprite),al_get_bitmap_height(T->sprite),T->ejex,T->ejey,T->ancho,T->alto,0);
}

void inicTorres(Torre torres[],int cantidad){
    al_load_bitmap("../imagenes/torre.png");
    

    
}
