#ifndef mapa_H
#define mapa_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define FIL 23
#define COL 41
#define cuadrado 32


extern char mapa[FIL][COL];
extern int cantidadEnemigos;

void cargarMapa(void);
void dibujarMapa(ALLEGRO_BITMAP *terreno, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino, ALLEGRO_BITMAP *agua, ALLEGRO_BITMAP *oro, ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *portal);
bool buscarPosicion(char CharBusca, float *x,float *y);

//char otenerCel(int fila, int col);
#endif


