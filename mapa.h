#ifndef mapa_H
#define mapa_H
#define FIL 25
#define COL 42
#define cuadrado 32


void cargarMapa(char nivel[]);
void dibujarMapa(void);

char otenerCel(int fila, int col);
#endif

