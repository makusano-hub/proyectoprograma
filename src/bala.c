#include "bala.h"

void inicBala(Bala balas[], int cantidadBalas, ALLEGRO_BITMAP * sprite){
    for (int i =0 ; i<cantidadBalas;i++)
    {
        balas[i].activo=false;
        balas[i].x=0;
        balas[i].y=0;
        balas[i].velocidad = 10;
        balas[i].ancho= 8;
        balas[i].alto= 8;
        balas[i].objetivo = -1;
        balas[i].dano = 0;
        balas[i].sprite =sprite;
    }
}
bool dispararBala(Bala balas[], int cantidadBalas, Torre *torre,Enemigo enemigos[],int indiceEnemigo){
    
}

void dibuBala(Bala balas[], int cantidadBalas){
    for(int i = 0 ; i<cantidadBalas; i++){
        if(!balas[i].activo){
            continue;
        }
        if(balas[i].sprite!=NULL){
            al_draw_scaled_bitmap(balas[i].sprite,0,0,al_get_bitmap_width(balas[i].sprite ),al_get_bitmap_height(balas[i].sprite),balas[i].x,balas[i].y,balas[i].ancho,balas[i].alto,0);
        }
    }

}
void actBalas(Bala balas[], int cantidadBalas,Enemigo enemigos[], int cantidadEnemigos ){
    for(int i =0; i< cantidadBalas; i++)
    {
        Bala *bala = &balas[i];

        if(!bala->activo){
            continue;
        }
        if(bala->objetivo < 0 || bala -> objetivo >= cantidadEnemigos){
            bala->activo = false;
            bala ->objetivo = -1;
            continue;
        }
        Enemigo *objetivo = &enemigos[bala->objetivo];
        if(!objetivo->vivo){
            bala->activo = false;
            bala ->objetivo = -1;
            continue;
        }





    }
}