#include "participante.h"
#include "estructuras.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define WELCOME "¡Bienvenido, participante! ¿Que operacion desea realizar?\n"
#define OPCIONES1 "1 -Crear plantilla\n2 -Configurar plantillas\n3 -Listar plantillas\n4 -Eliminar plantilla\n 5 -Ranking\n6 -Salir"
#define OPCIONES2 "1 -Listar jugadores en plantilla\n2 -Listar jugadores disponibles\n3 -Añadir jugador a plantilla\n4 -Eliminar jugador\n5 -Volver"

int loadPlantillas(char*, plantilla**,  plantilla**, const int*);
void listaPlantilla(int* , plantilla** );
void eliminarPlantilla(plantilla**, int*, int*, plantilla**, futPlantilla**, int*);
void nuevaPlantilla(plantilla**, plantilla**, int*, char*, int*, int*, plantilla**, config**);
void menuConfigurar(plantilla** userPlantillas, plantilla** plantillas, futPlantilla** futPlantilla, futbolista ** futbolistas, equipo** equipos,
                    int* nPlantUser, int* nFutP, int* nFutbolistas, int* nEquipos );

void listJugadores();
void listPlantilla();
void addJugadores();
void deleteJugadores();




void menuParticipante(char *userID, char *userName, config **config, futbolista **futbolistas, equipo **equipos,
                      plantilla **plantillas, futPlantilla **futPlantillas, int* nPlant, int* nFut, int* nEquipo, int* nFutP) {

    int input = 0;
    int nPlantUser = 0;
    int deletedPlant = 0;

    plantilla* delStack = NULL;
    plantilla*  userPlantillas[3];

    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

    puts(WELCOME);

    while (input != 6) {

        puts(OPCIONES1);
        scanf("%d", &input);

        switch (input) {

            case 1: {

                if (nPlantUser < 3) {

                    nuevaPlantilla(plantillas, userPlantillas, nPlant, userID, nPlant, &deletedPlant, &delStack, config);

                } else puts("Ha alcanzado el número maximo de plantillas. Elimine una antes de continuar\n");
            }
            break;

            case 2:{

                if (nPlantUser != 0){
                    listaPlantilla(&nPlantUser, userPlantillas);
                    menuConfigurar(userPlantillas, plantillas, futPlantillas, futbolistas, equipos, &nPlantUser, nFutP, nFut, nEquipo);
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
                    listaPlantilla(&nPlantUser, userPlantillas);
                    eliminarPlantilla(plantillas, &nPlantUser, &deletedPlant, &delStack);
                }
            }

            break;

            case 5:{

                ranking();

            }
            break;

        }
    }
}


int loadPlantillas(char* userID, plantilla** arrayPlantilla, plantilla** userArray, const int* nPlant){

    int count = 0;
    int countUser = 0;

    while(count <= (*nPlant)){

        if(!strcmp((*arrayPlantilla)[count].idUsuario, userID)){
            (*userArray)[countUser] = (*arrayPlantilla)[count];
            countUser++;
            count++;
        }
        else
            count++;
    }
    return countUser;
}


void listaPlantilla(int *nPlantUser, plantilla** userPlantillas) {

    for (int i = 0; i < nPlantUser; ++i) {

        puts("Sus plantillas son:\n");
        printf("%s - %s - Puntuacion: %d\n", (*userPlantillas)[i].idPlantilla, (*userPlantillas[i]).nombre,
               (*userPlantillas)[i].puntuacion);
    }
}


