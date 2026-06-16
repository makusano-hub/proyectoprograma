#ifndef enemigo_h
#define enemigo_h

#include <allegro5/allegro.h>

typedef struct 
{
    float posx;
    float posy;
    float velocidad;
    /*ALLEGRO_BITMAP *sprite; */
}enemigo;

void inicioEnemigo(enemigo *e , float posx, float posy);
void moverEnemigo(enemigo *e);
void dibujoEnemigo(enemigo *e);

#endif