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

bool inicMenuP(Menu *menu);
void seleccionMenu(Menu *menu, int direccion);
void dibuMenuP(Menu *menu);
void dibuMenuRanking(Menu *menu, const char nombreTemporal[]);
void destruMenuP(Menu *menu);
Opciones obtenerOpcionMenu(Menu *menu);

#endif