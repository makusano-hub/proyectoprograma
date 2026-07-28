#include "menu.h"
#include "pantalla.h"
#include <stdio.h>
#include<string.h>
#include <allegro5/allegro_primitives.h>

bool inicMenuP(Menu *menu){
    menu->fuente = al_create_builtin_font();
    menu->opcion = 0;

    if(menu->fuente == NULL){
        return false;
    }
    return true;
}
void seleccionMEnu(Menu *menu, int direccion){
    menu->opcion += direccion;
    if(menu->opcion < 0){
        menu->opcion = 3 -1;
    }   
    if(menu->opcion >= 3){
        menu->opcion = 0;
    }
}
Opciones obtenerOpcionMenu(Menu *menu){
    return (Opciones) menu->opcion;
}
void dibuMenuP(Menu *menu){
    char *opciones[3] = { "Jugar","Ranking","Salir"};

    int centroX = anchoP /2;
    int centroY = altoP /2 -60;

    al_draw_text(menu->fuente,al_map_rgb(255,255,255),centroX,centroY -80,ALLEGRO_ALIGN_CENTRE,"DEFENSILLA");
    for(int i =0; i<3;i++){
        int y = centroY +i *50;

            if(i==menu->opcion){
                al_draw_filled_rectangle(centroX-100,y-10,centroX+100,y+25,al_map_rgb(70,70,160));
            }
        ALLEGRO_COLOR color;
            if(i==menu->opcion){
                color = al_map_rgb(255,255,0);
            }
            else{
                color = al_map_rgb(255,255,255);
            }

            al_draw_text(menu->fuente,color,centroX,y,ALLEGRO_ALIGN_CENTRE,opciones[i]);
    }
   //al_draw_text(menu->fuente,al_map_rgb(180,180,180),centroX,altoP-60,ALLEGRO_ALIGN_CENTRE,"flechas y enter para seleccionar");
}

void destruMenuP(Menu *menu){
    if(menu->fuente !=NULL){
        al_destroy_font(menu->fuente);
        menu->fuente=NULL;
    }
}
