#ifndef Jugador_h
#define Jugador_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#define anchoJugador 32
#define altoJugador 32


typedef struct 
{
  float ejex;
  float ejey;
  float velocidad;
  int vida;   /* data */
  int ancho;
  int alto;
  ALLEGRO_BITMAP *sprite;
}Jugador;

void inicJugador(Jugador *j);
void actJugador(Jugador *j, float ejex, float ejey);
void dibuJugador(Jugador *j,ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);


#endif
