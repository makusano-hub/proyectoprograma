#ifndef Enemigo_h
#define Enemigo_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include "movimiento.h"
#include "camino.h"

#define MAxEnemigos 40
#define MaxPortales 10
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

    int indiceCamino;
    int caminoSeguir;
    int portalOrigen;

    bool vivo;

    int vida;
    int dano;
    ALLEGRO_BITMAP *sprite;
    
}Enemigo;

typedef struct 
{
    float ejex;
    float ejey;

    int cantidadMaxima;
    int enemigosCreados;    

    int tiempo;
    ALLEGRO_BITMAP *sprite;
}Portal;


void inicioEnemigo(Enemigo *e);
void inicioEnemigos(Enemigo enemigos[], int cantidad);

void moverEnemigo(Enemigo *e);
void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);

void colisionEnemigo(Enemigo *e);
void actualizar(Enemigo *e);

int inicSpawn(Portal portales[], int cantPortales);
void spawnEnemigos(Portal portales[],int cantPortales, Enemigo enemigos[], int cantmaxima);
bool enemigoMeta(Enemigo *e);

bool moverEnemigoCamino(Enemigo *e, Camino *Camino);

//void crearEnemigosPortal(Portal *P,Enemigo enemigos[]);
#endif