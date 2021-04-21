#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Cronista.h"
#include "Admin.h"
#include "participante.h"


#define WELCOME "¡Bienvenido, participante! ¿Que operacion desea realizar?\n"
#define OPCIONES1 "1 -Crear plantilla\n2 -Configurar plantillas\n3 -Listar plantillas\n4 -Eliminar plantilla\n5 -Ranking\n6 -Salir\n"
#define OPCIONES2 "1 -Listar jugadores en plantilla\n2 -Listar jugadores disponibles\n3 -Anadir jugador a plantilla\n4 -Eliminar jugador\n5 -Volver\n"

int loadPlantillas(char*, plantilla**,  plantilla**, int*);
void listaPlantilla(int* , plantilla** );
void eliminarPlantilla(futPlantilla **, plantilla **, plantilla **, int *nFutP, int *, int *);
void nuevaPlantilla(plantilla**, plantilla**, int*, char*, int*, int*, plantilla**, config**);

void menuConfigurar(plantilla** userPlantillas, plantilla** plantillas, futPlantilla** futPlantilla, futbolista ** futbolistas, equipo** equipos, config**,
                    int* nPlantUser, int* nFutP, int* nFutbolistas, int* nEquipos);

void listJugadores(futbolista**, int*);
void listPlantilla(futPlantilla**, int*, futbolista**);
void addJugadores(futPlantilla**, futPlantilla*[], futbolista*[], futbolista*[], int*, int*, int*, char*);
void deleteJugadores(futPlantilla*[], futbolista*[], futbolista*[], int*, int*);
int selectPlantilla(futPlantilla *[], futPlantilla**, plantilla**, futbolista*[], futbolista**, int*, char*);
int loadDisponibles(futbolista**, futbolista*[], futPlantilla*[], int*, int*);




void menuParticipante(char *userID, char *userName, config **config, futbolista **futbolistas, equipo **equipos,
                      plantilla **plantillas, futPlantilla **futPlantillas, int* nPlant, int* nFut, int* nEquipo, int* nFutP) {

    puts(userID);
    int input = 0;
    int nPlantUser = 0;
    int deletedPlant = 0;

    plantilla* delStack = NULL;
    plantilla* userPlantillas[3];

    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

    puts(WELCOME);

    while (input != 6) {

        puts(OPCIONES1);
        scanf("%d", &input);

        switch (input) {

            case 1: {

                if (nPlantUser < 3) {

                    nuevaPlantilla(plantillas, userPlantillas, &nPlantUser, userID, nPlant, &deletedPlant, &delStack, config);

                } else puts("Ha alcanzado el número maximo de plantillas. Elimine una antes de continuar\n");
            }
            break;

            case 2:{

                if (nPlantUser != 0){
                    listaPlantilla(&nPlantUser, userPlantillas);
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
                    listaPlantilla(&nPlantUser, userPlantillas);
                }
            }
            break;

            case 4:{

                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    eliminarPlantilla(futPlantillas, userPlantillas, &delStack, nFutP, &nPlantUser, &deletedPlant);

                }
            }
            break;

            case 5:{



            }
            break;

        }
    }
    free(delStack);
}


int loadPlantillas(char* userID, plantilla** arrayPlantilla, plantilla** userArray, int* nPlant){

    int nPlantUser = 0;

    for (int i = 0; i < (*nPlant); ++i) {
        if(strcmp((*arrayPlantilla)[i].idUsuario, userID) == 0){
            userArray[nPlantUser] = arrayPlantilla[i];
        }
    }

    return nPlantUser;
}


void listaPlantilla(int *nPlantUser, plantilla** userPlantillas) {

    puts("Sus plantillas son:\n");

    for (int i = 0; i < (*nPlantUser); ++i) {

        printf("%d - %s-%s - Puntuacion: %d\n", i, (*userPlantillas)[i].idPlantilla, (*userPlantillas)[i].nombre,
               (*userPlantillas)[i].puntuacion);
    }
}

