#ifndef HUD_H
#define HUD_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#include "jugador.h"
#include "pantalla.h"

typedef struct{
    ALLEGRO_FONT *fuente;
}HUD;

bool initMenu(HUD *hud);

void dibuMenu(HUD *hud, Jugador *j);

void destruMenu(HUD *hud);

#endif