#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>


#include "jugador.h"
#include "movimiento.h"


void inicjugador(jugador *j,float ejex, float ejey){
    j->ejex = ejex;
    j ->ejey = ejey;
    j->velocidad= 5;
    j->sprite = al_load_bitmap("imagenes/jugplaceholder.png");
    j->ancho = 64;//al_get_bitmap_width(j->sprite);
    j->alto = 64;//al_get_bitmap_height(j->sprite);
    

}

//void actJugador(jugador *j, teclado *t){
 //   j ->ejex += posix* j->velocidad;
 //   j ->ejey += posiy* j->velocidad;
//}

void dibuJugador(jugador *j){
 
 //al_draw_filled_rectangle(j->ejex,j->ejey, j->ejex+anchojugador, j->ejey+altojugador,al_map_rgb(255,0,0));
  al_draw_scaled_bitmap(j->sprite,0,0,al_get_bitmap_width(j->sprite),al_get_bitmap_height(j->sprite), j->ejex, j->ejey,j->ancho,j->alto,0);
 
  
}
