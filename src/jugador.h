#ifndef Jugador_h
#define Jugador_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "movimiento.h"
#include "mapa.h"

#define anchoJugador 32
#define altoJugador 32

#define anchoframeJug 64
#define altoFramejug 64
#define FramesJug 5
#define FramesTickJug 8

#define minero 0
#define lenador 1
#define entidades 2


typedef struct 
{

  char nombre[4];
  int puntajeRank;

  float ejex;
  float ejey;

  float velocidad;
  int vida;   /* data */
  int oro;
  int madera;

  float casillaX;
  float casillaY;
  bool activo;
 
  int ancho;
  int alto;

  int frameActual;
  int filaAnimacion;
  int contadorAnimacion;
  bool moviendose;

  

  ALLEGRO_BITMAP *sprite;
}Jugador;

void inicJugador(Jugador *j,ConfigMap *configuracion,ALLEGRO_BITMAP *sprite);
void actJugador(Jugador *j);
void dibuJugador(Jugador *j,ALLEGRO_BITMAP *pasto, ALLEGRO_BITMAP *camino);
void movJugador(Jugador *j, teclado *t);

void cambiarJugador(Jugador *j);
void animacionJugador(Jugador *j);

#endif
