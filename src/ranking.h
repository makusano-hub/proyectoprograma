#ifndef RANKING_H
#define RANKING_H

#include <stdbool.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>

#define MaxRanker 10
#define LargoNombre 3

typedef struct{
    char nombre[LargoNombre + 1];
    int puntuacion;
}UserRanking;

bool registro(const char nombre[], int puntuacion);
/*
 typedef struct{
    UserRanking usuarios[10];
    int cantidad;
    ALLEGRO_FONT *fuente;
 }DatoRanking;

 bool inicRanking(DatoRanking *datoranking);
 void cargarRanking(DatoRanking *datoranking);
 void guardarRanking(char nombre[], int puntuacion);
 void dibuRanking(DatoRanking *datoranking);
 void destruRanking(DatoRanking *datoranking);
*/
 #endif