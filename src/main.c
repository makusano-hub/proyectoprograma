#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "movimiento.h"
#include "pantalla.h"
#include "enemigo.h"
#include "jugador.h"
#include "colision.h"
#include "mapa.h"


int main() {

	teclado teclado;
	Jugador Jugador;
	Enemigo Enemigo1;
	Portal spawn;
	
	al_init(); 
	al_init_image_addon();
	al_init_primitives_addon();
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
	

	bool redraw = true;
	bool running = true;

	//objeto objeto1;
	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(timer);

	cargarMapa();	
	
	inicJugador(&Jugador);
	inicioEnemigo(&Enemigo1);

	while (running){

		ALLEGRO_EVENT event;

		al_wait_for_event(queue, &event);

		if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){						
			running = false;
		}
		if(event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			teclapresionada(&teclado, event.keyboard.keycode);
		}
		if(event.type == ALLEGRO_EVENT_KEY_UP)
		{
			teclasoltada(&teclado, event.keyboard.keycode);
		}
		if(event.type == ALLEGRO_EVENT_TIMER)
		{
			moverEnemigo(&Enemigo1);
			movJugador(&Jugador,&teclado);			
			if(colisionJugEn(Jugador, Enemigo1)) {
	        	printf("Hubo colision\n");
    		}			
			actJugador(&Jugador);			
			redraw = true;
		}
		if(redraw && al_is_event_queue_empty(queue)){
			al_clear_to_color(al_map_rgb(255,255,255));
			dibujarMapa(terreno,pasto,camino,agua);
			dibuJugador(&Jugador,pasto,camino);
			dibujoEnemigo(&Enemigo1,pasto,camino);
			al_flip_display();			
			
			redraw = false;
		}
	} 
	al_destroy_bitmap(terreno);
	destruir_pantalla(display);
	al_destroy_timer(timer);   
	al_destroy_event_queue(queue);
    return 0;
}
