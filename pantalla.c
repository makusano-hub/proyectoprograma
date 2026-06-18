#include <stdio.h>
#include "pantalla.h"

ALLEGRO_DISPLAY* crear_pantalla(void) {

    ALLEGRO_DISPLAY *display;

    display = al_create_display(anchoP,altoP);

    if(display == NULL){
        printf("no se creo pantalla");
        return NULL;
    }    

    
    /*color blanco*/
    al_clear_to_color(al_map_rgb(255, 255, 255));
    al_flip_display();

    return display;
}

void destruir_pantalla(ALLEGRO_DISPLAY *display) {
    if (display != NULL) {
        al_destroy_display(display);
    }
}
