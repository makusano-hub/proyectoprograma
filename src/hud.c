#include "hud.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

bool initMenu(HUD *hud){
    hud->fuente= al_create_builtin_font();

    if(hud->fuente == NULL){
        return false;
    }
    return true;
}
void dibuMenu(HUD *hud, Jugador *j){
    float xMenu = anchoMap;
   
    al_draw_filled_rectangle(xMenu,0, xMenu+anchoMenu, altoP,al_map_rgba(0,0,0,220));
    al_draw_rectangle(xMenu,0,xMenu+anchoMenu,altoP,al_map_rgb(255,255,255),2);

    al_draw_text(hud->fuente,al_map_rgb(255,255,255),xMenu+20,20,0,"JUGADOR");

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,60,0,"Vida: %d",j->vida);

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,90,0,"Oro: %d",j->oro);

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,120,0,"Madera: %d",j->madera);


}
void destruMenu(HUD *hud){
    if(hud->fuente != NULL){
        al_destroy_font(hud->fuente);
        hud->fuente = NULL;
    }
}
