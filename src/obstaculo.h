#ifndef barrera_h
#define barrera_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdbool.h>

#define MaxRecursos 100

// deberia ser solo una estructura... recurso... con tipo_rec 0, 1, 2 ....

typedef struct
{
    float x;
    float y;

    char tipo;

    int ancho;
    int alto;

    int valor;
    int valorinic;
    
    int estado;// este estado es para comparar con cantidad y alli camiar el sprite 0 es lleno, 1 es medio 2 es nada

    int intervalo;
    bool vivo;
    ALLEGRO_BITMAP *sprite;

    /* data */
}Recursos;


void iniRecursos(Recursos *recursos,char tipo, float x, float y, ALLEGRO_BITMAP *sprite);
void dibRecursos(Recursos *recursos);
void actRecursos(Recursos *recursos);

#endif