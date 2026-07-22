#include "obstaculo.h"
#include "jugador.h"
#include "mapa.h"


void iniRecursos(Recursos *recursos,char tipo, float x, float y, ALLEGRO_BITMAP *sprite){

    recursos->tipo = tipo;

    recursos->alto = 32;
    recursos->ancho =32;

    recursos->x = x;
    recursos->y = y;
    
    recursos->vivo = true;

    recursos->sprite = sprite;
    //buscarPosicion('r',&o->ejex,&o->ejey);

    if(tipo == 'a'){
        recursos->valor = 100;
        recursos->vivo = true;
    }
    if(tipo == 'o'){
        recursos->valor =200;
        recursos->vivo = true;
    }
    
}
void actRecursos(Recursos *recursos){
    if(recursos->valor<=0){
        recursos->valor = 0;
        recursos->vivo =false;
    }

    
}
void dibRecursos(Recursos *recursos){
    if(recursos->vivo == true){
        al_draw_scaled_bitmap(recursos->sprite,0,0,al_get_bitmap_width(recursos->sprite),al_get_bitmap_height(recursos->sprite),recursos->x,recursos->y,recursos->ancho,recursos->alto,0);
    }
    else return;
}

