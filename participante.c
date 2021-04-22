#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cronista.h"
#include "Admin.h"
#include "participante.h"

#define WELCOME "¡Bienvenido, participante! ¿Que operacion desea realizar?\n"
#define OPCIONES1 "1 -Crear plantilla\n2 -Configurar plantillas\n3 -Listar plantillas\n4 -Eliminar plantilla\n5 -Ranking\n6 -Salir\n"
#define OPCIONES2 "1 -Listar jugadores en plantilla\n2 -Listar jugadores disponibles\n3 -Anadir jugador a plantilla\n4 -Eliminar jugador\n5 -Volver\n"

int loadPlantillas(char *userID, plantilla **arrayPlantilla, int *userArray, int *nPlant);
void listaPlantilla(plantilla **plantillas, int *nPlantUser, int *userArray);
void eliminarPlantilla(futPlantilla **futPlantillas, plantilla **plantillas, int *userPlantilla, int *nFutP,
                       int *nPlantUser);
int searchDeletedPlant(plantilla **, int *nPlantilla, int *index);
void nuevaPlantilla(plantilla **plantillas, config **config, int *userPlantillas, int *nPlant, int *nPlantUser,
                    char *userID);
void ranking(plantilla**, int*);

void menuConfigurar(int *userPlantillas, plantilla** plantillas, futPlantilla** futPlantillas, futbolista ** futbolistas, equipo** equipos, config **config,
                    int* nPlantUser, int* nFutP, int* nFutbolistas, int* nEquipos);

void listJugadores(futbolista**, int*);
void listPlantilla(futPlantilla**, int*, futbolista**);
void addJugadores(futPlantilla **arrayFutP, futPlantilla **userFutP, futbolista **playerData, futbolista **disponibles,
                  int *nFutP, int *nUserFutP, int *nDisponibles, char *idPlantilla, int *presupuesto, int *puntuacion);
void deleteJugadores(futPlantilla *userFutP[], futbolista *playerData[], futbolista *disponibles[], int *nUserFutP,
                     int *nDisponibles, int *nFutP, futPlantilla **arrayFutP);
int selectPlantilla(futPlantilla *localFutPlant[], futPlantilla **arrayFutPlantillas, int *userPlantillas,
                    futbolista *playerData[], futbolista **futbolistas, int *nFutP, char *plantID,
                    plantilla **arrayPlantillas, int input, int *presupuesto, int *puntuacion);
int loadDisponibles(futbolista**, futbolista*[], futPlantilla*[], int*, int*);

void bubbleSort(int [][2], int);
void swap(int* , int*, int*, int*);




void menuParticipante(char *userID, char *userName, config **config, futbolista **futbolistas, equipo **equipos,
                      plantilla **plantillas, futPlantilla **futPlantillas, int* nPlant, int* nFut, int* nEquipo, int* nFutP) {

    int input = 0;
    int nPlantUser = 0;

    int userPlantillas[3];

    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

    puts(WELCOME);

    while (input != 6) {

        puts(OPCIONES1);
        scanf("%d", &input);

        switch (input) {

            case 1: {

                if (nPlantUser < 3) {

                    nuevaPlantilla(plantillas, config, userPlantillas, nPlant, &nPlantUser, userID);

                } else puts("Ha alcanzado el número maximo de plantillas. Elimine una antes de continuar\n");
            }
            break;

            case 2:{

                if (nPlantUser != 0){
                    listaPlantilla(plantillas, &nPlantUser, userPlantillas);
                    menuConfigurar(userPlantillas, plantillas, futPlantillas, futbolistas, equipos, config, &nPlantUser, nFutP, nFut, nEquipo);
                }
                else
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
            }
            break;

            case 3: {

                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    listaPlantilla(plantillas, &nPlantUser, userPlantillas);
                }
            }
            break;

            case 4:{

                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    eliminarPlantilla(futPlantillas, plantillas, userPlantillas, nFutP, &nPlantUser);
                    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

                }
            }
            break;

            case 5:{

                ranking(plantillas, nPlant);
            }
            break;
        }
    }
}


int loadPlantillas(char* userID, plantilla** arrayPlantilla, int *userArray, int* nPlant){

    int nPlantUser = 0;

    for (int i = 0; i < (*nPlant); ++i) {

        if(strcmp((*arrayPlantilla)[i].idUsuario, userID) == 0){
            userArray[nPlantUser] = i;

            nPlantUser++;
        }
    }

    return nPlantUser;
}


