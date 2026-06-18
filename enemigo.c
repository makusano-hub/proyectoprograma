#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void inicioEnemigo(enemigo *e , float posx , float posy){
    e->posx = posx;
    e->posy = posy;  
    e->radio=15;
    e->velocidad = 1; /*la velocidad es en frames segun el timer*/
  //  e->sprite = al_load_bitmap("imagenes/scv.png");
}

void moverEnemigo(enemigo *e){
    e->posx -= e->velocidad;
if(e->posx + e->radio >= 800){
    e->posx = 800 - e->radio;
    e->velocidad *= -1;
}
if(e->posx - e->radio <=0)
{
    e->posx = e->radio;
    e->velocidad *= -1;
}

}
void dibujoEnemigo(enemigo *e){
al_draw_filled_circle(e->posx,e->posy,e->radio,al_map_rgb(0,255,0));
    //al_draw_bitmap(e->sprite, e->posx, e->posy,0);
}
