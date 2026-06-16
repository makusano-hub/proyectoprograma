#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "jugador.h"


void inicjugador(jugador *e,float start_x, float start_y){
    e->ejex = start_x;
    e->ejey = start_y;

    

}
void actJugador(jugador *e){
    e->ejex += e->velocidad;
    e->ejey += e->velocidad;
}
void dibuJugador(jugador *e){
 /*al_draw_bitmap*/
 al_draw_filled_rectangle(e->ejex, e->ejey, e->ejex + e->ancho, e->ejey + e->alto, al_map_rgb(255,0,0));
}
