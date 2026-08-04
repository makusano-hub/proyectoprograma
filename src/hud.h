#ifndef HUD_H
#define HUD_H

#include <stdbool.h>
#include <stdio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>

#include "jugador.h"
#include "pantalla.h"

typedef struct{
    ALLEGRO_FONT *fuente;
    ALLEGRO_BITMAP *iconoOro; 
    ALLEGRO_BITMAP *iconoMadera; 
    ALLEGRO_BITMAP *iconoVida;
    ALLEGRO_BITMAP *iconoTorre;
}HUD;

bool initMenu(HUD *hud);

void dibuMenu(HUD *hud, Jugador *j,DatosJugador *dj);

void destruMenu(HUD *hud);

#endif