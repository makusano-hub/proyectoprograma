#include "camino.h"
#include <stdio.h>

bool celdaDisponible(char caracter){
    return caracter == 'e' || caracter == 'c' || caracter == 'f';
}

/*bool calcularCamino( char mapa[FIL][COL], char inicio, char meta, Camino * Camino){
    
    bool visitado[FIL][COL] = {false};

    int filAnterior[FIL][COL];
    int columnAnterior[FIL][COL];

    Celda cola[FIL * COL];

    int frente = 0;
    int final =0;
    Celda inicio = {-1,-1};
    Celda meta = {-1,-1};

    Camino->longitud = 0;

    for (int fila=0;fila<FIL;fila++){
        for(int columna=0;columna<COL;columna++){
                filAnterior[fila][columna]= -1;
                columnAnterior[fila][columna]=-1;

                if(mapa[fila][columna] == inicio){
                    inicio.posFila = fila;
                    inicio.posColumna=columna; 
                }

                if(mapa[fila][columna]==meta){
                    meta.posFila = fila;
                    meta.posColumna = columna;
                }

        }
    }
    if (inicio.posFila == -1 || inicio.posColumna == -1 ){
        printf("no se encontro %c \n",inicio);
        return false;
    }
    if(meta.posFila == -1 || meta.posColumna == -1){
        printf("no se encontro %c \n",meta);
        return false;
    }

    cola[final] = inicio;
    final++;

    visitado[inicio.posFila][inicio.posColumna] = true;

    const int movimientoFila[4] = {-1,1,0,0};
    const int movimientoColumna[4] = {0,0,-1,1};

    bool encontrado = false;


    while (frente<final){
        Celda actual = cola[frente];
        frente++;
        if(actual.posFila == meta.posFila && actual.posColumna == meta.posColumna){
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
    Celda actual = meta;

    while(actual.posFila !=-1 && actual.posColumna != -1){
        caminoInvertido[cantidad] = actual;
        cantidad++;
        if(actual.posFila== inicio.posFila && actual.posColumna == inicio.posColumna){
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
}*/


bool calcularCamino(char mapa[FIL][COL], int filaInicio, int columnaInicio, Camino * Camino){
    
    bool visitado[FIL][COL] = {false};

    int filAnterior[FIL][COL];
    int columnAnterior[FIL][COL];

    Celda cola[FIL * COL];

    int frente = 0;
    int final =0;
    Celda inicio = {filaInicio,columnaInicio};
    Celda meta = {-1,-1};

    Camino->longitud = 0;
    //ver si no esta fuera de matriz o posicion invalidad
    if(filaInicio < 0 || filaInicio >= FIL || columnaInicio<0 || columnaInicio>=COL){
        return false;
    }
    if(mapa[filaInicio][columnaInicio] != 'e'){
        printf("no existe portal ni en fila ni columna");
        return false;
    }

    for (int fila=0;fila<FIL;fila++){

        for(int columna=0 ;columna<COL ;columna++){

                filAnterior[fila][columna]= -1;
                columnAnterior[fila][columna]=-1;
                /*
                if(mapa[fila][columna] == inicio){
                    inicio.posFila = fila;
                    inicio.posColumna=columna; 
                }

                if(mapa[fila][columna]==meta){
                    meta.posFila = fila;
                    meta.posColumna = columna;
                }*/

        }
    } 
    /*
    if (inicio.posFila == -1 || inicio.posColumna == -1 ){
        printf("no se encontro %d %d \n",inicio.posFila,inicio.posColumna);
        return false;
    }
    if(meta.posFila == -1 || meta.posColumna == -1){
        printf("no se encontro %d %d\n",meta.posFila,meta.posColumna);
        return false;
    }*/

    cola[final] = inicio;
    final++;

    visitado[filaInicio][columnaInicio] = true;

    const int movimientoFila[4] = {-1,1,0,0};
    const int movimientoColumna[4] = {0,0,-1,1};

    bool encontrado = false;


    while (frente<final){

        Celda actual = cola[frente];
        frente++;

        if(mapa[actual.posFila][actual.posColumna] == 'f'){
            meta = actual;
            encontrado = true;
            break;
        }
        for(int direccion = 0; direccion < 4; direccion++ ){

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
    if(!encontrado){
        printf("no existe camino del portal");
        return false;
    }

    Celda caminoInvertido [FIL * COL];
    int cantidad = 0;
    Celda actual = meta;

    while(true){
        caminoInvertido[cantidad] = actual;
        cantidad++;
        if(actual.posFila == filaInicio && actual.posColumna == columnaInicio){
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