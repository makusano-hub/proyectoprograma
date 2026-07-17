#ifndef colision
#define colision

#include "jugador.h"
#include "enemigo.h"
#include "obstaculo.h"
#include "mapa.h"

bool colisionJugEn(Jugador j,Enemigo e);
//sin usar bool colisionObsJug(Jugador j,Obstaculo o);
bool colisionMetaEnemigo(Enemigo *e, Jugador *j);
void colisionRecursos(Jugador *j, Recursos recursos[],int cantRecursos);
#endif