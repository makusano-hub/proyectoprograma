#include <allegro5/allegro.h>
#include <stdbool.h>
#include "colision.h"

bool colisionJugEn(Jugador j,Enemigo e){
    
    
    return( j.ejex <= e.ejex + e.ancho &&
            j.ejex + j.ancho >= e.ejex &&
            j.ejey <= e.ejey + e.alto &&
            j.ejey + j.alto >= e.ejey);
}
bool colisionObsJug(Jugador j, Obstaculo o){
    return( j.ejex <= o.ejex + o.ancho &&
            j.ejex + j.ancho >= o.ejex &&
            j.ejey <= o.ejey + o.alto  &&
            j.ejey + j.alto >= o.ejey);
}