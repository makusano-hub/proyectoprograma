#ifndef colision
#define colision

#include "jugador.h"
#include "enemigo.h"
#include "obstaculo.h"
#include "mapa.h"

bool colisionJugEn(Jugador j,Enemigo e);
bool colisionObsJug(Jugador j,Obstaculo o);
bool colisionMetaEnemigo(Enemigo e);
void colisionRecursos(Jugador *j);
#endif