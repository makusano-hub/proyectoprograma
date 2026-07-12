#ifndef Enemigo_h
#define Enemigo_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include "movimiento.h"

#define MAxEnemigos 40
#define tiempo_spawn 60

typedef struct 
{
    float ejex;
    float ejey;

    float casillax;
    float casillay;

    float velocidad;
    int ancho;
    int alto;

    bool vivo;
    bool moverse;

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
    int tiempo;
    ALLEGRO_BITMAP *sprite;
}Portal;


void inicioEnemigo(Enemigo *e);
void inicioEnemigos(Enemigo enemigos[], int cantidad);

void moverEnemigo(Enemigo *e);
void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);

void colisionEnemigo(Enemigo *e);
void actualizar(Enemigo *e);

void inicSpawn(Portal *P, int cantmaxima);
void spawnEnemigos(Portal *P,Enemigo enemigos[], int cantmaxima);
bool enemigoMeta(Enemigo *e);

//void crearEnemigosPortal(Portal *P,Enemigo enemigos[]);
#endif