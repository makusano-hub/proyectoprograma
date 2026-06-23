#include <stdio.h>
#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "movimiento.h"
#include "pantalla.h"
#include "enemigo.h"
#include "jugador.h"


int main() {

	teclado teclado;
	jugador jugador;
	enemigo enemigo1;
	al_init();
 
	al_init_image_addon();
	al_init_primitives_addon();

	al_install_keyboard();	
	iniciarteclado(&teclado);
	
	
	ALLEGRO_DISPLAY *display = crear_pantalla();
	ALLEGRO_TIMER *timer = al_create_timer(1.0/ 60.0);
	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();

	ALLEGRO_BITMAP *fondo = al_load_bitmap("imagenes/fondo1280x720.png");	

	bool redraw = true;
	bool running = true;

	//objeto objeto1;
	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());

	al_start_timer(timer);
	
	inicjugador(&jugador,400,550);
	inicioEnemigo(&enemigo1,200,550);
	
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
			moverEnemigo(&enemigo1);

			if(teclado.arriba)
			{
				jugador.ejey -= jugador.velocidad;
			}
			if(teclado.abajo)
			{
				jugador.ejey  += jugador.velocidad;
			}
			if(teclado.der)
			{
				jugador.ejex += jugador.velocidad;
			}
			if(teclado.izq)
			{
				jugador.ejex -= jugador.velocidad;
			}

			if(jugador.ejex < 0 )
			{
				jugador.ejex=0;
			}
			if(jugador.ejex>anchoP-anchojugador)
			{
				jugador.ejex = anchoP-anchojugador;
			}
			if(jugador.ejey > altoP-altojugador)
			{
				jugador.ejey = altoP-altojugador;
			}
			if(jugador.ejey < 0)
			{
				jugador.ejey = 0;
			}

			redraw = true;
		}
		if(redraw && al_is_event_queue_empty(queue)){
		//	al_clear_to_color(al_map_rgb(255,255,255));
			al_draw_bitmap(fondo,0,0,0);

			dibuJugador(&jugador);
			dibujoEnemigo(&enemigo1);
			al_flip_display();			
			
			redraw = false;
		}
	} 
/*
	al_destroy_bitmap(imagen);*/
	destruir_pantalla(display);
	
	al_destroy_timer(timer);   
	al_destroy_event_queue(queue);
    return 0;
}
