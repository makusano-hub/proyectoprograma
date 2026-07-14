#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <stdlib.h>
#include <stdio.h>

#include "jugador.h"
#include "movimiento.h"
#include "mapa.h"
#include "pantalla.h"


void inicJugador(Jugador *j){ 
    j->velocidad= 5;
    j->sprite = al_load_bitmap("../imagenes/jugplaceholder.png");
    j->ancho = 32;
    j->alto = 32;
    j->vida = 20;
	j->oro = 0;
	j->madera=0;
    j->ejex = 0;
    j->ejey = 0;

    buscarPosicion('j',&j->ejex,&j->ejey);
   /* for(int i=0;i< FIL; i++){
        for(int k=0; k<COL;k++){
            if (mapa[i][k] == 'j')
            {
                j->ejex = k*32;
                j->ejey = i*32;
                return;
            }
        }
    } */  

}

void actJugador(Jugador *j){

   			 if(j->ejex < 0 )
			{
				j->ejex=0;
			}
			if(j->ejex > anchoMap - j->ancho)
			{
				j->ejex = anchoMap - j->ancho;
			}
			if(j->ejey > altoMap - j->alto)
			{
				j->ejey = altoMap - j->alto;
			}
			if(j->ejey < 0)
			{
				j->ejey = 0;
			}

}

void dibuJugador(Jugador *j, ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino){
    
//aca se dibuja el sprite 
 //al_draw_filled_rectangle(j->ejex,j->ejey, j->ejex+anchoJugador, j->ejey+altoJugador,al_map_rgb(255,0,0));
  
   
    al_draw_scaled_bitmap(j->sprite,0,0,al_get_bitmap_width(j->sprite),al_get_bitmap_height(j->sprite), j->ejex, j->ejey,j->ancho,j->alto,0);
  
}

void movJugador(Jugador *j, teclado *t){
    		if(t->arriba)
			{
				j->ejey -= j->velocidad;
				//printf("arriba\n");
			}
			if(t->abajo)
			{
				j->ejey  += j->velocidad;
				//printf("abajo\n");
			}
			if(t->der)
			{
				j->ejex += j->velocidad;
				//printf("derecha\n");
			}
			if(t->izq)
			{
				j->ejex -= j->velocidad;
				//printf("izquierda\n");
			}
}