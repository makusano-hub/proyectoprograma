#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#include "movimiento.h"

void iniciarteclado(teclado *t){
    t->arriba = false;
    t->abajo = false;
    t->der = false;
    t->izq = false;
    t->w = false;
    t->s = false;
    t->a = false;
    t->d = false;
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
    case ALLEGRO_KEY_ENTER:
        
        break;        
    
    case ALLEGRO_KEY_W:
        t->w = true;
        break;
    case ALLEGRO_KEY_S:
        t->s = true;
        break;
    case ALLEGRO_KEY_D:
        t->d = true;
        break;
    case ALLEGRO_KEY_A:
        t->a = true;
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
    
    case ALLEGRO_KEY_W:
        t->w = false;
        break;
    case ALLEGRO_KEY_S:
        t->s = false;
        break;
    case ALLEGRO_KEY_D:
        t->d = false;
        break;
    case ALLEGRO_KEY_A:
        t->a = false;
        break;
    }   
}