void nuevaPlantilla( plantilla** plantillas, plantilla** userPlantillas, int* nPlantUser, char* userID,
                     int* nPlant, int* delPlant, plantilla** delStack, config** config){

    if((*delPlant) != 0){

        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)");
        char nombre[21];
        scanf("%s", nombre);

        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            scanf("%s", nombre);
        }
        strcpy((*delStack)[(*delPlant)-1].idUsuario, userID);
        strcpy((*delStack)[(*delPlant)-1].nombre, nombre);
        (*delStack)[(*delPlant)-1].presupuesto = 90;                /*Placeholder del numero en config donde estará el presupeuisto*/

        userPlantillas[(*nPlantUser)] = delStack[(*delPlant)-1];
        (*delPlant)--;
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
        userPlantillas[(*nPlantUser)] = plantillas[(*nPlant)];

        printf("Plantilla %s creada satisfactoriamente.\n", (*userPlantillas)[(*nPlantUser)].nombre);

        (*nPlantUser)++;
        printf("%d %s %s %s", (*nPlantUser), (*plantillas)[(*nPlant)].idUsuario, (*plantillas)[(*nPlant)].idPlantilla, (*plantillas)[(*nPlant)].nombre);

        (*nPlant)++;

    }
}


void eliminarPlantilla(futPlantilla **futPlantillas, plantilla **userPlantillas, plantilla **delStack, int *nFutP,
                       int *nPlantUser, int *deletedPlant) {

    puts("Seleccione la plantilla que desea eliminar:\n");
    int input;
    char deleted[3] = "\0";

    for (int i = 0; i < (*nPlantUser); ++i) {
        printf("[%d] %s-%s-%d-%d\n", i, (*userPlantillas)[i].idPlantilla,(*userPlantillas)[i].nombre,
               (*userPlantillas)[i].presupuesto,(*userPlantillas)[i].puntuacion);
    }
    scanf("%d", &input);

    strcpy((*userPlantillas)[input].idUsuario, deleted);

    (*deletedPlant)++;
    *delStack = realloc((plantilla *)(*delStack), (*deletedPlant) * sizeof(plantilla*));
    delStack[(*deletedPlant) - 1] = userPlantillas[input];

    userPlantillas[input] = NULL;
    (*nPlantUser)--;


}


//TODO: Check config number for maxPlayer in plantilla

void menuConfigurar(plantilla **userPlantillas, plantilla **plantillas, futPlantilla **futPlantillas, futbolista **futbolistas,
               equipo **equipos, config** config, int *nPlantUser, int *nFutP, int *nFutbolistas, int *nEquipos) {

    int input = 0;

    futPlantilla* userFutPlant = malloc(11* sizeof(futPlantilla));
    futbolista* playerData = malloc(11 * sizeof(futbolista));
    futbolista* futDisponibles = malloc(99 * sizeof(futbolista));

    char* idPlantilla = malloc(3* sizeof(char));
    int nUserFutP = selectPlantilla(&userFutPlant, futPlantillas, userPlantillas, &playerData, futbolistas, nFutP, idPlantilla);
    int nDisponibles = loadDisponibles(futbolistas, &futDisponibles, &userFutPlant, nFutbolistas, &nUserFutP);

    while (input != 5) {

        printf("Seleccione que operacion realizar sobre la plantilla:\n");
        puts(OPCIONES2);
        scanf("%d", &input);

        switch (input) {
            case 1: {
                if(nUserFutP == 0){
                    puts("La plantilla no contiene jugadores aun");
                }
                else{
                    listPlantilla(&userFutPlant, &nUserFutP, &playerData);
                }
            }
            break;

            case 2: {
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado");
                }
                else {
                    listJugadores(&futDisponibles, &nDisponibles);
                    }

            }
            break;

            case 3: {
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado");
                }
                else{
                    addJugadores(futPlantillas, &userFutPlant, &playerData, &futDisponibles, nFutP, &nUserFutP, &nDisponibles, idPlantilla);
                }
            }
            break;

            case 4: {
                deleteJugadores(&userFutPlant, &playerData, &futDisponibles, &nUserFutP, &nDisponibles);

            }
            break;
        }
    }
    free(userFutPlant);
    free(playerData);
    free(futDisponibles);
    free(idPlantilla);
}


