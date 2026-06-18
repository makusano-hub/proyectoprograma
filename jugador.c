#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "jugador.h"
#include "movimiento.h"


void inicjugador(jugador *j,float ejex, float ejey){
    j->ejex = ejex;
    j ->ejey = ejey;
    j->velocidad= 5;
    

}

//void actJugador(jugador *j, teclado *t){
 //   j ->ejex += posix* j->velocidad;
 //   j ->ejey += posiy* j->velocidad;
//}

void dibuJugador(jugador *j){
 //al_draw_bitmap;
 al_draw_filled_rectangle(j->ejex,j->ejey, j->ejex+anchojugador, j->ejey+altojugador,al_map_rgb(255,0,0));

 /*cuando encuentre sprite*/
  /*j ->sprite = al_load_bitmap("imagenes/scv.png");*/
}
