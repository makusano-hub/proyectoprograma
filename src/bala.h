#ifndef Bala_h
#define Bala_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <stdbool.h>

#include "enemigo.h"
#include "torre.h"

typedef struct 
{
    float x;
    float y;

    int ancho;
    int alto;

    float velocidad; //en x e y

    int dano;
    int objetivo;

    bool activo;

    ALLEGRO_BITMAP *sprite;

}Bala;

void inicBala(Bala balas[], int cantidadBalas, ALLEGRO_BITMAP * sprite);
void dispararBala(Bala balas[], int cantidadBalas, Torre *torre, Enemigo enemigos[],int indiceEnemigo);

void actBala(Bala balas[],int cantidadBalas,Enemigo enemigos[],int cantidadEnemigos);
void dibuBala(Bala balas[],int cantidadBalas);



#endif