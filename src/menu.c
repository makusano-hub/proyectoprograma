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
void seleccionMenu(Menu *menu, int direccion){
    menu->opcion += direccion;
    if(menu->opcion < 0){
        menu->opcion = 2;
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

    int centroX = anchoMap /2;
    int centroY = altoMap /2 -60;

    al_draw_filled_rectangle(centroX-180,centroY-100,centroX+100,centroY+100,al_map_rgb(0,0,255));

    al_draw_text(menu->fuente,al_map_rgb(0,255,0),centroX,centroY -80,ALLEGRO_ALIGN_CENTRE,"defensa");

    for(int i =0; i<3;i++){
        int y = centroY - 55 +i *55;

            if(i==menu->opcion){
                al_draw_filled_rectangle(centroX-120,y-10,centroX+120,y+25,al_map_rgb(70,70,160));
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

void dibuMenuRanking(Menu *menu, const char nombreTemporal[]){
    int centroX = anchoMap/2;
    int centroY = altoMap/2;
    al_draw_textf(menu->fuente,al_map_rgb(0,0,0),centroX,centroY-70,ALLEGRO_ALIGN_CENTRE, "Ingrese 3letras");
    al_draw_text(menu->fuente,al_map_rgb(0,0,0),centroX,centroY,ALLEGRO_ALIGN_CENTRE,nombreTemporal);
    al_draw_textf(menu->fuente,al_map_rgb(80,80,80),centroX,centroY+50,ALLEGRO_ALIGN_CENTRE,"Enter para continuar");
}

void destruMenuP(Menu *menu){
    if(menu->fuente !=NULL){
        al_destroy_font(menu->fuente);
        menu->fuente=NULL;
    }
}
