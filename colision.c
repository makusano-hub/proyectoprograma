#include <allegro5/allegro.h>
#include "jugador.h"
#include "enemigo.h"

bool colisionJugEn(jugador *j,enemigo *e){
    
    return( j->ejex < e->posx + e->ancho &&
            j->ejex + j->ancho > e->posx &&
            j->ejey < e->posy + e->alto &&
            j->ejey + j->alto > e->posy);
}