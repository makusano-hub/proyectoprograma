#include "ranking.h"
#include "pantalla.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<allegro5/allegro_primitives.h>




/*bool inicRanking(UserRanking ranking[],int maximo){
    datoranking->cantidad = 0;
    datoranking->fuente = al_create_builtin_font();

    if(datoranking->fuente == NULL)
    {
        return false;
    }
    cargarRanking(datoranking);
    return true;
}*/

//iniciar
 static int cargarRanking(UserRanking ranking[],int maximo){

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
    UserRanking ranking[MaxRanker];

    int cantidad = cargarRanking(ranking,MaxRanker);
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
 /*
 void guardarRanking(char nombre[], int puntuacion){
    UserRanking user[11];
    int cantidad =0;

    FILE *archivo =fopen("ranking.txt","r");
    if(archivo!=NULL){
        while(cantidad < 11)
    }
 }
 int comparar()
 void dibuRanking(DatoRanking *datoranking);
 void destruRanking(DatoRanking *datoranking);*/