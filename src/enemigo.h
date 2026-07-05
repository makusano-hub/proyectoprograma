#ifndef Enemigo_h
#define Enemigo_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define MAxEnemigos 4;
Portal spawn;

typedef struct 
{
    float ejex;
    float ejey;
    float velocidad;
    int ancho;
    int alto;
    
    int vida;
    int dano;
    ALLEGRO_BITMAP *sprite;
    
}Enemigo;

typedef struct 
{
    float ejex;
    float ejey;
}Portal;


void inicioEnemigo(Enemigo *e);
void moverEnemigo(Enemigo *e);
void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);
void colisionEnemigo(Enemigo *e);
void accionEnemigo(Enemigo *e);
void inicSpawn(Portal *P);
#endif