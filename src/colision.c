#include <allegro5/allegro.h>
#include <stdbool.h>
#include <stdio.h>
#include "colision.h"

bool colisionJugEn(Jugador j,Enemigo e){
    if(e.vivo == false){
        return false;
    } 

    return( j.ejex <= e.ejex + e.ancho &&
            j.ejex + j.ancho >= e.ejex &&
            j.ejey <= e.ejey + e.alto &&
            j.ejey + j.alto >= e.ejey);
    
}
bool colisionObsJug(Jugador j, Obstaculo o){
    return( j.ejex <= o.ejex + o.ancho &&
            j.ejex + j.ancho >= o.ejex &&
            j.ejey <= o.ejey + o.alto  &&
            j.ejey + j.alto >= o.ejey);
}
bool colisionMetaEnemigo(Enemigo *e, Jugador *j){
    if(e->vivo == false){
        return false;
    }
    int colInicio = e->ejex  /  cuadrado;
    int filInicio = e->ejey / cuadrado;

    int colFin = (e->ejex + e->ancho - 1) / cuadrado;
    int filFin = (e->ejey + e->alto -1) /cuadrado;

    for(int fila = filInicio; fila<= filFin; fila++)
    {
        for(int cola = colInicio; cola<=colFin; cola++)
            {
                if(mapa[fila][cola]=='f')
                {
                    j->vida -= e->dano;
                    printf("enemigo llego a meta %d\n", j->vida);
                    if(j->vida < 0 )
                    {
                        j->vida =0;
                    }
                    e->vivo = false;
                    
                    return true;
                }
            }
    }
     return false;
}
void colisionRecursos(Jugador *j){
    int colInicio = j->ejex  /  cuadrado;
    int filInicio = j->ejey / cuadrado;

    int colFin = (j->ejex + j->ancho - 1) / cuadrado;
    int filFin = (j->ejey + j->alto -1) /cuadrado;
        for(int fila = filInicio; fila<= filFin; fila++){
            for(int cola = colInicio; cola<=colFin; cola++){
                if(mapa[fila][cola] == 'o'){
                    j->oro += 1;

                    printf("oro");
                }
                if(mapa[fila][cola] == 'a'){
                    j->madera += 1;

                    printf("madera");
                }
            }
        }
}