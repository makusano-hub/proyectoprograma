#include "ranking.h"
#include "pantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<allegro5/allegro_primitives.h>
#include "jugador.h"


static int leerRanking(UserRanking ranking[], int maximo);
static void OrdenarPuntaje(UserRanking ranking[],int cantidad);

bool inicRanking(DatoRanking *datos){
    datos->cantidad = 0;
    datos->fuente = al_create_builtin_font();

    if(datos->fuente == NULL)
    {
        return false;
    }
    cargarRanking(datos);
    return true;
}

void cargarRanking(DatoRanking *datos){
    datos->cantidad = leerRanking(datos->usuarios,MaxRanker);
}

//iniciar
static int leerRanking(UserRanking ranking[],int maximo){

    FILE *archivo = fopen("ranking.txt","r");
    int cantidad = 0;

    if(archivo == NULL){
        return 0;
    }

    while (cantidad<maximo && fscanf(archivo,"%3s %d",
        ranking[cantidad].nombre,
        &ranking[cantidad].puntuacion) == 2)
    {
        cantidad++;
    }
    fclose(archivo);
    return cantidad;

    //falta comparar puntajes
    
}
 //ordenar
static void OrdenarPuntaje(UserRanking ranking[],int cantidad){
    for(int i = 0; i<cantidad-1;i++){
        for(int j = i+1; j< cantidad;j++){
            if(ranking[j].puntuacion > ranking[i].puntuacion){
                UserRanking auxiliar = ranking[i];
                ranking[i]= ranking[j];
                ranking[j]= auxiliar;

            }
        }
    }
}

//registrarpuntaje
bool registrarPuntaje(const char nombre[],int puntuacion){
    UserRanking ranking[MaxRanker + 1];

    int cantidad = leerRanking(ranking,MaxRanker);
    snprintf(ranking[cantidad].nombre,sizeof(ranking[cantidad].nombre),"%.3s",nombre);

    ranking[cantidad].puntuacion = puntuacion;
    cantidad++;
    
    OrdenarPuntaje(ranking,cantidad);
    if(cantidad>MaxRanker){
        cantidad = MaxRanker;
    }

    FILE *archivo =fopen("ranking.txt","w");
    for(int i=0;i<cantidad;i++){
        fprintf(archivo, "%s %d\n",ranking[i].nombre,ranking[i].puntuacion);
    }
    fclose(archivo);
    return true;
}

void dibuRanking(DatoRanking *datos){
    int centroX = anchoMap /2;
    int inicioY = 100;

    al_draw_text(datos->fuente,al_map_rgb(0,0,0),centroX,90,ALLEGRO_ALIGN_CENTRE,"RANKING");

    if(datos->cantidad == 0){
        al_draw_text(datos->fuente,al_map_rgb(80,80,80),centroX,inicioY,ALLEGRO_ALIGN_CENTRE,"no hay puntajes registrados");
    }
    for(int i =0; i< datos->cantidad; i++){
        al_draw_textf(datos->fuente,al_map_rgb(0,0,0),centroX,inicioY + i * 35, ALLEGRO_ALIGN_CENTRE," %d. %s - %d",i+1,datos->usuarios[i].nombre,datos->usuarios[i].puntuacion);
    }
    al_draw_text(datos->fuente,al_map_rgb(80,80,80),centroX,altoP-50,ALLEGRO_ALIGN_CENTRE,"ESC para salir");
}

void destruRanking(DatoRanking *datos)
{
    if(datos->fuente != NULL ){
        al_destroy_font(datos->fuente);
        datos->fuente = NULL;
    }
    datos->cantidad =0;
}