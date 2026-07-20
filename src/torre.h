#ifndef torre_h
#define torre_h

#include "enemigo.h"
#include "jugador.h"
#include "mapa.h"
#include <stdbool.h>

#define MaxTorres 50

#define costoOro 1
#define costoMadera 1

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



void inicTorreInicial(Torre *castillo,ALLEGRO_BITMAP *sprite);
void inicTorres(Torre torres[], int cantidadTorres);

bool crearTorreJugador(Torre torres[], int *cantidadTorres, Jugador *jugador, ALLEGRO_BITMAP *sprite);


void dibuTorre(Torre *torre);
void dibuTorreS(Torre torres[],int cantidadTorres);

bool rango(Torre *torre, Enemigo *e);


//void actTorre(Torre *torre);
//void inicTorres(Torre torres[], int cantidad);
//bool EnRango(Torre *torre, Enemigo *e);//no implementado aun

//void disparoTorre(Torre torres[], Enemigo *e);
//void TorreInicial(Torre);

#endif