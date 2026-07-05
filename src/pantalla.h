#ifndef PANTALLA_H
#define PANTALLA_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include    "mapa.h"

#define anchoP  COL*cuadrado
#define altoP    FIL*cuadrado


/*corregido pantalla*/
ALLEGRO_DISPLAY* crear_pantalla(void);

/*cerrrar pantalla*/ 
void destruir_pantalla(ALLEGRO_DISPLAY *display);

#endif
