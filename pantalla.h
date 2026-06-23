#ifndef PANTALLA_H
#define PANTALLA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

#define anchoP 1280
#define altoP   720


/*corregido pantalla*/
ALLEGRO_DISPLAY* crear_pantalla(void);

/*cerrrar pantalla*/ 
void destruir_pantalla(ALLEGRO_DISPLAY *display);

#endif
