#ifndef movimiento_h
#define movimiento_h
#include <stdbool.h>
#include "jugador.h"

typedef struct
{
    bool arriba;
    bool abajo;
    bool der;
    bool izq;

} teclado;

void iniciarteclado(teclado *t);
void teclapresionada(teclado *t,int tecla);
void teclasoltada(teclado *t, int tecla);


#endif