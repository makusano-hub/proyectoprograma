#ifndef Bala_h
#define Bala_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>
#include <math.h>

#include "enemigo.h"
#include "torre.h"

#define MaxBalas 100

typedef struct 
{
    float x;
    float y;

    int ancho;
    int alto;

    float direccionX;
    float direccionY;

    float velocidad; //en x e y
    float distanciaReccorida;
    float distanciaMax;

    int dano;
    int objetivo;

    bool activo;

    ALLEGRO_BITMAP *sprite;

}Bala;

void inicBala(Bala balas[], int cantidadBalas, ALLEGRO_BITMAP * sprite);
bool dispararBala(Bala balas[], int cantidadBalas, Torre *torre, Enemigo enemigos[],int indiceEnemigo);

void actDisparoTorre(Torre *torre, Bala balas[],int cantidadBalas, Enemigo enemigos[],int cantidadEnemigos);
void actDisparoCastillo(Torre *castillo, Torre torres[], int cantidadTorres,Bala balas[], int cantidadBalas, Enemigo enemigos[], int cantidadEnemigos);

void actBala(Bala balas[],int cantidadBalas,Enemigo enemigos[],int cantidadEnemigos);
void dibuBala(Bala balas[],int cantidadBalas);



#endif