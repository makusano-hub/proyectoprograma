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
    bool vivo;
    ALLEGRO_BITMAP *sprite;
}Obstaculo;

typedef struct
{   
    int valor;
    float ejex;
    float ejey;
    int ancho;
    int alto;
    bool vivo;
    ALLEGRO_BITMAP *sprite;
}Arbol;

typedef struct{
    int valor;
    float ejex;
    float ejey;
    int ancho;
    int alto;
    bool vivo;
    ALLEGRO_BITMAP *sprite;

}Oro;


void dibObstaculo(Obstaculo *o);
void iniObstaculo(Obstaculo *o);

void iniOro(Oro *gu);
void diOro(Oro *gu);
void actOro(Oro *gu);

void iniArbol(Arbol *Ar);
void diArbol(Arbol *Ar);
void actArol(Arbol *Ar);

#endif