void listaPlantilla(plantilla **plantillas, int *nPlantUser, int *userArray) {

    puts("Sus plantillas son:\n");

    for (int i = 0; i < (*nPlantUser); ++i) {

        printf("[%d] - %s-%s - Puntuacion: %d\n", i,
               (*plantillas)[userArray[i]].idPlantilla,
               (*plantillas)[userArray[i]].nombre,
               (*plantillas)[userArray[i]].puntuacion);
    }
}

void nuevaPlantilla(plantilla **plantillas, config **config, int *userPlantillas, int *nPlant, int *nPlantUser,
                    char *userID) {


    int index = 0;
    int found = searchDeletedPlant(plantillas, nPlant, &index);

    if(found == 1){
        char nombre[21];

        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)");
        scanf("%s", nombre);
        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            scanf("%s", nombre);
        }

        strcpy((*plantillas)[index].idUsuario, userID);
        strcpy((*plantillas)[index].nombre, nombre);
        (*plantillas)[index].presupuesto = 90;
        (*plantillas)[index].puntuacion = 0;

        userPlantillas[(*nPlantUser)] = index;
        (*nPlantUser)++;


    }

    else{
        char nombre[21];
        char plantID[4];

        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)");
        scanf("%s", nombre);
        sprintf(plantID, "%03d", (*nPlant));

        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            scanf("%s", nombre);
        }
        if((*nPlant) % 30 == 0) {
            (*plantillas) = realloc((plantilla *) (*plantillas), ((*nPlant) + 30) * sizeof(plantilla));
        }

        plantilla newPlant;
        strcpy(newPlant.idUsuario, userID),
        strcpy(newPlant.idPlantilla, plantID),
        strcpy(newPlant.nombre, nombre),
        newPlant.presupuesto = 90,
        newPlant.puntuacion = 0;

        (*plantillas)[(*nPlant)] = newPlant;
        userPlantillas[(*nPlantUser)] = (*nPlant);

        printf("Plantilla %s creada satisfactoriamente.\n", (*plantillas)[(*nPlant)].nombre);

        (*nPlantUser)++;
        (*nPlant)++;

    }
}


void eliminarPlantilla(futPlantilla **futPlantillas, plantilla **plantillas, int *userPlantilla, int *nFutP,
                       int *nPlantUser) {

    puts("Seleccione la plantilla que desea eliminar:\n");
    int input;
    char deleted[3] = "\0";

    for (int i = 0; i < (*nPlantUser); ++i) {
        printf("[%d] %s-%s-%d-%d\n", i, (*plantillas)[userPlantilla[i]].idPlantilla,
               (*plantillas)[userPlantilla[i]].nombre,
               (*plantillas)[userPlantilla[i]].presupuesto,
               (*plantillas)[userPlantilla[i]].puntuacion);
    }
    scanf("%d", &input);

    for (int i = 0; i < (*nFutP); ++i) {

        if (strcmp((*futPlantillas)[i].idPlantilla, (*plantillas)[userPlantilla[input]].idPlantilla) == 0) {
            strcpy((*futPlantillas)[i].idPlantilla, "\0");
        }
    }
    strcpy((*plantillas)[userPlantilla[input]].idUsuario, deleted);
}

int searchDeletedPlant(plantilla **arrayPlantilla, int *nPlantilla, int *index) {

    for (int i = 0; i < (*nPlantilla); ++i) {

        if(strcmp((*arrayPlantilla)[i].idUsuario, "\0") == 0){

            (*index) = i;
            return 1;
        }
    }
    return 0;
}


