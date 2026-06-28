#ifndef mapa_H
#define mapa_H
#define FIL 25
#define COL 42
#define cuadrado 32


extern char mapa[FIL][COL];
void cargarMapa(void);
void dibujarMapa(ALLEGRO_BITMAP *terreno);

//char otenerCel(int fila, int col);
#endif


