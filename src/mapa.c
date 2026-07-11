#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "mapa.h"
#include "jugador.h"
#include "enemigo.h"

char mapa[FIL][COL];
int cantidadEnemigos = 0;
Portal spawn[10];



void cargarMapa(void){
    char aux;
    int cantSpawn;
    int portalFil;
    int portalCol;
    
    FILE *nivel = fopen("matriz.txt", "r");
    if(nivel == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    fscanf(nivel, "%d\n",&cantidadEnemigos); //lee el numero anterior de la matriz para cantidad de enemigos
    //fscanf(nivel,"%c",&aux); // soluciona problema de corrido al generar la matriz
    //leer matriz
    for(int i = 0; i < FIL; i++){
        for(int j = 0; j < COL; j++){
            fscanf(nivel, "%c", &mapa[i][j]);
            if(mapa[i][j]== 'e'){
                portalFil = i;
                portalCol = j;
            }
        }
        fscanf(nivel, "%c", &aux); 
    }
    fclose(nivel);    
}

void dibujarMapa(ALLEGRO_BITMAP *terreno , ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino, ALLEGRO_BITMAP *agua, ALLEGRO_BITMAP *oro, ALLEGRO_BITMAP *arbol,ALLEGRO_BITMAP *portal){
    
    for (int i =0 ; i<FIL; i++){        
        for(int j = 0 ; j<COL;j++){
           
            if(mapa[i][j]== 't')/*tierra*/
            {
                //al_draw_bitmap_region(pasto, 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
            }
            if(mapa[i][j] == 'l')
            {
                //al_draw_filled_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 255, 255));
                //al_draw_bitmap_region(terreno, 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
               al_draw_bitmap(agua, j*cuadrado, i*cuadrado, 0);
            }           
            if(mapa[i][j]== 'c' || mapa[i][j] == 'e'){
                 //al_draw_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 255, 0), 1);
                 //al_draw_bitmap_region(camino, 32, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
                al_draw_bitmap(camino, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'o'){
               // al_draw_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 255, 255), 1);
               al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
               al_draw_bitmap(oro,j*cuadrado,i*cuadrado,0);
            }
            if(mapa[i][j]== 'a'){
                //al_draw_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 0, 255), 1);
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
                al_draw_bitmap(arbol,j*cuadrado,i*cuadrado,0);
            }
            if(mapa[i][j]== 'f'){
                al_draw_bitmap(pasto, j*cuadrado,i*cuadrado,0);
                al_draw_rectangle(j*cuadrado,i*cuadrado, j*cuadrado + cuadrado, i*cuadrado+cuadrado,al_map_rgb(255,0,0),1);
            }
            if(mapa[i][j]== 'e'){
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
                al_draw_bitmap(portal,j*cuadrado, i*cuadrado,0);
                
            }
        }

    }
}   
bool buscarPosicion(char CharBusca,float *x, float *y){
    for(int i=0;i<FIL;i++){
        for(int j=0;j<COL;j++){
            if(mapa[i][j] == CharBusca){
                *x= j * cuadrado;
                *y= i * cuadrado;
                return true;
            }
        }
    }
    return false;
}