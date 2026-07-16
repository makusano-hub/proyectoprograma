#include "hud.h"

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

bool initMenu(HUD *hud){
    hud->fuente= al_create_builtin_font();
    hud->iconoMadera = al_load_bitmap("../imagenes/iconomadera(1).png");
    hud->iconoOro = al_load_bitmap("../imagenes/iconoOro(1).png");
    hud->iconoVida = al_load_bitmap("../imagenes/iconoVida(1).png");
    if(hud->fuente == NULL){
        return false;
    }
     if(hud->iconoMadera == NULL){
        printf("no se cargo iconmadera");
        return false;
    }
     if(hud->iconoOro == NULL){
        printf("no se cargo iconoro");
        return false;
    }
     if(hud->iconoVida == NULL){
        printf("no se cargo iconvida");
        return false;
    }
    return true;

}
void dibuMenu(HUD *hud, Jugador *j){
    
    float xMenu = anchoMap;
   
    al_draw_filled_rectangle(xMenu,0, xMenu+anchoMenu, altoP,al_map_rgba(0,0,0,220));
    al_draw_rectangle(xMenu,0,xMenu+anchoMenu,altoP,al_map_rgb(255,255,255),2);

    al_draw_text(hud->fuente,al_map_rgb(255,255,255),xMenu+20,20,0,"JUGADOR");
    

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,55,0,"Vida: %d",j->vida);
    al_draw_scaled_bitmap(hud->iconoVida,0,0,al_get_bitmap_width(hud->iconoVida),al_get_bitmap_height(hud->iconoVida),xMenu+100,55,32,32,0);

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,85,0,"Oro: %d",j->oro);
    al_draw_scaled_bitmap(hud->iconoOro,0,0,al_get_bitmap_width(hud->iconoOro),al_get_bitmap_height(hud->iconoOro),xMenu+100,85,32,32,0);
       

    al_draw_textf(hud->fuente,al_map_rgb(255,80,80), xMenu+20,120,0,"Madera: %d",j->madera);
    al_draw_scaled_bitmap(hud->iconoMadera,0,0,al_get_bitmap_width(hud->iconoMadera),al_get_bitmap_height(hud->iconoMadera),xMenu+100,115,32,32,0);


}
void destruMenu(HUD *hud){
    if(hud->fuente != NULL){
        al_destroy_font(hud->fuente);
        hud->fuente = NULL;
    }
     if(hud->iconoVida != NULL){
        al_destroy_bitmap(hud->iconoVida);
        hud->iconoVida = NULL;
    }
     if(hud->iconoOro != NULL){
        al_destroy_bitmap(hud->iconoOro);
        hud->iconoOro = NULL;
    }
     if(hud->iconoMadera != NULL){
        al_destroy_bitmap(hud->iconoMadera);
        hud->iconoMadera = NULL;
    }
}
