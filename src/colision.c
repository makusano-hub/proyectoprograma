#include <allegro5/allegro.h>
#include <stdbool.h>
#include <stdio.h>
#include "colision.h"

bool colisionJugEn(Jugador j,Enemigo e){
    if(e.vivo == false){
        return false;
    } 
    return( j.ejex <= e.ejex + e.ancho && j.ejex + j.ancho >= e.ejex &&j.ejey <= e.ejey + e.alto &&j.ejey + j.alto >= e.ejey);
    
}
bool colisionMetaEnemigo(ConfigMap *configuracion,Enemigo *e, Jugador *j,DatosJugador *dj){
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
            if(configuracion-> mapa[fila][cola]=='f'){
                dj->vida -= e->dano;
                dj->puntajeRank -= 50;
                printf("enemigo llego a meta %d\n", dj->vida);
                if(dj->vida < 0 )
                {
                    dj->vida =0;
                }
                e->vivo = false;
                    
                return true;
            }
        }
    }
     return false;
}
void colisionRecursos(Jugador *j, Recursos recursos[], int cantRecursos,DatosJugador *dj){

    int auxExtraccion = 60;
    for(int i = 0 ; i<cantRecursos;i++){
        Recursos *r = &recursos[i];
        if(r->vivo == false){
            continue;
        }

        bool choque = j->ejex <= r->x + r->ancho && j->ejex + j->ancho >= r->x && j->ejey <= r->y + r->alto  && j->ejey + j->alto >= r->y;

        bool Recoleccion = (j->tipo == lenador && r->tipo == 'a') || (j->tipo == minero && r->tipo == 'o');
        
        if(!choque || !Recoleccion){
            r->intervalo = 0;
            continue;
        }            
        if(r->valor <=0)
        {
            continue;
        }
        r->intervalo++;


        if(r->intervalo >= auxExtraccion ){
            int extraidOro = 10;
            int extraidoMadera = 20;

            if(extraidOro > r->valor || extraidoMadera > r->valor){
                extraidoMadera = r->valor;
                extraidOro = r->valor;
            }
            r->valor -= 10;
            r->intervalo = 0;
            if(r->tipo == 'a'){
                dj->madera += extraidoMadera;
            }
            if(r->tipo == 'o'){
                dj->oro += extraidOro;
            }
            actRecursos(r);
        }
    }
}