#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


#include "jugador.h"
#include "movimiento.h"
#include "mapa.h"

void inicjugador(jugador *j){ 
    j->velocidad= 5;
    j->sprite = al_load_bitmap("imagenes/jugplaceholder.png");
    j->ancho = 32;//al_get_bitmap_width(j->sprite);
    j->alto = 32;//al_get_bitmap_height(j->sprite);
    j->ejex = 0;
    j ->ejey = 0;

    /*utilizar posicio inicial en matriz para iniciar el jugador*/
    for(int i=0;i< FIL; i++){
        for(int k=0; k<COL;k++){
            if (mapa[i][k] == 'j')
            {
                j->ejex = k*32;
                j->ejey = i*32;
                return;
            }
        }
    }
    

}

//void actJugador(jugador *j, teclado *t){
 //   j ->ejex += posix* j->velocidad;
 //   j ->ejey += posiy* j->velocidad;
//}

void dibuJugador(jugador *j){
//aca se dibuja el sprite 
 //al_draw_filled_rectangle(j->ejex,j->ejey, j->ejex+anchojugador, j->ejey+altojugador,al_map_rgb(255,0,0));
  al_draw_scaled_bitmap(j->sprite,0,0,al_get_bitmap_width(j->sprite),al_get_bitmap_height(j->sprite), j->ejex, j->ejey,j->ancho,j->alto,0);
 
  
}
