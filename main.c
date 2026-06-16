#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

/*typedef  struct 
{
	float obj_x = 400.0;
	float obj_y = 600.0;
	float velocidad = 5.0;
	bool redraw = true;
	bool correr = true;
	int vida;
	ALLEGRO_COLOR color;
} objeto;*/

int main() {
	al_init();
 
	al_init_image_addon();
	al_init_primitives_addon();
	
	ALLEGRO_DISPLAY *display = al_create_display(800,600);
	ALLEGRO_TIMER *timer = al_create_timer(1.0/ 60.0);
	ALLEGRO_EVENT_QUEUE * queue = al_create_event_queue();

	ALLEGRO_BITMAP *imagen = al_load_bitmap("dado.png");
	/*if (!imagen) {
        fprintf(stderr, "Error: No se pudo cargar la imagen.g\n");
        al_destroy_display(display);
        return -1;
    }*/


	float obj_x = 400.0;
	float obj_y = 600.0;
	float velocidad = 5.0;
	float tamano = 40.0;
	bool redraw = true;
	bool running = true;

	//objeto objeto1;
	al_install_keyboard();	
	al_register_event_source(queue, al_get_display_event_source(display));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_keyboard_event_source());




	al_start_timer(timer);

	while (running){
		ALLEGRO_EVENT event;
		al_wait_for_event(queue, &event);

		/*if(event.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
			running = false;
		}*/
		if(event.type == ALLEGRO_EVENT_KEY_DOWN){
			/*ALLEGRO_KEYBOARD_STATE key_state;
			al_get_keyboard_state(&key_state);
			*/
			if(event.keyboard.keycode == ALLEGRO_KEY_UP) 	    obj_y -=velocidad;
			if(event.keyboard.keycode ==  ALLEGRO_KEY_DOWN) 	obj_y += velocidad;
			if(event.keyboard.keycode ==  ALLEGRO_KEY_LEFT)     obj_x -= velocidad;
			if(event.keyboard.keycode ==  ALLEGRO_KEY_RIGHT)	obj_x += velocidad;	
			
			redraw = true;
		}
		if(redraw && al_is_event_queue_empty(queue)){
			al_clear_to_color(al_map_rgb(255, 255 , 255));	

			al_draw_bitmap(imagen, obj_x, obj_y, 0);

			al_draw_filled_rectangle(obj_x, obj_y, obj_x + tamano, obj_y + tamano, al_map_rgb(255, 0, 0));
			al_flip_display();
			redraw = false;
		}
		/*printf("%f %f",obj_x, obj_y);*/


	}

   
    /*

    display = al_create_display(800, 600);
    if (!display) {
        fprintf(stderr, "Error al crear la ventana\n");
        return -1;
    }

    // Fondo blanco
    al_clear_to_color(al_map_rgb(255, 255, 255));

    // Jugador: cuadrado negro de 20x20 píxeles
    int x = 390;
    int y = 290;
    int tam = 20;

    al_draw_filled_rectangle(
        x, y,
        x + tam, y + tam,
        al_map_rgb(0, 0, 0)
    );

    al_flip_display();

    al_rest(5.0);
*/
	al_destroy_bitmap(imagen);
	al_destroy_display(display);
	al_destroy_timer(timer);   
	al_destroy_event_queue(queue);
    return 0;
}
