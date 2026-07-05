#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "mapa.h"
void inicionemigo(Enemigo *e);
void moverEnemigo(Enemigo *e);
void diujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);

void inicionemigo(Enemigo *e ){

    e->velocidad = 1; 
    e->sprite = al_load_bitmap("imagenes/zombie.png");
    e->ancho = 32;
    e->alto = 32;
    e->ejex = 0;
    e->ejey = 0;

    e->vida = 20;
    e->dano = 1;
    int cantidadEnemigos = 0;
    /*while(cantidadEnemigos<=MAxEnemigos){

    }*/

   /*for(int i=0;i< FIL; i++){/
        for(int j=0; j<COL;j++){
            if (mapa[i][j] == 'e')
            {   
                printf("%c",mapa[i][j]);
                e->ejex = j*32;
                e->ejey = i*32;
                return;
                cantidadEnemigos++;
            } 
        }
    }*/
}

void moverEnemigo(Enemigo *e){
    e->ejex -= e->velocidad;
    /*colision con borde no con l*/
    if(e->ejex + e->ancho >= 1280){
        e->ejex = 1280 - e->ancho;
        e->velocidad *= -1;
    }
    if(e->ejex <= 0){
        e->ejex = 0;
        e->velocidad *=-1;
    }
}

void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino){
//al_draw_filled_circle(e->ejex,e->ejey,e->radio,al_map_rgb(0,255,0));
  al_draw_scaled_bitmap(e->sprite,0,0,al_get_bitmap_width(e->sprite),al_get_bitmap_height(e->sprite),e->ejex,e->ejey,e->ancho,e->alto,0); 
   for(int i =0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            if(mapa[i][j]== 'j' && mapa[i][j+1] == 'c' ){
                al_draw_bitmap(camino, j*cuadrado, i*cuadrado,1);
            }
            if(mapa[i][j]== 'j' && mapa[i][j+1] != 'c'){
                al_draw_bitmap(pasto, j*cuadrado, i*cuadrado,1);
            }

        }
    }

}
void colisionEnemigo(Enemigo *e){  

}
void accionEnemigo(Enemigo *e){
    
}
void crearSpawn();
