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

    recursos->intervalo =0;
    recursos->estado=0;

    //buscarPosicion('r',&o->ejex,&o->ejey);

    if(tipo == 'a'){
        recursos->valor = 100;
        recursos->vivo = true;
    }
    else if(tipo == 'o'){
        recursos->valor =200;
        recursos->vivo = true;
    }
    else{
        recursos->valor = 0;
        recursos->vivo = false;
    }
    recursos->valorinic = recursos->valor;
}
void actRecursos(Recursos *recursos){
    if(recursos->valor<=0){
        recursos->valor = 0;        
        recursos->vivo =false;
    }
    else if(recursos->valor <=10)
    {   recursos->valor =10;
        recursos->estado = 2;
    }
    else if(recursos->valor <= recursos->valorinic /2)
    {
        recursos->estado = 1;
    }
    else{
        recursos->estado = 0;
    }

}
void dibRecursos(Recursos *recursos){
    if(recursos->vivo == true){
         
        int origen = recursos->estado * 724;

        al_draw_scaled_bitmap(recursos->sprite,origen,0,724,724,recursos->x,recursos->y,recursos->ancho,recursos->alto,0);
    
        //al_draw_scaled_bitmap(recursos->sprite,0,0,al_get_bitmap_width(recursos->sprite),al_get_bitmap_height(recursos->sprite),recursos->x,recursos->y,recursos->ancho,recursos->alto,0);
    }
    else return;
}

