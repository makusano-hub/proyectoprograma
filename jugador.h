#ifndef jugador_h
#define jugador_h

typedef struct 
{
  float ejex;
  float ejey;
  float velocidad;
  int vida;   /* data */
  ALLEGRO_BITMAP *sprite;
}jugador;

void inicjugador(jugador *j, float ejex, float ejey);
void actJugador(jugador *j, float ejex, float ejey);
void dibuJugador(jugador *j);

#endif
