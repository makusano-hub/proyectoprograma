#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "mapa.h"
#include "jugador.h"
#include "enemigo.h"
#include "obstaculo.h"

//Portal spawn[10];//variable globales

bool cargarMapa(const char *nombreArchivo,ConfigMap *configuracion,Recursos recursos[],ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *oro, int *cantRecursos){
    FILE *nivel = fopen(nombreArchivo,"r");
    if(nivel == NULL){
        printf("error al abrir el archivo\n");
        return false;
    }
    *cantRecursos =0;
    if(fscanf(nivel,"%d",&configuracion->cantidadEnemigos)!= 1){
        printf("cantidad de enemigos inconclusa");
        fclose(nivel);
        return false;
    }
    for(int i = 0; i < FIL; i++){
        for(int j = 0; j < COL; j++){
            fscanf(nivel, " %c", &configuracion->mapa[i][j]);
            //ALLEGRO_BITMAP *sprite = NULL;          
           
            if (configuracion -> mapa[i][j]=='a')
            {
                iniRecursos(&recursos[*cantRecursos], 'a',j * cuadrado, i * cuadrado,arbol);
                (*cantRecursos)++;
            }
            else if (configuracion->mapa[i][j] == 'o')
            {
                iniRecursos(&recursos[*cantRecursos], 'o',j * cuadrado, i * cuadrado,oro);
                (*cantRecursos)++;
            }     
           
            //else if (... == 'o')
        }
        //fscanf(nivel, "%c", &aux); 
    }
 fclose(nivel);
 return true;
    
}

void dibujarMapa(ConfigMap *configuracion,
                    ALLEGRO_BITMAP *terreno , 
                    ALLEGRO_BITMAP *pasto, 
                    ALLEGRO_BITMAP *camino, 
                    ALLEGRO_BITMAP *agua, 
                    ALLEGRO_BITMAP *oro, 
                    ALLEGRO_BITMAP *arbol,                   
                    ALLEGRO_BITMAP *sheetPortal,
                    ALLEGRO_BITMAP *casa,
                    ALLEGRO_BITMAP *aldea,
                    ALLEGRO_BITMAP *castelo,
                    int framePortal){
    
    for (int i =0 ; i<FIL; i++){        
        for(int j = 0 ; j<COL;j++){
           
            if(configuracion-> mapa[i][j]== 't' || configuracion-> mapa[i][j]== 'j' ||configuracion->  mapa[i][j]== 'o' || configuracion-> mapa[i][j]== 'a' ||configuracion->  mapa[i][j]=='T' )/*tierra*/
            {
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
            }
            if(configuracion-> mapa[i][j] == 'l')
            {                
               al_draw_bitmap(agua, j*cuadrado, i*cuadrado, 0);
            }           
            if(configuracion-> mapa[i][j]== 'c' || configuracion-> mapa[i][j] == 'e')
            {
                al_draw_bitmap(camino, j*cuadrado, i*cuadrado, 0);
            }                    
            if(configuracion-> mapa[i][j]== 'f')
            {
                al_draw_bitmap(pasto, j*cuadrado,i*cuadrado,0);
                al_draw_scaled_bitmap(aldea,0,0,al_get_bitmap_width(aldea),al_get_bitmap_height(aldea),j*cuadrado,i*cuadrado,cuadrado,cuadrado,0);
            }
            if(configuracion-> mapa[i][j]== 'e')
            {
                int origenX =framePortal *anchoFramePortal;
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
                al_draw_scaled_bitmap(sheetPortal,origenX,0,anchoFramePortal,altoFramePortal,j*cuadrado,i*cuadrado,cuadrado,cuadrado,0);              
            }
            
            if(configuracion->mapa[i][j] == '.')
            {
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
                al_draw_scaled_bitmap(casa,0,0,al_get_bitmap_width(casa),al_get_bitmap_height(casa),j* cuadrado, i*cuadrado,cuadrado,cuadrado,0 );
            }
            if(configuracion->mapa[i][j] == 'j')
            {
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);                
            }
            int columnaTileCastillo = -1;
            int filaTileCastillo = -1;
            if(configuracion-> mapa[i][j]== 'k')
            {
               columnaTileCastillo = 0;
                filaTileCastillo = 0;          
            }
            if(configuracion->mapa[i][j] == 'h'){
                columnaTileCastillo = 1;
                filaTileCastillo = 0;
            }
            if(configuracion->mapa[i][j] == 'v'){
                columnaTileCastillo =2;
                filaTileCastillo =0;
            }
            if(configuracion->mapa[i][j] == '2'){
                columnaTileCastillo =1;
                filaTileCastillo =1;
            }
            if(configuracion->mapa[i][j] == '1'){
                columnaTileCastillo =0;
                filaTileCastillo=1;
            }
            if(configuracion->mapa[i][j]=='3'){
                columnaTileCastillo=2;
                filaTileCastillo=1;
            }
            if(configuracion->mapa[i][j]=='4'){
                columnaTileCastillo=3;
                filaTileCastillo=1;
            }
            if(columnaTileCastillo !=-1 && filaTileCastillo !=-1){
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);

                int origenXK =columnaTileCastillo *cuadrado;
                int origenYK = filaTileCastillo *cuadrado;

                al_draw_bitmap_region(castelo,origenXK,origenYK,cuadrado,cuadrado,j*cuadrado,i*cuadrado,0);
            }
        }
    }
}   
bool buscarPosicion(ConfigMap *configuracion,char CharBusca,float *x, float *y){
    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            if(configuracion-> mapa[i][j] == CharBusca){
                *x= j * cuadrado;
                *y= i * cuadrado;
                return true;
            }
        }
    }
    return false;
}