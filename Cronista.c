#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cronista.h"


void listar_equipos(int *, equipo **);
void valorar_equipos(int *, equipo **,int *, futbolista**);

// cabecera: void cronista(int *nEquipos, equipo **equipos, int *nFutbolistas, futbolista **futbolistas)
//precondicion: nEquipos y nFutbolistas son el tamaño de los vectores equipo y futbolista
//postcondicion: muestra un menú de cronista y permite listar equipos y valorar jugadores.

void cronista(int *nEquipos, equipo **equipos, int *nFutbolistas, futbolista **futbolistas){

    int n;
    do{
        printf("MENU CRONISTA\n"
               "1.-Listar equipos\n"
               "2.-Valorar equipos\n"
               "3.-Salir del programa\n");

        do{scanf("%i",&n);}
        while(n<1 && n>3);

        switch(n){
            case 1: listar_equipos(nEquipos, equipos);
                break;
            case 2: valorar_equipos(nEquipos, equipos, nFutbolistas, futbolistas);
                break;
            case 3:			//salir del programa
                break;
        }
    }while(n!=3);

};

//cabecera:void listar_equipos(int *nEquipos, equipo **equipos)
//precondicion:nEquipos es el tamaño del vector equipo
//postcondicion:muestra la lista de los equipos que hay en equipos.txt

void listar_equipos(int *nEquipos, equipo **equipos){
    printf("Lista de equipos:\n");

    int i;

    for(i=0;i<(*nEquipos);i++){
        printf("%s-%s\n",(*equipos)[i].idEquipo,(*equipos)[i].nombreEquipo);
    }

    printf("\n");

}

//cabecera:void valorar_equipos(int *nEquipos, equipo **equipos,int *nFutbolistas, futbolista **futbolistas)
//precondicion:nEquipos y nFutbolistas son el tamaño de los vectores equipo y futbolista
//postcondicion:permite modificar la puntuacion de los futbolistas

void valorar_equipos(int *nEquipos, equipo **equipos,int *nFutbolistas, futbolista **futbolistas){
    printf("Valorar equipos:\n");

    int i,idfut;
    char conf,conf2,id[3];

    do{
        printf("ID del equipo a valorar: ");
        fflush(stdin);
        fgets(id,3,stdin);

        for(i=0;i<(*nFutbolistas);i++){
            if(strcmp((*futbolistas)[i].idEquipo,id)==0){
                printf("%s - %s. Nota: %d\n",(*futbolistas)[i].idFutbolista,(*futbolistas)[i].nombre,(*futbolistas)[i].puntuacion);
            }
        }

        do{
            printf("Elija el jugador para modificar su nota:");
            scanf("%i",&idfut);

            printf("%s - %s. Nota: \n",(*futbolistas)[idfut].idFutbolista,(*futbolistas)[idfut].nombre);
            fflush(stdin);
            scanf("%i",&(*futbolistas)[idfut].puntuacion);

            printf("Quiere modificar otra puntuacion? s/n");
            fflush(stdin);
            scanf("%c",&conf);

        }while(conf=='s');

        printf("Quiere modificar puntuaciones de otro equipo? s/n");
        fflush(stdin);
        scanf("%c",&conf2);

    }while(conf2=='s');

}