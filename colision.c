#include <allegro5/allegro.h>
#include<stdbool.h>
#include "jugador.h"
#include "enemigo.h"

bool colisionJugEn(jugador j,enemigo e){
    
    return( j.ejex <= e.ejex + e.ancho &&
            j.ejex + j.ancho >= e.ejex &&
            j.ejey <= e.ejey + e.alto &&
            j.ejey + j.alto >= e.ejey);
}