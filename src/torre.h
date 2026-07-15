#ifndef torre_h
#define torre_h

#include "enemigo.h"
#include "jugador.h"
#include "mapa.h"
#include <stdbool.h>

#define MaxTorres 50

#define costoOro 10
#define costoMadera 10

typedef struct 
{
    int dano;
    float alcance;
    
    int Tconstru;
    float ejex;
    float ejey;
    float ancho;
    float alto;

    bool activo;
    ALLEGRO_BITMAP *sprite;
        
}Torre;



void inicTorre(Torre *torre);
void actTorre(Torre *torre);
void dibuTorre(Torre *torre);
void inicTorres(Torre torres[], int cantidad);
void dibuTorres(Torre torres[]);
/*
void disparoTorre(Torre torres[], Enemigo *e);
void TorreInicial(Torre);*/

#endif