#ifndef barrera_h
#define barrera_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

#define MaxOro  100
#define MaxArboles  100

typedef struct 
{
    int valor;
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

void iniObstaculo(Obstaculo *o,float x, float y);
void dibObstaculo(Obstaculo *o);
void actObstaculo(Obstaculo *o);

void iniOro(Oro *gu, float x, float y);
void diOro(Oro *gu);
void actOro(Oro *gu);

void iniArbol(Arbol *Ar,float x, float y);
void diArbol(Arbol *Ar);
void actArbol(Arbol *Ar);

#endif