void eliminarPlantilla(plantilla** userPlantillas, int* nPlantUser, int* deletedPlant, plantilla** delStack, futPlantilla** futPlantillas, int* nFutP){

    puts("Seleccione la plantilla que desea eliminar:\n");
    char* input;

    for (int i = 0; i < (*nPlantUser); ++i) {
        printf("%s - %s - %d - %d", (*userPlantillas)[(*nPlantUser)].idPlantilla,(*userPlantillas)[(*nPlantUser)].nombre,
               (*userPlantillas)[(*nPlantUser)].presupuesto,(*userPlantillas)[(*nPlantUser)].puntuacion);
    }
    gets(input);
    
    for (int i = 0; i < (*nPlantUser); ++i) {
        if(strcmp(input, (*userPlantillas)[i].idPlantilla) != 0){

            for (int j = 0; j < (*nFutP); ++j) {

                if((*futPlantillas)[j].idPlantilla == (*userPlantillas)[i].idPlantilla){
                    strcpy((*futPlantillas)[j].idPlantilla, "/0");
                }
            }
            strcpy((*userPlantillas)[i].idUsuario, "/0");
            (*nPlantUser)--;

            (*deletedPlant)++;
            *delStack = realloc((plantilla*)(*delStack), (*deletedPlant)*sizeof(plantilla));
            (*delStack)[(*deletedPlant)-1] = (*userPlantillas)[i];

        }
    }
}

void nuevaPlantilla( plantilla** plantillas, plantilla** userPlantillas, int* nPlantUser, char* userID, int* nPlant, int* delPlant, plantilla** delStack, config** config){

    if((*delPlant) != 0){
        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)");
        char* nombre;
        gets(nombre);

        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            gets(nombre);
        }
        strcpy((*delStack)[(*delPlant)-1].idUsuario, userID);
        strcpy((*delStack)[(*delPlant)-1].nombre, nombre);
        (*delStack)[(*delPlant)-1].presupuesto = (*config)[5].value;                /*Placeholder del numero en config donde estará el presupeuisto*/

        (*userPlantillas)[(*nPlantUser)] = (*delStack)[(*delPlant)-1];
        (*delPlant)--;
        (*nPlantUser)++;
    }

    else{
        char* nombre;
        char* plantID;

        gets(nombre);
        sprintf(plantID, "%03d", (*nPlant));

        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            gets(nombre);
        }
        if((*nPlant) % 30 == 0) {
            (*plantillas) = realloc((plantilla *) (*plantillas), ((*nPlant) + 30) * sizeof(plantilla));
        }

        plantilla newPlant;
        strcpy(newPlant.nombre, nombre);
        strcpy(newPlant.idUsuario, userID);
        strcpy(newPlant.idPlantilla, plantID );
        newPlant.presupuesto = (*config)[5].value;
        newPlant.puntuacion = 0;

        (*plantillas)[(*nPlant)] = newPlant;
        (*userPlantillas)[*nPlantUser] = newPlant;

        (*nPlantUser)++;
        (*nPlant)++;
    }
}

void menuConfigurar(plantilla **userPlantillas, plantilla **plantillas, futPlantilla **futPlantillas, futbolista **futbolistas,
               equipo **equipos, int *nPlantUser, int *nFutP, int *nFutbolistas, int *nEquipos) {

    int input = 0;
    int input2 = 0;
    futPlantilla futPlant[11];
    futbolista playerData[11];
    int nFutPlant = 0;

    puts("Introduzca el número de la plantilla a modificar");
    scanf("%d", &input);

    while (input > 3){
        puts("Por favor, introduzca un identificador de plantilla válido");
        scanf("%d", &input);
    }

    for (int i = 0; i < (*nFutP); ++i) {
        if(strcmp((*futPlantillas)[i].idPlantilla, (*userPlantillas)[input].idPlantilla) != 0){
            futPlant[nFutPlant] = (*futPlantillas)[i];
            nFutPlant++;
        }
    }

    while (input2 != 5) {

        printf("Seleccione qué operacion realizar sobre la plantilla: %s", (*userPlantillas)[input].nombre);
        scanf("%d", &input2);

        switch (input2) {
            case 1: {

                if(nFutPlant == 0){
                    puts("La plantilla no contiene jugadores aún");
                }
                else{
                    listPlantilla(&futPlant, nFutPlant);
                }
            }
                break;

            case 2: {
                listJugadores();

            }
                break;

            case 3: {
                addJugadores();

            }
                break;

            case 4: {
                deleteJugadores();

            }
                break;
        }
    }

}

void listPlantilla(futPlantilla** futbolistasP, int nFut){

    for (int i = 0; i <= nFut; ++i) {
        printf("%s", (*futbolistasP)[i].idFutbolista)

    }


}

void listJugadores() {

}

void addJugadores(){

}

void deleteJugadores(){

}