void menuConfigurar(int *userPlantillas, plantilla **plantillas, futPlantilla **futPlantillas, futbolista **futbolistas,
                    equipo **equipos, config** config, int *nPlantUser, int *nFutP, int *nFutbolistas, int *nEquipos) {

    int input;
    int input2 = 0;

    int nUserFutP;
    int nDisponibles;

    int presupuesto = 90;
    int puntuacion = 0;

    char* idPlantilla = malloc(3* sizeof(char));

    futPlantilla* userFutPlant = malloc(11* sizeof(futPlantilla));
    futbolista* playerData = malloc(11 * sizeof(futbolista));
    futbolista* futDisponibles = malloc(99 * sizeof(futbolista));

    puts("Introduzca el numero de la plantilla a modificar");
    scanf("%d", &input);

    while (input > 3){
        puts("Por favor, introduzca un identificador de plantilla valido");
        scanf("%d", &input);
    }


    nUserFutP = selectPlantilla(&userFutPlant, futPlantillas, userPlantillas, &playerData, futbolistas, nFutP,
                                idPlantilla, plantillas, input, &presupuesto, &puntuacion);
    nDisponibles = loadDisponibles(futbolistas, &futDisponibles, &userFutPlant, nFutbolistas, &nUserFutP);


    while (input2 != 5) {

        printf("Seleccione que operacion realizar sobre la plantilla:\n");
        puts(OPCIONES2);
        scanf("%d", &input2);

        switch (input2) {
            case 1: {
                if(nUserFutP == 0){
                    puts("La plantilla no contiene jugadores aun\n");
                }
                else{
                    listPlantilla(&userFutPlant, &nUserFutP, &playerData);
                }
            }
            break;

            case 2: {
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado\n");
                }
                else {
                    listJugadores(&futDisponibles, &nDisponibles);
                    }

            }
            break;

            case 3: {
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado\n");
                }
                else{
                    addJugadores(futPlantillas, &userFutPlant, &playerData, &futDisponibles, nFutP, &nUserFutP,
                                 &nDisponibles, idPlantilla, &presupuesto, &puntuacion);
                }
            }
            break;

            case 4: {
                if(nUserFutP == 0){
                    puts("No existen jugadores en la plantilla.\n");
                }
                else {
                    deleteJugadores(&userFutPlant, &playerData, &futDisponibles, &nUserFutP, &nDisponibles, nFutP,
                                    futPlantillas);
                    nUserFutP = selectPlantilla(&userFutPlant, futPlantillas, userPlantillas, &playerData, futbolistas,
                                                nFutP,
                                                idPlantilla, plantillas, input, &presupuesto, &puntuacion);
                    nDisponibles = loadDisponibles(futbolistas, &futDisponibles, &userFutPlant, nFutbolistas, &nUserFutP);
                }
            }
            break;
        }
    }

    (*plantillas)[input].presupuesto = presupuesto;
    (*plantillas)[input].puntuacion = puntuacion;

    free(userFutPlant);
    free(playerData);
    free(futDisponibles);
    free(idPlantilla);
}

void addJugadores(futPlantilla **arrayFutP, futPlantilla **userFutP, futbolista **playerData, futbolista **disponibles,
                  int *nFutP, int *nUserFutP, int *nDisponibles, char *idPlantilla, int *presupuesto, int *puntuacion) {

    int input = 0;
    int input2 = 0;
    do {
        puts("Por favor, seleccione de la lista el identificador de jugador a añadir:\n");
        listJugadores(disponibles, nDisponibles);
        printf("Presupuesto restante: %d\n", (*presupuesto));

        scanf("%d", &input);

        while (input >= (*nDisponibles)){
            puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2");
            scanf("%d", &input);
        }
        if((presupuesto - (*disponibles)[input].precio) > 0) {

            if (!(*nFutP) % 50) {
                (*arrayFutP) = (futPlantilla *) realloc((*arrayFutP), ((*nFutP) + 50) * sizeof(futPlantilla));
            }

            futPlantilla newFutPlan;
            strcpy(newFutPlan.idFutbolista, (*disponibles)[input].idFutbolista),
                    strcpy(newFutPlan.idPlantilla, idPlantilla);

            (*arrayFutP)[(*nFutP)] = newFutPlan;
            (*userFutP)[(*nUserFutP)] = (*arrayFutP)[(*nFutP)];
            (*playerData)[(*nUserFutP)] = (*disponibles)[input];
            strcpy((*disponibles)[input].nombre, "NULL");

            (*presupuesto) = (*presupuesto) - (*disponibles)[input].precio;
            (*puntuacion) = (*puntuacion) + (*disponibles)[input].puntuacion;
            (*nUserFutP)++;
            (*nFutP)++;
        }
        else
            puts("Presupuesto máximo excedido, imposible añadir usuario");

        puts("Desea añadir otro jugador?\n0 - Yes\n1 - No");
        scanf("%d", &input2);
    }
    while(input2 == 0);
}


void deleteJugadores(futPlantilla *userFutP[], futbolista *playerData[], futbolista *disponibles[], int *nUserFutP,
                     int *nDisponibles, int *nFutP, futPlantilla **arrayFutP) {

    int input = 0;

    puts("Por favor, seleccione el jugador a eliminar de la plantilla");

    for (int i = 0; i < (*nUserFutP); ++i) {
        printf("[%d] %s-%s\n", i, (*userFutP)[i].idFutbolista, (*playerData)[i].nombre);
    }


    scanf("%d", &input);
    while (input >= (*nDisponibles)){
        puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2\n");
        scanf("%d", &input);
    }

    for (int i = 0; i < (*nFutP); ++i) {

        if(strcmp((*userFutP)[input].idFutbolista, (*arrayFutP)[i].idFutbolista) == 0  && strcmp((*userFutP)[input].idPlantilla, (*arrayFutP)[i].idPlantilla) == 0 ){
            strcpy((*arrayFutP)[i].idPlantilla, "\0");
        }
    }
}


