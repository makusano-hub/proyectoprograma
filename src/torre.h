#ifndef torre_h
#define torre_h

#include "enemigo.h"
#include "jugador.h"
#include "mapa.h"
#include <stdbool.h>

#define MaxTorres 50

#define costoOro 10
#define costoMadera 10

typedef enum{
    torreNormal,
    torreRapida
}TipoTorre;

typedef struct 
{

    TipoTorre tipo;

    int dano;
    float alcance;
    
    int faseConstruccion;
    int auxConstruccion;//cuantas fases
    int cantidadFase; //contador fase
    bool construida;
    //int fases el spritesheet tiene 5
    // si funciona ataca o sea bool funciona
    //

    float ejex;
    float ejey;

    float ancho;
    float alto;

    int disparo;
    int intervaloDisparo;

    bool activo;
    ALLEGRO_BITMAP *sprite;
        
}Torre;

/*
typedef struct{
    
}bala*/



void inicTorreInicial(Torre *castillo,ConfigMap *configuracion,ALLEGRO_BITMAP *sprite);
void inicTorres(Torre torres[], int cantidadTorres);

bool crearTorreJugador(Torre torres[], int *cantidadTorres, Jugador *jugador,DatosJugador *dj,ConfigMap *configuracion, ALLEGRO_BITMAP *sprite,TipoTorre tipo);

void construirTorre(Torre *torre);
void construirTorres(Torre torres[], int cantidadTorres);

void dibuTorre(Torre *torre);
void dibuTorreS(Torre torres[],int cantidadTorres);

bool rango(Torre *torre, Enemigo *e);


//void actTorre(Torre *torre);
//void inicTorres(Torre torres[], int cantidad);
//bool EnRango(Torre *torre, Enemigo *e);//no implementado aun

//void disparoTorre(Torre torres[], Enemigo *e);
//void TorreInicial(Torre);

#endif