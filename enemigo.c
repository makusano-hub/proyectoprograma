#include "enemigo.h"
#include <allegro5/allegro_image.h>

void inicioEnemigo(enemigo *e , float posx , float posy,float velocidad){
    e->posx = 100;
    e->posy = 200;
    e->velocidad = 1; /*la velocidad es en frames segun el timer*/
    e->sprite = al_load_bitmap("imagenes/scv.png");
}

void moverEnemigo(enemigo *e){
    e->posx -= e->velocidad;
}
void dibujoEnemigo(enemigo *e){
    al_draw_bitmap(e->sprite, e->posx, e->posy,0);
}
