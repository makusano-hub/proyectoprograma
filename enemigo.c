#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

void inicioEnemigo(enemigo *e , float posx , float posy){
    e->posx = posx;
    e->posy = posy;  
    
    e->velocidad = 1; /*la velocidad es en frames segun el timer*/
    e->sprite = al_load_bitmap("imagenes/zombie.png");
    e->ancho = al_get_bitmap_width(e->sprite);
    e->alto = al_get_bitmap_height(e->sprite);
}

void moverEnemigo(enemigo *e){
    e->posx -= e->velocidad;

    /*colision con borde*/
    if(e->posx + e->ancho >= 1280){
        e->posx = 1280 - e->ancho;
        e->velocidad *= -1;
    }
    if(e->posx <= 0){
        e->posx = 0;
        e->velocidad *=-1;
    }
    /*movimiento de figura
    if(e->posx + e->radio >= 800){
    e->posx = 800 - e->radio;
    e->velocidad *= -1;
        }
    if(e->posx - e->radio <=0)
    {
    e->posx = e->radio;
    e->velocidad *= -1;
    }*/

}

void dibujoEnemigo(enemigo *e){
//al_draw_filled_circle(e->posx,e->posy,e->radio,al_map_rgb(0,255,0));
  al_draw_scaled_bitmap(e->sprite,0,0,e->ancho,e->alto,e->posx,e->posy,64,64,0); 
}
void colisionEnemigo(enemigo *e){
    

}
