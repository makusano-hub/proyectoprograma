#ifndef PANTALLA_H
#define PANTALLA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include    "mapa.h"

#define anchoMap COL*cuadrado
#define altoMap FIL*cuadrado
#define anchoMenu 250

#define anchoP  anchoMap + anchoMenu
#define altoP   altoMap



/*corregido pantalla*/
ALLEGRO_DISPLAY* crear_pantalla(void);

/*cerrrar pantalla*/ 
void destruir_pantalla(ALLEGRO_DISPLAY *display);

#endif
