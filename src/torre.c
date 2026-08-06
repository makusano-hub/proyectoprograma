#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "torre.h"

//extern char mapa[FIL][COL];

//void dibuTorres(Torre torre[MaxTorres]);
//void disparoTorre(Torre *T, Enemigo *e);

void inicTorreInicial(Torre *castillo,ConfigMap *configuracion,ALLEGRO_BITMAP *sprite){
    castillo->ejex = 0;
    castillo->ejey = 0;
    castillo->ancho = cuadrado+10;
    castillo->alto = cuadrado+10;
    castillo->activo = true;
    castillo->sprite = sprite; //al_load_bitmap("../imagenes/castelo.png");
    castillo->alcance = 320 ; //sqrt(pow(COL*cuadrado,2) +  pow(FIL*cuadrado,2)); 
    castillo->dano = 100;

    castillo->faseConstruccion=0;
    castillo->auxConstruccion =0;
    castillo->cantidadFase =1;
    castillo->construida = true;
    castillo->disparo=0;
    castillo->intervaloDisparo=240;
    buscarPosicion(configuracion,'k',&castillo->ejex,&castillo->ejey);
    
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

        torres[i].faseConstruccion =0;
        torres[i].auxConstruccion =0;
        torres[i].cantidadFase = 5; //segun la spritesheet
        torres[i].disparo = 0;
        torres[i].intervaloDisparo = 180; //cada segundo
        torres[i].construida = false;
    }
}
   // al_load_bitmap("../imagenes/torre.png");
    
bool crearTorreJugador(Torre torres[], int *cantidadTorres, Jugador *jugador,DatosJugador *dj,ConfigMap *configuracion, ALLEGRO_BITMAP *sprite,TipoTorre tipo){

    //posicionamiento jugador

    int poscolumna = (int)((jugador->ejex + jugador->ancho / 2.0f) /cuadrado);
    int posfila = (int)((jugador->ejey + jugador->alto / 2.0f) /cuadrado);

    if(posfila< 0 || posfila >= FIL || poscolumna<0 || poscolumna >=COL){
        return false;
    }

    if(dj->oro < costoOro || dj->madera < costoMadera){
        printf("no hay suficientes recursos oro %d, madera %d\n",dj->oro,dj->madera);
        return false;
         //poner ojala cuanto oro tiene el jugador como jugador->oro y jugador-->madera            
    }

    else{   
        if(*cantidadTorres < MaxTorres){

            Torre *nueva = &torres[*cantidadTorres];

            nueva->tipo = tipo;

            nueva->ejex = poscolumna * cuadrado;
            nueva->ejey = posfila *cuadrado;

            nueva->ancho=cuadrado;
            nueva->alto=cuadrado;    

            nueva->activo = true;
            nueva->sprite= sprite;

            nueva->faseConstruccion =0;
            nueva->auxConstruccion=0;
             
            nueva->disparo=0;   
            
            if(tipo == torreRapida){

                nueva->cantidadFase =1;
                nueva->construida = true;
                nueva->dano = 5;
                nueva->alcance = 192;
                nueva->intervaloDisparo = 10;
                dj->oro -= costoOroRapido;
                dj->madera -=costoMaderaRapido;
            }
            else if(tipo == torreNormal){
                nueva->cantidadFase = 5;
                nueva->construida = false;
                nueva->dano = 20;
                nueva->alcance = 320;
                nueva->intervaloDisparo = 240;
                dj->oro -= costoOro;
                dj->madera -=costoMadera;
            }
            if(configuracion->mapa[posfila][poscolumna] =='t'){

                configuracion-> mapa[posfila][poscolumna] = 'T';
                (*cantidadTorres)++;
                return true;  
            }
            if(configuracion->mapa[posfila][poscolumna] == 'c' || configuracion-> mapa[posfila][poscolumna] == 'T' || configuracion-> mapa[posfila][poscolumna] == 'e' || configuracion-> mapa[posfila][poscolumna] == 'k' || configuracion-> mapa[posfila][poscolumna] == 'f')
            {
                printf("no se puede construir en esta casiila");
                return false;
            }            
            else if(*cantidadTorres >= MaxTorres){
                return false;
            }                   
        }       
    }
    return true;
}

void construirTorre(Torre *torre){
    if(!torre->activo || torre->construida){
        return;
    }
    torre->auxConstruccion++;
    if(torre->auxConstruccion< 60 ){ //modifica el tiempo del intervalo que seconstruye ejemplo 60fps es un segundo
        return;
    }
    torre->auxConstruccion = 0;
    if(torre->faseConstruccion < torre->cantidadFase - 1){
        torre->faseConstruccion++;
    }
    if(torre->faseConstruccion >= torre->cantidadFase -1){
        torre->construida = true;
    }
}
void construirTorres(Torre torres[],int cantidadTorres){
    for(int i =0;i<cantidadTorres;i++){
        construirTorre(&torres[i]);
    }
}


    //ver si es int o bool porque si es pitagoras true o que retorne el rango unicamente
bool rango(Torre *torre, Enemigo *e){
    if(!e->vivo || !torre->activo || !torre->construida){
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
    int anchoImagen = al_get_bitmap_width(torres->sprite);
    int altoImagen = al_get_bitmap_height(torres->sprite);

    int anchoFrame = anchoImagen / torres-> cantidadFase;

    int origenX = torres->faseConstruccion * anchoFrame;
    al_draw_scaled_bitmap(torres->sprite,origenX,0,anchoFrame,altoImagen,torres->ejex,torres->ejey,torres->ancho,torres->alto+20,0);
}
  
void dibuTorreS(Torre torres[],int cantidadTorres){
    for(int i =0; i<cantidadTorres;i++){
        dibuTorre(&torres[i]);
    }
}

//anadir disparo o sea balas

