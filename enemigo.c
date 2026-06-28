#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "mapa.h"

void inicioEnemigo(enemigo *e , float ejex , float ejey){
   // e->ejex = ejex;
    //e->ejey = ejey;  
    
    e->velocidad = 1; /*la velocidad es en frames segun el timer*/
    e->sprite = al_load_bitmap("imagenes/zombie.png");
    e->ancho = 32;//al_get_bitmap_width(e->sprite);
    e->alto = 32;//al_get_bitmap_height(e->sprite);

    for(int i=0;i< FIL; i++){/*esto es para iniciar la posicion*/
        for(int j=0; j<COL;j++){
            if (mapa[i][j == 'e'])
            {
                e->ejex = j*32;
                e->ejey = i*32;
                return;
            }
        }
    }
}

void moverEnemigo(enemigo *e){
    e->ejex -= e->velocidad;

    /*colision con borde*/
    if(e->ejex + e->ancho >= 1280){
        e->ejex = 1280 - e->ancho;
        e->velocidad *= -1;
    }
    if(e->ejex <= 0){
        e->ejex = 0;
        e->velocidad *=-1;
    }
    /*movimiento de figura
    if(e->ejex + e->radio >= 800){
    e->ejex = 800 - e->radio;
    e->velocidad *= -1;
        }
    if(e->ejex - e->radio <=0)
    {
    e->ejex = e->radio;
    e->velocidad *= -1;
    }*/

}

void dibujoEnemigo(enemigo *e){
//al_draw_filled_circle(e->ejex,e->ejey,e->radio,al_map_rgb(0,255,0));
  al_draw_scaled_bitmap(e->sprite,0,0,al_get_bitmap_width(e->sprite),al_get_bitmap_height(e->sprite),e->ejex,e->ejey,e->ancho,e->alto,0); 
}
void colisionEnemigo(enemigo *e){
    

}
