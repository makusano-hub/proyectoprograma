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
/*bool colisionObsJug(Jugador j, Recursos recursos){
    return( j.ejex <= recursos.x + recursos.ancho &&
            j.ejex + j.ancho >= recursos.x &&
            j.ejey <= recursos.y + recursos.alto  &&
            j.ejey + j.alto >= recursos.y);
}*/
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
void colisionRecursos(Jugador *j, Recursos recursos[], int cantRecursos){
    for(int i = 0 ; i<cantRecursos;i++){
        Recursos *r = &recursos[i];
        if(recursos->vivo == false){
            continue;
        }

        if(recursos->tipo == 'a'){
            if (j->ejex <= r->x + r->ancho &&
                j->ejex + j->ancho >= r->x &&
                j->ejey <= r->y + r->alto  &&
                j->ejey + j->alto >= r->y)
            {
                    //aca el jugador saca el recurso instantaneamente
                j->madera += r->valor;

                r->valor = 0;
                r->vivo = false;
            }
            
        }       
        if(recursos->tipo == 'o'){
            if (j->ejex <= r->x + r->ancho &&
                j->ejex + j->ancho >= r->x &&
                j->ejey <= r->y + r->alto  &&
                j->ejey + j->alto >= r->y)
            {

                //aca saca el recurso el jugador instantaneamente
                j->oro += r->valor;

                r->valor = 0;
                r->vivo = false;
            }
            
        }
    }
}