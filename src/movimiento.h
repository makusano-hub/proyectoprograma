#ifndef movimiento_h
#define movimiento_h

#include <allegro5/allegro.h>
#include "teclado.h"



void iniciarteclado(teclado *t);
void teclapresionada(teclado *t,int tecla);
void teclasoltada(teclado *t, int tecla);


#endif