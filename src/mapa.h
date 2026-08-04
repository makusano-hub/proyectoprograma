#ifndef mapa_H
#define mapa_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#include "obstaculo.h"

#define FIL 23
#define COL 41
#define cuadrado 32

#define anchoFramePortal 64
#define altoFramePortal 64 
#define framTickPortal 8
#define cantFramePortal 8
typedef struct 
{
    char mapa[FIL][COL];
    int cantidadEnemigos; 
    int enemigosSpawneados;
}ConfigMap;


//extern char mapa[FIL][COL];
//extern int cantidadEnemigos;

//void cargarMapa(Recursos recursos[], ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *oro, int *cantRecursos);
bool cargarMapa(const char *nombreArchivo,ConfigMap *configuracion, Recursos recursos[],ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *oro, int *cantRecursos);
void dibujarMapa(ConfigMap *configuracion,ALLEGRO_BITMAP *terreno, ALLEGRO_BITMAP *pasto, 
    ALLEGRO_BITMAP *camino, ALLEGRO_BITMAP *agua, ALLEGRO_BITMAP *oro, ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *sheetPortal,ALLEGRO_BITMAP *casa,int framePortal);
bool buscarPosicion(ConfigMap *configuracion, char CharBusca, float *x,float *y);

//void contarRecursos(Arbol arboles[], int *cantidadArboles, Oro oros[], int *cantidadOros);

//char otenerCel(int fila, int col);
#endif


