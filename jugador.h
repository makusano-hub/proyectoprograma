#ifndef jugador_h
#define jugador_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define anchojugador 32
#define altojugador 32


typedef struct 
{
  float ejex;
  float ejey;
  float velocidad;
  int vida;   /* data */
  int ancho;
  int alto;
  ALLEGRO_BITMAP *sprite;
}jugador;

void inicjugador(jugador *j, float ejex, float ejey);
void actJugador(jugador *j, float ejex, float ejey);
void dibuJugador(jugador *j);

#endif
