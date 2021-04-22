#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Headers/Cronista.h"


void listar_equipos(int *, equipo **);
void valorar_equipos(int *, equipo **,int *, futbolista**);

//cabecera: void cronista(int *nEquipos, equipo **equipos, int *nFutbolistas, futbolista **futbolistas)
//precondicion: nEquipos y nFutbolistas son el tamaño de los vectores equipo y futbolista
//postcondicion: muestra un menú de cronista y permite listar equipos y valorar jugadores.

void cronista(int *nEquipos, equipo **equipos, int *nFutbolistas, futbolista **futbolistas) {

    int n;
    do {
        printf("MENU CRONISTA\n"
               "1.-Listar equipos\n"
               "2.-Valorar equipos\n"
               "3.-Cerrar sesion\n");

        do {
            scanf("%i",&n);
            fflush(stdin);
        }
        while(n<1 && n>3);

        switch(n) {
        case 1:
            listar_equipos(nEquipos, equipos);
            break;
        case 2:
            valorar_equipos(nEquipos, equipos, nFutbolistas, futbolistas);
            break;
        case 3:			//salir del programa
            break;
        }
    } while(n!=3);

};

//cabecera:void listar_equipos(int *nEquipos, equipo **equipos)
//precondicion:nEquipos es el tamaño del vector equipo
//postcondicion:muestra la lista de los equipos que hay en equipos.txt

void listar_equipos(int *nEquipos, equipo **equipos) {
    int i;

    printf("Lista de equipos:\n");
    for(i=0; i<(*nEquipos); i++) {
        if((*equipos)[i].idEquipo[0] != '\0')
            printf("%s - %s\n", (*equipos)[i].idEquipo,(*equipos)[i].nombreEquipo);
    }
    printf("\n");
}

//cabecera:void valorar_equipos(int *nEquipos, equipo **equipos,int *nFutbolistas, futbolista **futbolistas)
//precondicion:nEquipos y nFutbolistas son el tamaño de los vectores equipo y futbolista
//postcondicion:permite modificar la puntuacion de los futbolistas

void valorar_equipos(int *nEquipos, equipo **equipos,int *nFutbolistas, futbolista **futbolistas) {
    printf("Valorar equipos:\n");

    int i;
    char idfut[3];
    char conf,conf2,id[3];

    do {
        printf("ID del equipo a valorar: ");
        fflush(stdin);
        fgets(id,3,stdin);
        strtok(id, "\n");
        for(i=0; i<(*nFutbolistas); i++) {
            if(strcmp((*futbolistas)[i].idEquipo,id)==0) {
                printf("%s - %s. Nota: %d\n",(*futbolistas)[i].idFutbolista,(*futbolistas)[i].nombre,(*futbolistas)[i].puntuacion);
            }
        }

        do {
            int n = 0;
            printf("Elija el jugador para modificar su nota:");
            fflush(stdin);
            fgets(idfut,3,stdin);
            strtok(idfut,"\n");

            i = 0;
            while(i<(*nFutbolistas) && strcmp((*futbolistas)[i].idFutbolista,idfut)!=0)
                i++;
            do
            {
                printf("%s - %s. Nota: %d\n\n Introduzca nueva puntuacion: ",(*futbolistas)[i].idFutbolista,(*futbolistas)[i].nombre,(*futbolistas)[i].puntuacion);
                fflush(stdin);
                scanf("%i", &n);

                if(n >= 0 && n <= 10)
                    (*futbolistas)[i].puntuacion = n;
                else
                    printf("\n Valor incorrecto, debe estar entre 0 y 10 (ambos incluidos)\n");
            } while(n < 0 || n > 10);

            printf("Quiere modificar otra puntuacion? s/n: ");
            fflush(stdin);
            scanf("%c",&conf);

        } while(conf=='s');

        printf("Quiere modificar puntuaciones de otro equipo? s/n: ");
        fflush(stdin);
        scanf("%c",&conf2);

    } while(conf2=='s');
}
