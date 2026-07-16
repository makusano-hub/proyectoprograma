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
                if(fila < 0 || fila>=FIL ||
                    cola<0||cola >=COL){
                    continue;
                }
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
void colisionRecursos(Jugador *j, Arbol arboles[],int cantArboles,Oro oros[],int cantOros){
    for(int i = 0 ; i<cantArboles;i++){
        if(arboles[i].vivo == true){
            if (j->ejex <= arboles[i].ejex + arboles[i].ancho &&
                j->ejex + j->ancho >= arboles[i].ejex &&
                j->ejey <= arboles[i].ejey + arboles[i].alto  &&
                j->ejey + j->alto >= arboles[i].ejey)
            {
                j->madera += arboles[i].valor;

                arboles[i].valor = 0;
                arboles[i].vivo = false;
            }
            
        }
    }
    for(int i = 0 ; i<cantOros;i++){
        if(oros[i].vivo == true){
            if (j->ejex <= oros[i].ejex + oros[i].ancho &&
                j->ejex + j->ancho >= oros[i].ejex &&
                j->ejey <= oros[i].ejey + oros[i].alto  &&
                j->ejey + j->alto >= oros[i].ejey)
            {
                j->oro += oros[i].valor;

                oros[i].valor = 0;
                oros[i].vivo = false;
            }
            
        }
    }
}