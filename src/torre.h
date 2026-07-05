#ifndef torre_h
#define torre_h

#include "enemigo.h"
#include "jugador.h"

typedef struct 
{
    int dano;
    int costo;
    int Tconstru;
    float ejex;
    float ejey;
    
}Torre;

void inicTorre(Torre *T);
void dibuTorre(Torre *T);
void disparoTorre(Torre *T, enemigo *e);

#endif