void deleteJugadores(futPlantilla* userFutP[], futbolista* playerData[], futbolista* disponibles[], int* nUserFutP, int* nDisponibles){

    puts("Por favor, seleccione el jugador a eliminar de la plantilla");

    for (int i = 0; i < (*nUserFutP); ++i) {
        printf("%d %s-%s", i, (*userFutP)[i].idFutbolista, (*playerData)[i].nombre);
    }

    int input = 0;

    scanf("%d", &input);
    while (input >= (*nDisponibles)){
        puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2");
        scanf("%d", &input);
    }

    if((*nDisponibles) > 99){
        int found = 0;
        for (int i = 0; i < ((*nDisponibles)) && found == 0; ++i) {
            if(disponibles[i] == NULL){
                (*disponibles)[i] = (*playerData)[input];
                found = 1;
            }
        }
    }
    else{
        (*disponibles)[(*nDisponibles)] = (*playerData)[input];
        (*nDisponibles)++;
    }
    strcpy((*userFutP)[input].idPlantilla, "\0");
    playerData[input] = NULL;
}


int loadDisponibles(futbolista **arrayFut, futbolista **disponibles, futPlantilla **userFutPlant, int *nFutbolistas, int *nUserFutP) {
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

void listJugadores(futbolista** futDisponibles, int* nDisponibles) {

    puts("Jugadores disponibles:\n");

    for(int i = 0; i < (*nDisponibles); ++i) {
        if(strcmp((*futDisponibles)[i].nombre, "NULL")){
            printf("%d - %s-%s\n",i , (*futDisponibles)[i].idFutbolista, (*futDisponibles)[i].nombre);

        }
    }
}

void listPlantilla(futPlantilla** futbolistasP, int* nFutPlant, futbolista** playerData){

    for (int i = 0; i < (*nFutPlant); ++i) {
        printf("%s-%s\n", (*futbolistasP)[i].idFutbolista,(*playerData)[i].nombre);
    }
}

int selectPlantilla(futPlantilla *localFutPlant[], futPlantilla **arrayFutPlantillas, plantilla **userPlantillas,
                    futbolista *playerData[], futbolista **futbolistas, int *nFutP, char* plantID) {
    int input;
    int nFutPlant = 0;

    puts("Introduzca el numero de la plantilla a modificar");
    scanf("%d", &input);

    while (input > 3){
        puts("Por favor, introduzca un identificador de plantilla valido");
        scanf("%d", &input);
    }
    for (int i = 0; i < (*nFutP); ++i) {
        if(!strcmp((*arrayFutPlantillas)[i].idPlantilla, (*userPlantillas)[input].idPlantilla)){
            (*localFutPlant)[nFutPlant] = (*arrayFutPlantillas)[i];

            nFutPlant++;
        }
    }
    for (int j = 0; j < nFutPlant; ++j) {
        int counter = 0;

        do {
            if (!strcmp((*localFutPlant)[j].idFutbolista, (*futbolistas)[counter].idFutbolista)) {
                (*playerData)[j] = (*futbolistas)[counter];
            }
            counter++;

        } while (strcmp((*localFutPlant)[j].idFutbolista, (*futbolistas)[counter-1].idFutbolista) != 0);
    }
    strcpy(plantID, (*userPlantillas)[input].idPlantilla);
    return nFutPlant;
}

void addJugadores(futPlantilla **arrayFutP, futPlantilla **userFutP, futbolista **playerData, futbolista **disponibles,
                  int *nFutP, int *nUserFutP, int *nDisponibles, char *idPlantilla) {


    int input = 0;
    int input2 = 0;
    do {
        puts("Por favor, seleccione de la lista el identificador de jugador a añadir:\n");
        listJugadores(disponibles, nDisponibles);
        scanf("%d", &input);

        while (input >= (*nDisponibles)){
            puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2");
            scanf("%d", &input);
        }

        if(!(*nFutP) % 50){
            (*arrayFutP) = (futPlantilla*) realloc((*arrayFutP), ((*nFutP)+50) * sizeof(futPlantilla));
        }

        futPlantilla newFutPlan;
        strcpy(newFutPlan.idFutbolista, (*disponibles)[input].idFutbolista),
        strcpy(newFutPlan.idPlantilla, idPlantilla);

        (*arrayFutP)[(*nFutP)] = newFutPlan;
        (*userFutP)[(*nUserFutP)] = (*arrayFutP)[(*nFutP)];
        (*playerData)[(*nUserFutP)] = (*disponibles)[input];
        strcpy((*disponibles)[input].nombre, "NULL") ;

        (*nUserFutP)++;
        (*nFutP)++;

        puts("Desea añadir otro jugador?\n0 - Yes\n1 - No");
        scanf("%d", &input2);
    }
    while(input2 == 0);
}


