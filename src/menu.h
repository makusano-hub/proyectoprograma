#ifndef MENU_H
#define MENU_H
#include <stdbool.h>
#include<allegro5/allegro.h>
#include <allegro5/allegro_font.h>


typedef enum{
    Jugar,
    Ranking,
    salir
}Opciones;

typedef struct 
{
    ALLEGRO_FONT *fuente;
    int opcion;

}Menu;

bool inicmenu(Menu *menu);
void seleccionMenu(Menu *menu, int direccion);
void dibuMenu(Menu *menu);
void destruMenu(Menu *menu);
Opciones obtenerOpcionMenu(Menu *menu);

#endif