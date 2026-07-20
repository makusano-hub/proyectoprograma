#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>

#include "movimiento.h"
#include "pantalla.h"
#include "enemigo.h"
#include "jugador.h"
#include "colision.h"
#include "mapa.h"
#include "hud.h"
#include "camino.h"
#include "torre.h"
#include "obstaculo.h"

int main() {

	teclado teclado;
	Jugador Jugador;
	Enemigo enemigos[MAxEnemigos];
	Portal spawn[MaxPortales];
	Recursos recursos[MaxRecursos] = {0};

	/*Arbol arboles[MaxArboles];
	Oro oros[MaxOro];*/

	HUD hud;
	Camino caminoEnemigos[MaxPortales];
	Torre castillo;
	Torre torres[MaxTorres];

	int cantidadTorres =0;
	//int cantidadEnemigos =0;
	int cantidadPortales = 0;
	int cantRecursos =0;	

	srand(time(NULL));
	
	al_init(); 
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_font_addon();
	al_install_keyboard();	
	iniciarteclado(&teclado);
	
	
	
	ALLEGRO_DISPLAY *display = crear_pantalla();
	ALLEGRO_TIMER *timer = al_create_timer(1.0/ 60.0);
	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();

	//ALLEGRO_BITMAP *fondo = al_load_bitmap("imagenes/fondo1280x720.png");	
	ALLEGRO_BITMAP *terreno = al_load_bitmap("../imagenes/terreno.png");
	ALLEGRO_BITMAP *pasto = al_load_bitmap("../imagenes/GrassCenter.png");
	ALLEGRO_BITMAP *camino = al_load_bitmap("../imagenes/muro.png");
	ALLEGRO_BITMAP *agua = al_load_bitmap("../imagenes/agua.png");
	ALLEGRO_BITMAP *oro = al_load_bitmap("../imagenes/oro.png");
	ALLEGRO_BITMAP *arbol = al_load_bitmap("../imagenes/arbol.png");
	ALLEGRO_BITMAP *portal = al_load_bitmap("../imagenes/portal.png");
	ALLEGRO_BITMAP *torre = al_load_bitmap("../imagenes/torre.png");
	ALLEGRO_BITMAP *castelo = al_load_bitmap("../imagenes/castelo.png");

	//spritesheet para "animacion"
	/*
	ALLEGRO_BITMAP *enemigobasico = al_load_bitmap(../imagenes/enemigobasico.png);
	ALLEGRO_BITMAP *enemigofuerte = al_load_bitmap(../imagenes/enemigofuerte.png);
	

	al_draw_scaled_bitmap(enemigobasico,)
	*/

	

	bool redraw = true;
	bool running = true;

	//objeto objeto1;
	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	cargarMapa(recursos,arbol,oro,&cantRecursos);
	initMenu(&hud);

	//contarRecursos(arboles,&cantidadArboles,oros,&cantidadOros);
	
	cantidadPortales = inicSpawn(spawn,MaxPortales);
	
	if(!calcularCamino(mapa,'e','f',&caminoEnemigos)){
		printf("no se calculo camino de enemigo");
		return 1;
	}

	inicJugador(&Jugador);
	inicTorres(torres,MaxTorres);

	inicTorreInicial(&castillo,castelo);
	
	inicioEnemigos(enemigos, MAxEnemigos);
	//inicSpawn(spawn, cantidadPortales);

	while (running){
		
		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){						
			running = false;
		}
		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			teclapresionada(&teclado, event.keyboard.keycode);
				if(event.keyboard.keycode == ALLEGRO_KEY_ENTER){
					crearTorreJugador(torres,&cantidadTorres,&Jugador,torre);
				}
		}
		if(event.type == ALLEGRO_EVENT_KEY_UP)
		{
			teclasoltada(&teclado, event.keyboard.keycode);
		}
		if(event.type == ALLEGRO_EVENT_TIMER)
		{	

			for (int i = 0; i < cantidadPortales; i++) {
   					 spawn[i].tiempo++;
					}

			spawnEnemigos(spawn,cantidadPortales,enemigos,MAxEnemigos);

			for(int i =0; i< MAxEnemigos; i++){
				if(!enemigos[i].vivo){
					continue;
				}							
			
				moverEnemigoCamino(&enemigos[i],&caminoEnemigos[enemigos[i].portalOrigen]);//cambiar que cada enemigo calcule su camino
				colisionMetaEnemigo(&enemigos[i], &Jugador);
			}
			
			//moverEnemigo(&enemigo,&teclado);
			movJugador(&Jugador,&teclado);
			actJugador(&Jugador);				
			colisionRecursos(&Jugador, recursos, cantRecursos);
			if(Jugador.vida <=0){
				running = false;
			}				
					
			redraw = true;
		}
		if(redraw && al_is_event_queue_empty(queue)){
			al_clear_to_color(al_map_rgb(255,255,255));
			dibujarMapa(terreno,pasto,camino,agua,oro,arbol,portal);

			for(int i =0; i<cantRecursos; i++){
				dibRecursos(&recursos[i]);
			}

			/*for(int i=0; i<cantidadArboles;i++){
				diArbol(&arboles[i]);
			}
			for(int i=0; i<cantidadOros;i++){
				diOro(&oros[i]);	
			}		*/				

			dibuJugador(&Jugador,pasto,camino);
			dibuTorre(&castillo);
			dibuTorreS(torres,cantidadTorres);

			for(int i =0; i<MAxEnemigos;i++)
			{
				dibujoEnemigo(&enemigos[i],pasto,camino);
			}		
			dibuMenu(&hud,&Jugador);
			al_flip_display();			
			
			redraw = false;
		}
	} 
	al_destroy_bitmap(terreno);
	al_destroy_bitmap(pasto);	
	al_destroy_bitmap(oro);
	al_destroy_bitmap(arbol);
	
	
	destruMenu(&hud);
	destruir_pantalla(display);
	al_destroy_timer(timer);   
	al_destroy_event_queue(queue);
    return 0;
}
