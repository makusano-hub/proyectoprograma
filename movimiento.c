#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "movimiento.h"


void movimiento(jugador *j){

ALLEGRO_KEYBOARD_STATE teclado;

al_get_keyboard_state(&teclado);

/*arriba y abajo acordarse explicaicon allegro si sube se resta, si baja se suma*/
if (al_key_down(&teclado, ALLEGRO_KEY_UP)) j->ejey += j->velocidad;

if (al_key_down(&teclado, ALLEGRO_KEY_DOWN)) j->ejey -= j->velocidad;

if (al_key_down(&teclado, ALLEGRO_KEY_LEFT)) j->ejex -= j->velocidad;

if (al_key_down(&teclado, ALLEGRO_KEY_RIGHT)) j->ejex += j-> velocidad;


}