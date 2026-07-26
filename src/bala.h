#ifndef Bala_h
#define Bala_h
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

typedef struct 
{
    int x;
    int y;

    int ancho;
    int alto;

    bool activo;

    ALLEGRO_BITMAP *sprite;

}Bala;

void inicBala(void);
void dibuBala(void);
void actBala(void);


#endif