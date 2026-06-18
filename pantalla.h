#ifndef PANTALLA_H
#define PANTALLA_H

#include <allegro5/allegro.h>

#define anchoP   800
#define altoP  600


/*corregido pantalla*/
ALLEGRO_DISPLAY* crear_pantalla(void);

/*cerrrar pantalla*/ 
void destruir_pantalla(ALLEGRO_DISPLAY *display);

#endif
