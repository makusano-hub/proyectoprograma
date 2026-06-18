#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "movimiento.h"

void iniciarteclado(teclado *t){
    t->arriba = false;
    t->abajo = false;
    t->der = false;
    t->izq = false;
}
void teclapresionada(teclado *t, int tecla){
    switch (tecla)
    {
    case ALLEGRO_KEY_UP:
        t->arriba = true;
        break;
    
    case ALLEGRO_KEY_DOWN:
        t->abajo = true;
        break;
    
    case ALLEGRO_KEY_LEFT:
        t->izq = true;
        break;
    case ALLEGRO_KEY_RIGHT:
    t->der = true;
    break;    
    }   

}
void teclasoltada(teclado *t, int tecla){
    switch (tecla)
    {
    case ALLEGRO_KEY_UP:
        t->arriba = false;
        break;
    
    case ALLEGRO_KEY_DOWN:
        t->abajo = false;
        break;
    
    case ALLEGRO_KEY_LEFT:
        t->izq = false;
        break;
    case ALLEGRO_KEY_RIGHT:
    t->der = false;
    break;    
    }   
}