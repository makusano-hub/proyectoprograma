#include "enemigo.h"
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <stdio.h>
#include <math.h>
#include "mapa.h"
void inicioEnemigo(Enemigo *e);
void moverEnemigo(Enemigo *e);
void diujoEnemigo(Enemigo *e, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);


int enemigosSpawneados = 0;

void inicioEnemigo(Enemigo *e){

    
    e->velocidad = 1.0f; 
    e->sprite = al_load_bitmap("../imagenes/zombie.png");
    e->ancho = 32;
    e->alto = 32;

    e->ejex = 0;
    e->ejey = 0;

    e->vivo = false;

    e->vida = 1;
    e->dano = 1;

    e->indiceCamino = 1;

    e->portalOrigen = -1;
     
    
    
}
void inicioEnemigos(Enemigo enemigos[], int cantidad){
    for(int i = 0 ; i<cantidad; i++){
        inicioEnemigo(&enemigos[i]);
    }
}

/*void moverEnemigo(Enemigo *e){
    
    for(int i =0; i<MAxEnemigos; i++){
        if( e->vivo == false){
            return;
        }
        if(e->vivo == true){
            int fila = e->ejex /cuadrado;
            int col = e->ejey /cuadrado;
   
            
        }
    }
    e->ejex -= e->velocidad;
        
        if(e->ejex + e->ancho >= 1280){
         e->ejex = 1280 - e->ancho;
            e->velocidad *= -1;
        }
        if(e->ejex <= 0){
            e->ejex = 0;
            e->velocidad *=-1;
        }
}*/

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

int inicSpawn(Portal portales[], int cantidadMaxima)
{
    int cantPortales = 0;

    for (int i = 0; i < FIL; i++) {
        for (int j = 0; j < COL; j++) {

            if (mapa[i][j] == 'e') {

                portales[cantPortales].ejex = j * cuadrado;
                portales[cantPortales].ejey = i * cuadrado;

                portales[cantPortales].tiempo = 0;
                portales[cantPortales].enemigosCreados = 0;
                portales[cantPortales].cantidadMaxima = 20;

                cantPortales++;
            }
        }
    }

    return cantPortales;
}
/*void spawnEnemigos(Portal portales[],int cantidadPortales, Enemigo enemigos[], int cantmaxima){

    int turnoPortal = rand() % cantidadPortales;
    int enemigoscreados = 0;
        for(int i = 0; i < cantmaxima;i++){
         
            if(enemigos[i].vivo == false){           

                enemigos[i].ejex = portales[turnoPortal].ejex;
                enemigos[i].ejey = portales[turnoPortal].ejey;
                enemigos[i].vida = 20;
                enemigos[i].vivo = true;
                enemigos[i].indiceCamino = 1;
                enemigos[i].portalOrigen = turnoPortal;                 
                enemigoscreados++;
                portales[turnoPortal].tiempo = 0 ;
                break;
            }           
        }    
}   */
void spawnEnemigos(Portal portales[], int cantidadPortales, Enemigo enemigos[], int cantMaxima)/*camiar cantMaxima a cantidadEnemigos para que no mesiga confundiendo*/
{

    if (enemigosSpawneados >= cantidadEnemigos){
        return;
    }   

    for (int p = 0; p < cantidadPortales; p++) {

        if (portales[p].tiempo < tiempo_spawn){
            continue;
        }
            

            portales[p].tiempo = 0;

        for (int i = 0; i < cantMaxima; i++) {

            if (!enemigos[i].vivo) {

                enemigos[i].ejex = portales[p].ejex;
                enemigos[i].ejey = portales[p].ejey;
                enemigos[i].vida = 20;
                enemigos[i].vivo = true;
                enemigos[i].indiceCamino = 1;
                enemigos[i].portalOrigen = p;
                enemigosSpawneados++;

                break;
            }
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

bool moverEnemigoCamino(Enemigo *e, Camino *Camino){
    if(!e->vivo){
        return false;
    }
    if (e->indiceCamino >= Camino->longitud){
        return true;
    }

    Celda destino = Camino->celdas[e->indiceCamino];

    float destinoX = destino.posColumna * cuadrado;
    float destinoY = destino.posFila *cuadrado;

    float diferenciaX = destinoX - e->ejex;
    float diferenciaY = destinoY - e->ejey;

    if(fabsf(diferenciaX)<= e->velocidad &&
        fabsf(diferenciaY)<= e->velocidad){
            e->ejex = destinoX;
            e->ejey = destinoY;

            e->indiceCamino++;

            if(e->indiceCamino >= Camino->longitud){
                return true;
            }
            return false;
        }


        if(diferenciaX > 0){
            e->ejex += e->velocidad;
        }
        else if(diferenciaX < 0){
            e->ejex -= e->velocidad;
        }
        else if(diferenciaY > 0){
            e->ejey += e->velocidad;
        }
        else if(diferenciaY < 0){
            e->ejey -= e->velocidad;
        }
        return false;
}