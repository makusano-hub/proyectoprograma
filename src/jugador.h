#ifndef Jugador_h
#define Jugador_h

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "movimiento.h"
#include "mapa.h"
#define nombreJug 3

#define anchoJugador 32
#define altoJugador 32

#define anchoframeJug 64
#define altoFramejug 64
#define FramesJug 5
#define FramesTickJug 8

#define MaxJugadores 2

#define minero 1
#define lenador 0
//#define entidades 2

typedef struct{
  char nombre[nombreJug+1];
  int puntajeRank;

  int vida;
  int oro;
  int madera;

}DatosJugador;


typedef struct 
{

  //char nombre[4];
  //int puntajeRank;
  int tipo;

  float ejex;
  float ejey;

  float velocidad;
  //int vida;   
  //int oro;
  //int madera;

  float casillaX;
  float casillaY;
  bool activo;
 
  int ancho;
  int alto;

  int frameActual;
  int filaAnimacion;
  int contadorAnimacion;
  bool moviendose;

  DatosJugador *datos;

  ALLEGRO_BITMAP *sprite;
}Jugador;


void inicDatosJugador(DatosJugador *dj);
void inicJugador(Jugador *j,int tipo,float x, float y,ALLEGRO_BITMAP *sprite,DatosJugador *dj);

void inicJugadores(Jugador jugadores[],ConfigMap *configuracion,ALLEGRO_BITMAP *sprites[],DatosJugador *dj);

void actJugador(Jugador *j);
void dibuJugador(Jugador *j);
void dibuJugadores(Jugador jugadores[],int cantidad, int jugadoActivo);

void movJugador(Jugador *j, teclado *t);

void cambiarJugador(Jugador jugadores[],int *jugadorActivo);
void animacionJugador(Jugador *j);

#endif
