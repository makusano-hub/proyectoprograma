#ifndef torre_h
#define torre_h

#include "enemigo.h"
#include "jugador.h"
#include "mapa.h"
#include <stdbool.h>

#define cuadrado 32

typedef struct 
{
    int dano;
    int costo;
    int Tconstru;
    float ejex;
    float ejey;
    float ancho;
    float alto;
    ALLEGRO_BITMAP *sprite;
        
}Torre;

void inicTorre(Torre *T, float x, float y);
void dibuTorre(Torre *T);
void disparoTorre(Torre *T, Enemigo *e);

#endif