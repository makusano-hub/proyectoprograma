#include "camino.h"
#include <stdio.h>

bool celdaDisponible(char caracter){
    return caracter == 'e' || caracter == 'c' || caracter == 'f';
}

bool calcularCamino( char mapa[FIL][COL], char inicio, char meta, Camino * Camino){
    
    bool visitado[FIL][COL] = {false};

    int filAnterior[FIL][COL];
    int columnAnterior[FIL][COL];

    Celda cola[FIL * COL];

    int frente = 0;
    int final =0;
    Celda inicioPos = {-1,-1};
    Celda metaPos = {-1,-1};

    Camino->longitud = 0;

    for (int fila=0;fila<FIL;fila++){
        for(int columna=0;columna<COL;columna++){
                filAnterior[fila][columna]= -1;
                columnAnterior[fila][columna]=-1;

                if(mapa[fila][columna] == inicio){
                    inicioPos.posFila = fila;
                    inicioPos.posColumna=columna; 
                }

                if(mapa[fila][columna]==meta){
                    metaPos.posFila = fila;
                    metaPos.posColumna = columna;
                }

        }
    }
    if (inicioPos.posFila == -1 || inicioPos.posColumna == -1 ){
        printf("no se encontro %c \n",inicio);
        return false;
    }
    if(metaPos.posFila == -1 || metaPos.posColumna == -1){
        printf("no se encontro %c \n",meta);
        return false;
    }

    cola[final] = inicioPos;
    final++;

    visitado[inicioPos.posFila][inicioPos.posColumna] = true;

    const int movimientoFila[4] = {-1,1,0,0};
    const int movimientoColumna[4] = {0,0,-1,1};

    bool encontrado = false;


    while (frente<final){
        Celda actual = cola[frente];
        frente++;
        if(actual.posFila == metaPos.posFila && actual.posColumna == metaPos.posColumna){
            encontrado = true;
            break;
        }
        for(int direccion = 0; direccion<4;direccion++ ){
            int nuevaFila = actual.posFila + movimientoFila[direccion];
            int nuevaColumna = actual.posColumna +movimientoColumna[direccion];

            if(nuevaFila < 0 || nuevaFila >= FIL || nuevaColumna <0 || nuevaColumna >=COL){
                continue;
            }
            if(visitado[nuevaFila][nuevaColumna]){
                continue;
            }
            if(!celdaDisponible(mapa[nuevaFila][nuevaColumna])){
                continue;
            }
            visitado[nuevaFila][nuevaColumna]=true;

            filAnterior[nuevaFila][nuevaColumna]= actual.posFila;
            columnAnterior[nuevaFila][nuevaColumna]= actual.posColumna;

            cola[final].posFila = nuevaFila;
            cola[final].posColumna = nuevaColumna;
            final++;
        }
    }
    Celda caminoInvertido [FIL*COL];
    int cantidad = 0;
    Celda actual = metaPos;

    while(actual.posFila !=-1 && actual.posColumna != -1){
        caminoInvertido[cantidad] = actual;
        cantidad++;
        if(actual.posFila== inicioPos.posFila && actual.posColumna == inicioPos.posColumna){
            break;
        }
        int fAnterior = filAnterior[actual.posFila][actual.posColumna];
        int cAnterior = columnAnterior[actual.posFila][actual.posColumna];

        actual.posFila = fAnterior;
        actual.posColumna = cAnterior;
    }
    Camino->longitud = cantidad;

    for(int i =0; i< cantidad; i++){
        Camino->celdas[i] = caminoInvertido[cantidad -1 - i];
    }

    
    if(!encontrado){
        Camino->longitud = 0;
        return false; 
    }
    return true;
}