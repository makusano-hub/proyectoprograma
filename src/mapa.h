#ifndef mapa_H
#define mapa_H
#define FIL 23
#define COL 41
#define cuadrado 32


extern char mapa[FIL][COL];
void cargarMapa(void);
void dibujarMapa(ALLEGRO_BITMAP *terreno, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino, ALLEGRO_BITMAP *agua);
void buscarPosicion(char CharBusca, int *x,int *y);

//char otenerCel(int fila, int col);
#endif


