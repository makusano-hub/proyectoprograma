#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "torre.h"

#define maxTorres 20
extern char mapa[FIL][COL];

//void dibuTorres(Torre torre[MaxTorres]);
//void disparoTorre(Torre *T, Enemigo *e);

void inicTorreInicial(Torre *castillo,ALLEGRO_BITMAP *sprite){
    castillo->ejex = 0;
    castillo->ejey = 0;
    castillo->ancho = cuadrado;
    castillo->alto = cuadrado;
    castillo->activo = true;
    castillo->sprite = al_load_bitmap("../imagenes/castelo.png");
    castillo->alcance = sqrt(pow(COL*cuadrado,2) +  pow(FIL*cuadrado,2)); 
    buscarPosicion('k',&castillo->ejex,&castillo->ejey);
    
}
/*void dibu(Torre *castillo){
     al_draw_scaled_bitmap(castillo->sprite,0,0,al_get_bitmap_width(castillo->sprite),al_get_bitmap_height(castillo->sprite),castillo->ejex,castillo->ejey,castillo->ancho,castillo->alto,0);
}*/

void inicTorres(Torre torres[],int cantidadTorres){
    for(int i =0; i<cantidadTorres;i++){

        torres[i].dano = 0;
        torres[i].alcance = 0 ;
        
        torres[i].ejex = 0;
        torres[i].ejey = 0;

        torres[i].ancho = cuadrado;
        torres[i].alto = cuadrado;

        torres[i].activo = false;
        torres[i].sprite = NULL;
    }
}
   // al_load_bitmap("../imagenes/torre.png");
    
bool crearTorreJugador(Torre torres[], int *cantidadTorres, Jugador *jugador, ALLEGRO_BITMAP *sprite){

    //posicionamiento jugador

    int poscolumna = (int)((jugador->ejex + jugador->ancho) / 2.0f)/cuadrado;
    int posfila = (int)((jugador->ejey + jugador->alto) / 2.0f)/cuadrado;

        if(jugador->oro < costoOro || jugador->madera < costoMadera){
            printf("no hay suficientes recursos oro %d, madera %d\n",jugador->oro,jugador->madera);
            //poner ojala cuanto oro tiene el jugador como jugador->oro y jugador-->madera            
        }
        else
        {   
            if(*cantidadTorres < maxTorres){

            Torre *nueva = &torres[*cantidadTorres];

            nueva->ejex = poscolumna * cuadrado;
            nueva->ejey = posfila *cuadrado;

            nueva->ancho=cuadrado;
            nueva->alto=cuadrado;

            nueva ->dano = 1;
            nueva->alcance = 192;

            nueva->activo = true;
            nueva->sprite= sprite;

            jugador->oro -= costoOro;
            jugador->madera -=costoMadera;
            mapa[posfila][poscolumna] = 'T';

            (*cantidadTorres)++;
            return true; 
            }
            else if(*cantidadTorres >= maxTorres){
                return false;
            }                   
        }
        /*ver que no hayan tores en la misma casilla de matriz
            if(mapa[i][j] == 'T' || mapa[i][j] == 'c' || mapa[i][j] == 'e' || mapa ) o una funcion que verifique y recorra si existe una torre en esa casilla
        */
        

    }

    //ver si es int o bool porque si es pitagoras true o que retorne el rango unicamente
 bool rango(Torre *torre, Enemigo *e){
    if(e->vivo == false){
        return false;
    }
    //calcular posiciones y centro de torres y enemigos
    float torreAncho = torre->ejex + torre->ancho /2;
    float torreAlto = torre->ejey + torre->alto /2;

    float torreCentroAncho = torreAncho ;
    float torreCentroAlto = torreAlto ;

    float EnemigoAncho = e->ejex + e->ancho /2;
    float EnemigoAlto = e->ejey + e->alto /2;

    float EnemigoCentroAncho = EnemigoAncho ;
    float EnemigoCentroAlto = EnemigoAlto ;

    //calcular distancias entre enemigo y torre

    float DistanciaX = torreCentroAncho - EnemigoCentroAncho;
    float DistanciaY = torreCentroAlto - EnemigoCentroAlto;

    //pitagoras para calcular las distancias 
    
    float pitagorasDistancia = sqrt(pow(DistanciaX,2) +  pow(DistanciaY,2));

    //debo implementar cual es el rango de la torre, ejemplo la distancia de pitagoras es >= rangoTorre entonces torre puede disparar
    return pitagorasDistancia<=torre->alcance;
    
 }   

 /*bool disparo(Torre *torre){
    if(torre->alcance>= pitagorasDistancia){
        return false;
    }
 }*/

 
  void dibuTorre(Torre *torres){
    if(!torres->activo){
        return;
    }
    al_draw_scaled_bitmap(torres->sprite,0,0,al_get_bitmap_width(torres->sprite),al_get_bitmap_height(torres->sprite),torres->ejex,torres->ejey,torres->ancho,torres->alto,0);
  }  
void dibuTorreS(Torre torres[],int cantidadTorres){
    for(int i =0; i<cantidadTorres;i++){
        dibuTorre(&torres[i]);
    }
}

