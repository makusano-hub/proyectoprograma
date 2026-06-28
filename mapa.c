#include <allegro5/allegro.h>
#include <stdlib.h>
#include <stdio.h>

#include "mapa.h"

void cargarMapa(void){
    char mapa[FIL][COL];
    FILE *nivel = fopen("nivel1.txt", "r");
    if(nivel == NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    for(int i = 0; i < FIL; i++){
        for(int j = 0; j < COL; j++){
            fscanf(nivel, "%c", &mapa[i][j]);
        }
        fscanf(nivel, "%*c");
    }
    fclose(nivel);

}

void dibujarMapa(char nivel){
    for (int i =0 ; i<FIL; i++){
        for(int j = 0 ; j<COL;){
            if(mapa[i][j]== 't')
            {
                al_draw_bitmap_region(al_load_bitmap("imagenes/terreno.png"), 0, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'c'){
                al_draw_bitmap_region(al_load_bitmap("imagenes/terreno.png"), 32, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'b'){
                al_draw_bitmap_region(al_load_bitmap("imagenes/terreno.png"), 64, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
            if(mapa[i][j]== 'f'){
                al_draw_bitmap_region(al_load_bitmap("imagenes/terreno.png"), 96, 0, 32, 32, j*cuadrado, i*cuadrado, 0);
            }
        }
    }
}