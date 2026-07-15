#include "obstaculo.h"
#include "jugador.h"
#include "mapa.h"


void iniObstaculo(Obstaculo *o,float x, float y){

    o->alto = 32;
    o->ancho =32;
    o->ejex;
    o->ejey;
    o->valor=100;
    o->vida = 100;
    o->vivo = true;
    o->sprite = al_load_bitmap("../imagenes/roca.png");
}
void actObstaculo(Obstaculo *o){
    if(o->vida<=100){
        o->valor = 0;
        o->vivo =false;
    }
}
void dibObstaculo(Obstaculo *o){
    al_draw_scaled_bitmap(o->sprite,0,0,al_get_bitmap_width(o->sprite),al_get_bitmap_height(o->sprite),o->ejex,o->ejey,o->ancho,o->alto,0);
}

void iniArbol(Arbol *Ar, float x, float y){

    Ar->alto = 32;
    Ar->ancho = 32;
    Ar->valor=100;
    Ar->ejex;
    Ar->ejey;
    Ar->valor;
    Ar->vivo = true;
    Ar->sprite = al_load_bitmap("../imagenes/arbol.png");
}

void actArbol(Arbol *Ar){
    if(Ar->valor<=0){
        Ar->valor=0;
        Ar->vivo = false;
    }
}
void diArbol(Arbol *Ar){
    if(Ar->vivo == false){
        return;
    }
     al_draw_scaled_bitmap(Ar->sprite,0,0,al_get_bitmap_width(Ar->sprite),al_get_bitmap_height(Ar->sprite),Ar->ejex,Ar->ejey,Ar->ancho,Ar->alto,0);
}

void iniOro(Oro *au,float x, float y){

    au->alto = 32;
    au->ancho =32;
    au->ejex;
    au->ejey;
    au->valor=100;    
    au->vivo = true;
    au->sprite = al_load_bitmap("../imagenes/oro.png");
    buscarPosicion('o',&au->ejex,&au->ejey);
}


void diOro(Oro *au){
     if(au->vivo == false){
        return;
    }
     al_draw_scaled_bitmap(au->sprite,0,0,al_get_bitmap_width(au->sprite),al_get_bitmap_height(au->sprite),au->ejex,au->ejey,au->ancho,au->alto,0);

}

void actOro(Oro *au){
    if(au->valor<=0){
        au->valor = 0;
        au->vivo = false;
    }

}
