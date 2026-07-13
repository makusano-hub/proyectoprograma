#ifndef camino_H
#define camino_H
#include <stdbool.h>
#include "mapa.h"

typedef struct{
    int posFila;
    int posColumna;
}Celda;

typedef struct{
    Celda celdas[FIL*COL];
    int longitud;
}Camino;

bool calcularCamino(char mapa[FIL][COL], char inicio, char meta, Camino *camino);
#endif