void listJugadores(futbolista** futDisponibles, int* nDisponibles) {

    puts("Jugadores disponibles:\n");

    for(int i = 0; i < (*nDisponibles); ++i) {
        if(strcmp((*futDisponibles)[i].nombre, "NULL")){
            printf("%d - %s-%s Precio: %d\n",i , (*futDisponibles)[i].idFutbolista, (*futDisponibles)[i].nombre, (*futDisponibles)[i].precio);

        }
    }
}

void listPlantilla(futPlantilla** futbolistasP, int* nFutPlant, futbolista** playerData){

    for (int i = 0; i < (*nFutPlant); ++i) {
        printf("%s-%s Precio: %d\n", (*futbolistasP)[i].idFutbolista,(*playerData)[i].nombre, (*playerData)[i].precio);
    }
}

int selectPlantilla(futPlantilla *localFutPlant[], futPlantilla **arrayFutPlantillas, int *userPlantillas,
                    futbolista *playerData[], futbolista **futbolistas, int *nFutP, char *plantID,
                    plantilla **arrayPlantillas, int input, int *presupuesto, int *puntuacion){
    int nFutPlant = 0;

    for (int i = 0; i < (*nFutP); ++i) {
        if(strcmp((*arrayFutPlantillas)[i].idPlantilla, (*arrayPlantillas)[userPlantillas[input]].idPlantilla) == 0){
            (*localFutPlant)[nFutPlant] = (*arrayFutPlantillas)[i];

            nFutPlant++;
        }
    }
    for (int j = 0; j < nFutPlant; ++j) {
        int counter = 0;

        do {
            if (!strcmp((*localFutPlant)[j].idFutbolista, (*futbolistas)[counter].idFutbolista)) {
                (*playerData)[j] = (*futbolistas)[counter];
                (*presupuesto) = (*presupuesto) - (*playerData)[j].precio;
                (*puntuacion) = (*puntuacion) + (*playerData)[j].puntuacion;
            }
            counter++;

        } while (strcmp((*localFutPlant)[j].idFutbolista, (*futbolistas)[counter-1].idFutbolista) != 0);
    }
    strcpy(plantID, (*arrayPlantillas)[userPlantillas[input]].idPlantilla);
    return nFutPlant;
}

int loadDisponibles(futbolista **arrayFut, futbolista **disponibles, futPlantilla **userFutPlant, int *nFutbolistas, int *nUserFutP){
    int counter = 0;
    int temp = 0;

    for (int i = 0; i < (*nFutbolistas); ++i) {
        int exist = 0;

        for (int j = 0; j < (*nUserFutP) && temp<(*nUserFutP); ++j) {
            if(!strcmp((*arrayFut)[i].idFutbolista, (*userFutPlant)[j].idFutbolista)){
                exist = 1;
                temp++;
            }
        }
        if(exist == 0){
            (*disponibles)[counter] = (*arrayFut)[i];
            counter++;
        }
    }
    return counter;
}

void ranking(plantilla** arrayPlantilla, int* nPlantillas){

    int indexArray[(*nPlantillas)][2];

    for (int i = 0; i < (*nPlantillas); ++i) {

        indexArray[i][0] = (*arrayPlantilla)[i].puntuacion;
        indexArray[i][1] = i;

        bubbleSort(indexArray, (*nPlantillas));
    }
    for (int i = 0; i < (*nPlantillas); ++i) {
        printf("[%d] %s - %s\n", (*arrayPlantilla)[indexArray[i][1]].puntuacion, (*arrayPlantilla)[indexArray[i][1]].idPlantilla, (*arrayPlantilla)[indexArray[i][1]].nombre);
    }

}

void bubbleSort(int arr[][2], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                swap(&arr[j][0], &arr[j + 1][0], &arr[j][1], &arr[j + 1][1]);
            }
        }
    }

}


void swap(int *valueA, int *valueB, int *indexA, int *indexB)
{
    int temp = *valueA;
    int temp2 = *indexA;

    *valueA = *valueB;
    *valueB = temp;

    *indexA = *valueB;
    *indexB = temp2;
}