#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "pantalla.h"

void display(void){
al_clear_to_color(al_map_rgb(255,255,255));
al_draw_filled_rectangle(300,300,50,50,al_map_rgb(255,0,0));
al_flip_display();

}