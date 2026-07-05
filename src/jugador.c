#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>

#include "jugador.h"
#include "movimiento.h"
#include "mapa.h"

void inicJugador(Jugador *j){ 
    j->velocidad= 5;
    j->sprite = al_load_bitmap("imagenes/jugplaceholder.png");
    j->ancho = 32;
    j->alto = 32;
    j->vida = 20;
    j->ejex = 0;
    j->ejey = 0;

    buscarPosicion('j',&j->ejex,&j->ejey);
   /* for(int i=0;i< FIL; i++){
        for(int k=0; k<COL;k++){
            if (mapa[i][k] == 'j')
            {
                j->ejex = k*32;
                j->ejey = i*32;
                return;
            }
        }
    } */  

}

//void actJugador(Jugador *j, teclado *t){
 //   j ->ejex += posix* j->velocidad;
 //   j ->ejey += posiy* j->velocidad;
//}

void dibuJugador(Jugador *j, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino){
    
//aca se dibuja el sprite 
 //al_draw_filled_rectangle(j->ejex,j->ejey, j->ejex+anchoJugador, j->ejey+altoJugador,al_map_rgb(255,0,0));
  
    for(int i =0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            if(mapa[i][j]== 'j' && mapa[i][j+1] == 'c' ){
                al_draw_bitmap(camino, j*cuadrado, i*cuadrado,1);
            }
        }
    }
    al_draw_scaled_bitmap(j->sprite,0,0,al_get_bitmap_width(j->sprite),al_get_bitmap_height(j->sprite), j->ejex, j->ejey,j->ancho,j->alto,0);
  
}
