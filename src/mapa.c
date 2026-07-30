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
        printf("cantidad de enemigos inconclusa",nombreArchivo);
         fclose(nivel);
        return false;
    }
    for(int i = 0; i < FIL; i++){
        for(int j = 0; j < COL; j++){
            fscanf(nivel, " %c", &configuracion->mapa[i][j]);
            //ALLEGRO_BITMAP *sprite = NULL;          
           
            if (configuracion -> mapa[i][j]=='a')
            {
                iniRecursos(&recursos[*cantRecursos], 'a',
                j * cuadrado, i * cuadrado,
                arbol);
                (*cantRecursos)++;
            }
            else if (configuracion->mapa[i][j] == 'o')
            {
                iniRecursos(&recursos[*cantRecursos], 'o',
                j * cuadrado, i * cuadrado,
                oro);
                 (*cantRecursos)++;
            }     
           
            //else if (... == 'o')
        }
        //fscanf(nivel, "%c", &aux); 
    }
    fclose(nivel);
   return true;
    
}


/*void cargarMapgita(Recursos recursos[], ALLEGRO_BITMAP *arbol, ALLEGRO_BITMAP *oro,int *cantRecursos){
    char aux;
    int cantSpawn = 0;
    *cantRecursos  = 0; 

    //AGREGAR un int para poder cargar siguiente matriz / nivel ejemplo base es matriz.txt, si es 1, matriz2.txt, y etc etc.
    
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
            //ALLEGRO_BITMAP *sprite = NULL;
            
            if(mapa[i][j]== 'e'){               
                cantSpawn++;
            }
            else if (mapa[i][j]=='a')
            {
                iniRecursos(&recursos[*cantRecursos], 'a',
                j * cuadrado, i * cuadrado,
                arbol);
                (*cantRecursos)++;
            }
            else if (mapa[i][j] == 'o')
            {
                iniRecursos(&recursos[*cantRecursos], 'o',
                j * cuadrado, i * cuadrado,
                oro);
                 (*cantRecursos)++;
            }     
           
            //else if (... == 'o')
        }
        fscanf(nivel, "%c", &aux); 
    }
     //(*cantRecursos)++;
    fclose(nivel);    
}*/

void dibujarMapa(ConfigMap *configuracion,
                    ALLEGRO_BITMAP *terreno , 
                    ALLEGRO_BITMAP *pasto, 
                    ALLEGRO_BITMAP *camino, 
                    ALLEGRO_BITMAP *agua, 
                    ALLEGRO_BITMAP *oro, 
                    ALLEGRO_BITMAP *arbol,                   
                    ALLEGRO_BITMAP *sheetPortal,
                    int framePortal){
    
    for (int i =0 ; i<FIL; i++){        
        for(int j = 0 ; j<COL;j++){
           
            if(configuracion-> mapa[i][j]== 't' || configuracion-> mapa[i][j]== 'j' ||configuracion->  mapa[i][j]== 'o' || configuracion-> mapa[i][j]== 'a' ||configuracion->  mapa[i][j]=='T' )/*tierra*/
            {
                //al_draw_bitmap_region(pasto, 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
            }
            if(configuracion-> mapa[i][j] == 'l')
            {
                //al_draw_filled_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 255, 255));
                //al_draw_bitmap_region(terreno, 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
               al_draw_bitmap(agua, j*cuadrado, i*cuadrado, 0);
            }           
            if(configuracion-> mapa[i][j]== 'c' || configuracion-> mapa[i][j] == 'e'){
                 //al_draw_rectangle(j*cuadrado, i*cuadrado, j*cuadrado+cuadrado, i*cuadrado+cuadrado, al_map_rgb(255, 255, 0), 1);
                 //al_draw_bitmap_region(camino, 32, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
                al_draw_bitmap(camino, j*cuadrado, i*cuadrado, 0);
            }                    
           if(configuracion-> mapa[i][j]== 'f'){
                al_draw_bitmap(pasto, j*cuadrado,i*cuadrado,0);
                al_draw_rectangle(j*cuadrado,i*cuadrado, j*cuadrado + cuadrado, i*cuadrado+cuadrado,al_map_rgb(255,0,0),1);
            }
            if(configuracion-> mapa[i][j]== 'e'){
                int origenX =framePortal *anchoFramePortal;
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
                al_draw_scaled_bitmap(sheetPortal,origenX,0,anchoFramePortal,altoFramePortal,j*cuadrado,i*cuadrado,cuadrado,cuadrado,0);
                //al_draw_bitmap(sheetPortal,j*cuadrado, i*cuadrado,0);                
            }
            if(configuracion-> mapa[i][j]== 'k'){
                al_draw_bitmap(pasto,j*cuadrado,i*cuadrado,0);
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

/*void contarRecursos(Arbol arboles[], int *cantidadArboles, Oro oros[], int *cantidadOros){
    *cantidadArboles =0;
    *cantidadOros =0;

    for(int i = 0; i<FIL ; i++){
        for(int j = 0; j<COL ;j++){
            if(mapa[i][j]== 'a'){
                if(*cantidadArboles<MaxArboles){
                    iniArbol(&arboles[*cantidadArboles],j*cuadrado, i*cuadrado);
                    (*cantidadArboles)++;
                }         
            }

            else if(mapa[i][j]== 'o'){
                if(*cantidadOros<MaxOro){
                    iniOro(&oros[*cantidadOros], j*cuadrado, i*cuadrado);
                    (*cantidadOros)++;
                }
            }
        }
    }
}*/