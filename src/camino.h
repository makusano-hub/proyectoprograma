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

bool calcularCamino(char mapa[FIL][COL], int filaInicio, int columnaInicio, Camino *camino);
#endif
