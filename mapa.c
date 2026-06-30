#include <allegro5/allegro.h>
#include <stdlib.h>
#include <stdio.h>

#include "mapa.h"

char mapa[FIL][COL];

void cargarMapa(void){
    
    FILE *nivel = fopen("matriz.txt", "r");
    if(nivel == NULL){
        printf("Error al abrir el archivo\n");
        return;
    }
    for(int i = 0; i < FIL; i++){
        for(int j = 0; j < COL; j++){
            fscanf(nivel, "%c", &mapa[i][j]);
        }
        fscanf(nivel, "%*c");
    }
    fclose(nivel);

}

void dibujarMapa(ALLEGRO_BITMAP *terreno){
      
    for (int i =0 ; i<FIL; i++){
        for(int j = 0 ; j<COL;j++){
           
            if(mapa[i][j]== 't')/*tierra*/
            {
                al_draw_bitmap_region(terreno, 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'c'){/*camino*/
                al_draw_bitmap_region(terreno, 32, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'b'){/*roca*/
                al_draw_bitmap_region(terreno,64, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'f'){/*meta*/
                al_draw_bitmap_region(terreno, 96, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
        }
    }
}