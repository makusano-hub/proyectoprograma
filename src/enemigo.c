#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include "mapa.h"
void inicioEnemigo(Enemigo *e);
void moverEnemigo(Enemigo *e,teclado *t);
void diujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);

void inicioEnemigo(Enemigo *e){

    for(int i =0; i<MAxEnemigos;i++){
    e->velocidad = 5; 
    e->sprite = al_load_bitmap("../imagenes/zombie.png");
    e->ancho = 32;
    e->alto = 32;
    e->ejex = 0;
    e->ejey = 0;

    e->vivo = false;

    e->vida = 1;
    e->dano = 1;
    }    
}
void inicioEnemigos(Enemigo enemigos[], int cantidad){
    for(int i = 0 ; i<cantidad; i++){
        inicioEnemigo(&enemigos[i]);
    }
}

void moverEnemigo(Enemigo *e,teclado *t){
    //
     for(int i =0; i<MAxEnemigos; i++){
        if( e->vivo == false){
            return;
        }
        if(e->vivo == true){
            int fila = e->ejex /cuadrado;
            int col = e->ejey /cuadrado;
   
             if(t->w)
			{
				e->ejey -= e->velocidad;
				//printf("arriba\n");
			}
			if(t->s)
			{
				e->ejey  += e->velocidad;
				//printf("abajo\n");
			}
			if(t->d)
			{
				e->ejex += e->velocidad;
				//printf("derecha\n");
			}
			if(t->a)
			{
				e->ejex -= e->velocidad;
				//printf("izquierda\n");
			}
        }
    }
    /*e->ejex -= e->velocidad;
        colision con borde no con l
        if(e->ejex + e->ancho >= 1280){
         e->ejex = 1280 - e->ancho;
            e->velocidad *= -1;
        }
        if(e->ejex <= 0){
            e->ejex = 0;
            e->velocidad *=-1;
        }*/
}

void dibujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino){
//al_draw_filled_circle(e->ejex,e->ejey,e->radio,al_map_rgb(0,255,0));
    if(e->vivo == false){
        return;
    }
    
  al_draw_scaled_bitmap(e->sprite,0,0,al_get_bitmap_width(e->sprite),al_get_bitmap_height(e->sprite),e->ejex,e->ejey,e->ancho,e->alto,0);     
}


void actualizarEnemigo(Enemigo *e){
    for(int i=0; i <MAxEnemigos; i++){   
        if(e->vivo == false)
        {
              return;
        }
        if(e->vida <= 0){
            e->vivo = false;
        }
    }
}

void inicSpawn(Portal *P, int cantidad){
    buscarPosicion('e',&P->ejex,&P->ejey);
    P-> cantmaxima = cantidad;
    P-> enemigoscreado =0;    
   
}

void spawnEnemigos(Portal *P, Enemigo enemigos[], int cantmaxima){
    if(P->enemigoscreado >= P->cantmaxima){
        return;
    }
    P->cuantoSpawn++;

    for(int i = 0; i<cantmaxima;i++){
        if(enemigos[i].vivo == false){
            enemigos[i].ejex = P->ejex;
            enemigos[i].ejey = P->ejey;
            enemigos[i].vida = 20;
            enemigos[i].vivo = true;
            P->enemigoscreado++;
            return;
        }
    }    
}


bool enemigoMeta(Enemigo *e){
    for(int i =0; i<MAxEnemigos;i++){    
        if(e->vivo== true){
            int posColumna = e->ejex/cuadrado;
            int posFila = e->ejey/cuadrado;
        if(posFila<0 || posFila >= FIL || posColumna < 0 || posColumna >= COL){
            return false;
         }
    return mapa[posFila][posColumna] == 'f';
    }
  }
}

