#ifndef Enemigo_h
#define Enemigo_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include "movimiento.h"

#define MAxEnemigos 4

typedef struct 
{
    float ejex;
    float ejey;
    float velocidad;
    int ancho;
    int alto;
    bool vivo;
    int vida;
    int dano;
    ALLEGRO_BITMAP *sprite;
    
}Enemigo;

typedef struct 
{
    float ejex;
    float ejey;
    int enemigoscreado;
    int cantmaxima;
}Portal;


void inicioEnemigo(Enemigo *e);
void moverEnemigo(Enemigo *e, teclado *t);
void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);
void colisionEnemigo(Enemigo *e);
void actualizar(Enemigo *e);
void inicSpawn(Portal *P, int cantmaxima);
bool enemigoMeta(Enemigo *e);
//void crearEnemigosPortal(Portal *P,Enemigo enemigos[]);
#endif