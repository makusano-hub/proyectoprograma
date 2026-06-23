#ifndef enemigo_h
#define enemigo_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

typedef struct 
{
    float posx;
    float posy;
    float velocidad;
    int ancho;
    int alto;
    
    //int vida;
   /*int dano;*/
    ALLEGRO_BITMAP *sprite;
    
}enemigo;

void inicioEnemigo(enemigo *e , float posx, float posy);
void moverEnemigo(enemigo *e);
void dibujoEnemigo(enemigo *e);

#endif