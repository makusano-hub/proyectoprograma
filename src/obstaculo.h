#ifndef barrera_h
#define barrera_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>


typedef struct 
{
    float ejex;
    float ejey;
    int ancho;
    int alto;
    int vida;
    ALLEGRO_BITMAP *sprite;
}Obstaculo;

void dibObstaculo(Obstaculo *o);
void iniObstaculo(Obstaculo *o);
#endif