#include "bala.h"
#include <allegro5/allegro_primitives.h>
#include<math.h>
void inicBala(Bala balas[], int cantidadBalas, ALLEGRO_BITMAP * sprite){
    for (int i =0 ; i<cantidadBalas;i++)
    {        
        balas[i].x=0;
        balas[i].y=0;

        balas[i].velocidad = 10;
        balas[i].ancho= 8;
        balas[i].alto= 8;

        balas[i].objetivo = -1;
        balas[i].dano = 0;

        balas[i].direccionX = 0;
        balas[i].direccionY = 0;

        balas[i].distanciaReccorida =0;
        balas[i].distanciaMax =0;

        balas[i].activo=false;
        balas[i].sprite =sprite;
    }
}

bool dispararBala(Bala balas[], int cantidadBalas, Torre *torre,Enemigo enemigos[],int indiceEnemigo){
    if(indiceEnemigo< 0 || !enemigos[indiceEnemigo].vivo){
         return false;
    }
    for(int i =0 ;i<cantidadBalas; i++){
        if(balas[i].activo){
            continue;
        }

        float origenX = torre->ejex + torre->ancho / 2.0f;

        float origenY = torre->ejey + torre->alto / 2.0f;

        float destinoX = enemigos[indiceEnemigo].ejex + enemigos[indiceEnemigo].ancho / 2.0f;

        float destinoY = enemigos[indiceEnemigo].ejey + enemigos[indiceEnemigo].alto / 2.0f;


        float diferenciaX = destinoX - origenX;
        float diferenciaY = destinoY - origenY;

        float distancia = sqrtf(diferenciaX * diferenciaX + diferenciaY*diferenciaY);
        if(distancia <=0){
            return false;
        }
        //caculo de direccion
        balas[i].direccionX = diferenciaX / distancia;
        balas[i].direccionY = diferenciaY / distancia;

        balas[i].x = origenX - balas[i].ancho / 2.0f;
        balas[i].y = origenY - balas[i].alto / 2.0f;

        balas[i].dano = torre->dano;
        balas[i].objetivo = indiceEnemigo;

        balas[i].distanciaReccorida =0;
        balas[i].distanciaMax = torre->alcance;
        balas[i].activo = true;

        return true;


        /*
        balas[i].x = torre ->ejex + torre ->ancho / 2.0f - balas[i].ancho / 2.0f;
        balas[i].y = torre ->ejey + torre ->alto / 2.0f - balas[i].alto / 2.0f;
        
        balas[i].dano = torre->dano;
        balas[i].objetivo = indiceEnemigo;
        balas[i].activo = true;
        return true;*/
    }
    return false;
}
void actDisparoTorre(Torre *torre, Bala balas[],int cantidadBalas, Enemigo enemigos[],int cantidadEnemigos){
    if(!torre->activo || !torre->construida){
        return;
    }
    torre->disparo++;
    if(torre->disparo < torre->intervaloDisparo){
        
        return;
    }
    
    for(int i =0 ; i<cantidadEnemigos;i++){
        if(!enemigos[i].vivo){
            continue;
        }
        if(rango(torre,&enemigos[i])){
            if(dispararBala(balas,cantidadBalas,torre,enemigos,i)){
                torre->disparo = 0;
            }
        }
    }
    return;
}
void actDisparoCastillo(Torre *castillo, Torre torres[], int cantidadTorres,Bala balas[], int cantidadBalas, Enemigo enemigos[], int cantidadEnemigos){

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
void actBala(Bala balas[], int cantidadBalas,Enemigo enemigos[], int cantidadEnemigos ){
    for(int i =0; i< cantidadBalas; i++)
    {
        Bala *bala = &balas[i];

        if(!bala->activo){
            continue;
        }
        /*
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
        }*/
        bala->x += bala->direccionX * bala->velocidad;
        bala->y += bala->direccionY * bala->velocidad;

        bala->distanciaReccorida += bala->velocidad;
         
        bool impacto = false;

        for(int j =0; j< cantidadEnemigos;j++){
            if(!enemigos[j].vivo){
                continue;
            }

            bool choque = bala->x <= enemigos[j].ejex + enemigos[j].ancho &&
                bala->x + bala->ancho >= enemigos[j].ejex &&
                bala->y <= enemigos[j].ejey + enemigos[j].alto  &&
                bala->y + bala->alto >= enemigos[j].ejey;

            if(choque){

                enemigos[j].vida -= bala->dano;
                actualizarEnemigo(&enemigos[j]);

                bala->activo = false;
                bala->objetivo =-1;
                impacto =true;
                break;
            }
        }
        if(impacto){
            continue;
        }
        if(bala->distanciaReccorida >= bala->distanciaMax){
            bala->activo = false;
            bala->objetivo =-1;
        }


    }
}