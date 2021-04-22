#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Headers/Cronista.h"
#include "Headers/Admin.h"
#include "Headers/participante.h"

#define WELCOME "Bienvenido, participante! Que operacion desea realizar?\n"
#define OPCIONES1 "1 -Crear plantilla\n2 -Configurar plantillas\n3 -Listar plantillas\n4 -Eliminar plantilla\n5 -Ranking\n6 -Salir\n"
#define OPCIONES2 "1 -Listar jugadores en plantilla\n2 -Listar jugadores disponibles\n3 -Anadir jugador a plantilla\n4 -Eliminar jugador\n5 -Volver\n"

int loadPlantillas(char *userID, plantilla **arrayPlantilla, int *userArray, int *nPlant);
void listaPlantilla(plantilla **arrayPlantillas, int *nPlantUser, int *userArray);
void eliminarPlantilla(futPlantilla **futPlantillas, plantilla **plantillas, int *userPlantilla, int *nFutP,
                       int *nPlantUser);
int searchDeletedPlant(plantilla **, int *nPlantilla, int *index);
void nuevaPlantilla(plantilla **arrayPlantillas, config **config, int *userPlantillas, int *nPlant, int *nPlantUser,
                    char *userID);
void ranking(plantilla**, int*);

void menuConfigurar(int *userPlantillas, plantilla **plantillas, futPlantilla **futPlantillas, futbolista **futbolistas,
                    config **config, int *nPlantUser, int *nFutP, int *nFutbolistas);

void listJugadores(futbolista**, int*);
void listPlantilla(futPlantilla**, int*, futbolista**);
void addJugadores(futPlantilla **arrayFutP, futPlantilla **userFutP, futbolista **playerData, futbolista **disponibles,
                  int *nFutP, int *nUserFutP, int *nDisponibles, char *idPlantilla, int *presupuesto, int *puntuacion);
void deleteJugadores(futPlantilla *userFutP[], futbolista *playerData[], int *nUserFutP, int *nFutP,
                     futPlantilla **arrayFutP);
int selectPlantilla(futPlantilla *localFutPlant[], futPlantilla **arrayFutPlantillas, int *userPlantillas,
                    futbolista *playerData[], futbolista **futbolistas, int *nFutP, char *plantID,
                    plantilla **arrayPlantillas, int input, int *presupuesto, int *puntuacion);
int loadDisponibles(futbolista**, futbolista*[], futPlantilla*[], int*, int*);

void bubbleSort(int [][2], int);
void swap(int* , int*, int*, int*);



/// menuParticipante - Inicia el menú correspondiente al perfil de usuario "Participante"
/// \param userID - Identificador numérico de dos digitos del usuario.
/// \param config - Array de estructuras de tipo config
/// \param futbolistas - Array de estructuras tipo futbolista
/// \param equipos - Array de estructuras tipo equipo
/// \param plantillas - Array de estructuras tipo plantilla
/// \param futPlantillas - Array de estructuras tipo futPlantilla
/// \param nPlant - Tamaño del array de tipo plantilla
/// \param nFut - Tamaño del array de tipo futbolista
/// \param nEquipo - Tamaño del array de tipo Equipo
/// \param nFutPlantilla - Tamaño del array de tipo futPlantilla

void menuParticipante(char *userID, config **config, futbolista **futbolistas, equipo **equipos, plantilla **plantillas,
                      futPlantilla **futPlantillas, int *nPlant, int *nFut, int *nEquipo, int *nFutPlantilla) {

    int input = 0;

    int nPlantUser;
    int userPlantillas[(*config)[0].value]; /*Vector de tamaño (max_plantillas), contiene los pares índice - posicion en el
                                              vector de estructuras correspondientes a las plantillas del usuario */

    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

    puts(WELCOME);

    while (input != 6) {

        puts(OPCIONES1);
        fflush(stdin);
        scanf("%d", &input);
        while (input>6 || input < 0){
            puts(OPCIONES1);
            puts("Introduzca un valor valido");
            fflush(stdin);
            scanf("%d", &input);

        }

        switch (input) {
            case 1:
                if (nPlantUser < (*config)[0].value) {

                    nuevaPlantilla(plantillas, config, userPlantillas, nPlant, &nPlantUser, userID);

                } else puts("Ha alcanzado el numero maximo de plantillas. Elimine una antes de continuar\n");
            break;

            case 2:
                if (nPlantUser != 0){
                    listaPlantilla(plantillas, &nPlantUser, userPlantillas);
                    menuConfigurar(userPlantillas, plantillas, futPlantillas, futbolistas, config, &nPlantUser,
                                   nFutPlantilla, nFut);
                }
                else
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
            break;

            case 3:
                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else
                    listaPlantilla(plantillas, &nPlantUser, userPlantillas);
            break;

            case 4:
                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    eliminarPlantilla(futPlantillas, plantillas, userPlantillas, nFutPlantilla, &nPlantUser);
                    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);
                }
            break;

            case 5:
                ranking(plantillas, nPlant);
            break;
        }
    }
}

/// Realiza una búsqueda sobre el array de Plantilla, si userID == Plantilla.userID, asigna el índice
/// i-esimo al vector de int userArray, creando pares indice - indice de estructura.
/// \param userID - Identificador de usuario.
/// \param arrayPlantilla - Array de estructuras tipo Plantilla
/// \param userArray - Array que almacena los indices de las plantillas del usuario dentro de arrayPlantilla.
/// \param nPlant - Tamaño de arrayPlantilla.
/// \return nPlantUser - Numero de plantillas con mismo userID que el usuario.

int loadPlantillas(char* userID, plantilla **arrayPlantilla, int *userArray, int* nPlant){

    int nPlantUser = 0;

    for (int i = 0; i < (*nPlant); ++i) {

        if(strcmp((*arrayPlantilla)[i].idUsuario, userID) == 0){
            userArray[nPlantUser] = i;
            nPlantUser++;
        }
    }
    return nPlantUser;
}

/// Muestra por pantalla las plantillas del usuario. (userID == plantilla.userID)
/// \param arrayPlantillas - Array de estructuras tipo Plantilla.
/// \param nPlantUser - Tamaño de userArray.
/// \param userArray - Array que contiene los índices de las estructuras de usuario en arrayPlantillas.

void listaPlantilla(plantilla **arrayPlantillas, int *nPlantUser, int *userArray) {

    puts("Sus plantillas son:\n");

    for (int i = 0; i < (*nPlantUser); ++i) {

        printf("[%d] - %s-%s - Puntuacion: %d\n", i,
               (*arrayPlantillas)[userArray[i]].idPlantilla,
               (*arrayPlantillas)[userArray[i]].nombre,
               (*arrayPlantillas)[userArray[i]].puntuacion);
    }
}

/// Crea una nueva plantilla.
/// \param arrayPlantillas - Array de estructuras tipo Plantilla
/// \param config  - Array de estructuras tipo Config
/// \param userPlantillas - Array que contiene los indices de las plantillas del usuario en arrayPlantillas
/// \param nPlant - Tamaño de arrayPlantillas
/// \param nPlantUser - Tamaño de userPlantillas
/// \param userID - Identificador de usuario.

void nuevaPlantilla(plantilla **arrayPlantillas, config **config, int *userPlantillas, int *nPlant, int *nPlantUser,
                    char *userID) {


    int index = 0;
    int found = searchDeletedPlant(arrayPlantillas, nPlant, &index); /* Realiza una búsqueda en arrayPlantillas de plantillas eliminadas
                                                                        En caso de encontrarla, recibe el índice por parámetro y la funcion devuelve 1. */

    if(found == 1){
        char nombre[21];

        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)");
        fflush(stdin);
        scanf("%s", nombre);
        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres");
            fflush(stdin);
            scanf("%s", nombre);
        }

        strcpy((*arrayPlantillas)[index].idUsuario, userID);
        strcpy((*arrayPlantillas)[index].nombre, nombre);
        (*arrayPlantillas)[index].presupuesto = (*config)[1].value;
        (*arrayPlantillas)[index].puntuacion = (*config)[2].value;

        userPlantillas[(*nPlantUser)] = index;
        (*nPlantUser)++;


    }

    else{
        char nombre[21];
        char plantID[4];
        sprintf(plantID, "%03d", (*nPlant));

        puts("Introduzca el nombre de la plantilla a crear (max. 20 caracteres)\n");
        fflush(stdin);
        scanf("%s", nombre);
        while (strlen(nombre)>20){
            puts("Limite de caracteres excedido (max. 20 caracteres\n");
            fflush(stdin);
            scanf("%s", nombre);
        }

        if((*nPlant) % 30 == 0) {
            (*arrayPlantillas) = realloc((plantilla *) (*arrayPlantillas), ((*nPlant) + 30) * sizeof(plantilla));
        }
        plantilla newPlant;
        strcpy(newPlant.idUsuario, userID),
        strcpy(newPlant.idPlantilla, plantID),
        strcpy(newPlant.nombre, nombre),
        newPlant.presupuesto = (*config)[1].value,
        newPlant.puntuacion = (*config)[2].value;

        (*arrayPlantillas)[(*nPlant)] = newPlant;
        userPlantillas[(*nPlantUser)] = (*nPlant);

        printf("Plantilla %s creada satisfactoriamente.\n", (*arrayPlantillas)[(*nPlant)].nombre);

        (*nPlantUser)++;
        (*nPlant)++;

    }
}

/// Elimina una plantilla, seleccionada por usuario.
/// \param futPlantillas - Array de estructuras tipo futPlantilla
/// \param plantillas - Array de estructuras tipo Plantilla
/// \param userPlantilla - Array que contiene los indices de las plantillas del usuario en arrayPlantillas
/// \param nFutP - Tamaño de futPlantillas
/// \param nPlantUser - Tamaño de userPlantilla

void eliminarPlantilla(futPlantilla **futPlantillas, plantilla **plantillas, int *userPlantilla, int *nFutP,
                       int *nPlantUser) {

    int input;
    char deleted[3] = "\0";

    puts("Seleccione la plantilla que desea eliminar:\n");

    for (int i = 0; i < (*nPlantUser); ++i) {   //Imprime las plantillas del usuario
        printf("[%d] %s-%s-%d-%d\n", i,
               (*plantillas)[userPlantilla[i]].idPlantilla,
               (*plantillas)[userPlantilla[i]].nombre,
               (*plantillas)[userPlantilla[i]].presupuesto,
               (*plantillas)[userPlantilla[i]].puntuacion);
    }

    fflush(stdin);
    scanf("%d", &input);    //Solicita el indice de la plantilla a eliminar
    while(input >= (*nPlantUser) || input < 0){
        puts("Introduzca un valor válido ( Ejemplo: 2\n");
        fflush(stdin);
        scanf("%d", &input);
    }

    for (int i = 0; i < (*nFutP); ++i) {

        if (strcmp((*futPlantillas)[i].idPlantilla, (*plantillas)[userPlantilla[input]].idPlantilla) == 0) { // "Elimina" los jugadores asignados a la plantilla borrada
            strcpy((*futPlantillas)[i].idPlantilla, "\0");
        }
    }
    strcpy((*plantillas)[userPlantilla[input]].idUsuario, deleted); // "Elimina" la plantilla.
}

/// Busca en el array de estructuras Plantilla alguna borrada durante la sesión actual.
/// \param arrayPlantilla  - Array de estructuras tipo Plantilla.
/// \param nPlantilla - Tamaño de arrayPlantila.
/// \param index  - Parámetro de salida mediante el cual se devuelve el índice de la plantilla borrada encontrada.
/// \return Devuelve 1 si encuentra una plantilla borrada, 0 en caso contrario.

int searchDeletedPlant(plantilla **arrayPlantilla, int *nPlantilla, int *index) {

    for (int i = 0; i < (*nPlantilla); ++i) {

        if(strcmp((*arrayPlantilla)[i].idUsuario, "\0") == 0){

            (*index) = i;
            return 1;
        }
    }
    return 0;
}

/// Menú de modificación de plantillas del usuario tipo Participante.
/// \param userPlantillas - Array que contiene los indices de las plantillas del usuario en arrayPlantillas
/// \param plantillas - Array de estructuras tipo Plantilla
/// \param futPlantillas - Array de estructuras tipo futPlantilla
/// \param futbolistas - Array de estructuras tipo futbolista
/// \param config - Array de estructuras tipo config
/// \param nPlantUser - Tamaño de userPlantillas.
/// \param nFutP - Tamaño de futPlantillas
/// \param nFutbolistas - Tamaño de futbolistas.

void menuConfigurar(int *userPlantillas, plantilla **plantillas, futPlantilla **futPlantillas, futbolista **futbolistas,
                    config **config, int *nPlantUser, int *nFutP, int *nFutbolistas) {

    int input;
    int input2;

    int nUserFutP;
    int nDisponibles;

    int presupuesto = (*config)[1].value; //Inicializa los presupuestos y puntuacion iniciales.
    int puntuacion = (*config)[2].value;

    char* idPlantilla = malloc(3* sizeof(char));

    futPlantilla* userFutPlant = malloc(11* sizeof(futPlantilla));
    futbolista* playerData = malloc(11 * sizeof(futbolista));
    futbolista* futDisponibles = malloc(99 * sizeof(futbolista));

    puts("Introduzca el numero de la plantilla a modificar\n");

    fflush(stdin);
    scanf("%d", &input);
    while (input >= (*nPlantUser) || input < 0){
        puts("Por favor, introduzca un identificador de plantilla valido");
        fflush(stdin);
        scanf("%d", &input);
    }

    nUserFutP = selectPlantilla(&userFutPlant, futPlantillas, userPlantillas, &playerData, futbolistas,
                                nFutP,idPlantilla, plantillas, input, &presupuesto, &puntuacion);
                                                                                                                /*Crea dos vectores auxiliares: userFutPlant, que contiene las estructuras futPlantilla de la plantilla seleccionada
                                                                                                                 y playerData, que contiene las estructuras Futbolista correspondientes a los jugadores de futPlantilla. */

    nDisponibles = loadDisponibles(futbolistas, &futDisponibles, &userFutPlant, nFutbolistas, &nUserFutP);      //Crea un vector auxiliar futDisponibles, que contiene los jugadores disponibles para añadir a la plantilla.

    do {
        printf("\nSeleccione que operacion realizar sobre la plantilla:\n");

        puts(OPCIONES2);
        fflush(stdin);
        scanf("%d", &input2);
        while (input2 < 0 || input2 > 5){
            puts("Seleccione una opción válida. (Ejemplo: 2)");
            fflush(stdin);
            scanf("%d", &input2);
        }

        switch (input2) {
            case 1:
                if(nUserFutP == 0){
                    puts("La plantilla no contiene jugadores aun\n");
                }
                else{
                    listPlantilla(&userFutPlant, &nUserFutP, &playerData);
                }
            break;

            case 2:
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado\n");
                }
                else {
                    listJugadores(&futDisponibles, &nDisponibles);
                    }
            break;

            case 3:
                if(nUserFutP == 11){
                    puts("Numero maximo de jugadores en esta plantilla alcanzado\n");
                }
                else{
                    addJugadores(futPlantillas, &userFutPlant, &playerData, &futDisponibles, nFutP, &nUserFutP,
                                 &nDisponibles, idPlantilla, &presupuesto, &puntuacion);
                }
            break;

            case 4:
                if(nUserFutP == 0){
                    puts("No existen jugadores en la plantilla.\n");
                }
                else {
                    deleteJugadores(&userFutPlant, &playerData, &nUserFutP, nFutP,
                                    futPlantillas);
                    nUserFutP = selectPlantilla(&userFutPlant, futPlantillas, userPlantillas, &playerData, futbolistas,
                                                nFutP,
                                                idPlantilla, plantillas, input, &presupuesto, &puntuacion);
                    nDisponibles = loadDisponibles(futbolistas, &futDisponibles, &userFutPlant, nFutbolistas, &nUserFutP);
                }
            break;
        }
    }
    while (input2 != 5);

    (*plantillas)[input].presupuesto = presupuesto;
    (*plantillas)[input].puntuacion = puntuacion;

    free(userFutPlant);
    free(playerData);
    free(futDisponibles);
    free(idPlantilla);
}

/// Añade jugadores a la plantilla seleccionada
/// \param arrayFutP - Array de estructuras futPlantilla.
/// \param userFutP - Vector auxiliar con las estructuras futPlantilla correspondientes al identificador de la plantilla seleccionada.
/// \param playerData - Vector auxiliar con las estructuras Futbolista correspondientes al identificador de las estructuras futPlantilla de userFutP
/// \param disponibles - Vector auxiliar con los jugadores disponibles para añadir a plantilla.
/// \param nFutP - Tamaño de arrayFutP
/// \param nUserFutP - Tamaño de userFutP
/// \param nDisponibles - Tamaño de disponibles.
/// \param idPlantilla - Identificador de la plantilla seleccionada.
/// \param presupuesto - Puntero al presupuesto de la plantilla seleccionada.
/// \param puntuacion - Puntero a la puntuación de la plantilla seleccionada.

void addJugadores(futPlantilla **arrayFutP, futPlantilla **userFutP, futbolista **playerData, futbolista **disponibles,
                  int *nFutP, int *nUserFutP, int *nDisponibles, char *idPlantilla, int *presupuesto, int *puntuacion) {

    int input = 0;
    int input2 = 0;
    do {
        puts("Por favor, seleccione de la lista el identificador de jugador a añadir:\n");
        listJugadores(disponibles, nDisponibles);
        printf("Presupuesto restante: %d\n", (*presupuesto));

        fflush(stdin);
        scanf("%d", &input);

        while (input >= (*nDisponibles) || input < 0 || strcpy((*disponibles)[input].nombre, "NULL") == 0){
            puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2\n");
            fflush(stdin);
            scanf("%d", &input);
        }
        if(((*presupuesto) - (*disponibles)[input].precio) > 0) {

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
            puts("Presupuesto máximo excedido, imposible añadir usuario\n");

        puts("Desea añadir otro jugador?\n0 - Yes\n1 - No\n");
        fflush(stdin);
        scanf("%d", &input2);
        while (input2 < 0 || input2 > 1){
            puts("Comando incorrecto\n");
            puts("Desea añadir otro jugador?\n0 - Yes\n1 - No\n");
            fflush(stdin);
            scanf("%d", &input2);
        }
    }
    while(input2 == 0);
}

/// Elimina jugadores de la plantilla seleccionada.
/// \param userFutP - Vector auxiliar con las estructuras futPlantilla correspondientes al identificador de la plantilla seleccionada.
/// \param playerData - Vector auxiliar con las estructuras Futbolista correspondientes al identificador de las estructuras futPlantilla de userFutP
/// \param nUserFutP - Tamaño de userFutP
/// \param nFutP - Tamaño de arrayFutP
/// \param arrayFutP - Vector de estructuras FutPlantillas

void deleteJugadores(futPlantilla *userFutP[], futbolista *playerData[], int *nUserFutP, int *nFutP,
                     futPlantilla **arrayFutP) {
    int input = 0;

    puts("Por favor, seleccione el jugador a eliminar de la plantilla");

    for (int i = 0; i < (*nUserFutP); ++i) {                                                    //imprime los jugadores en la plantilla
        printf("[%d] %s-%s\n", i, (*userFutP)[i].idFutbolista, (*playerData)[i].nombre);
    }

    fflush(stdin);
    scanf("%d", &input);
    while (input >= (*nUserFutP) || input < 0){
        puts("Por favor, introduzca un identificador de jugador válido (Formato de ejemplo: 2\n");
        fflush(stdin);
        scanf("%d", &input);
    }

    for (int i = 0; i < (*nFutP); ++i) {

        if(strcmp((*userFutP)[input].idFutbolista, (*arrayFutP)[i].idFutbolista) == 0  && strcmp((*userFutP)[input].idPlantilla, (*arrayFutP)[i].idPlantilla) == 0 ){
            strcpy((*arrayFutP)[i].idPlantilla, "\0");
        }
    }
}

/// Imprime los jugadores disponibles para añadir a la plantilla.
/// \param futDisponibles - Vector auxiliar de estructuras Futbolista que contiene los jugadores asignables a la plantilla.
/// \param nDisponibles  - Tamaño de futDisponibles.
void listJugadores(futbolista** futDisponibles, int* nDisponibles) {

    puts("Jugadores disponibles:\n");

    for(int i = 0; i < (*nDisponibles); ++i) {
        if(strcmp((*futDisponibles)[i].nombre, "NULL")){
            printf("[%d]  %s-%s Precio: %d\n",i , (*futDisponibles)[i].idFutbolista, (*futDisponibles)[i].nombre, (*futDisponibles)[i].precio);

        }
    }
}

/// Imprime los jugadores contenidos en la plantilla.
/// \param futbolistasP - Vector auxiliar de estructuras futPlantilla que contiene los jugadores de la plantilla.
/// \param nFutPlant - Tamaño de futbolistasP y playerData.
/// \param playerData - Vector auxiliar de estructuras Futbolista que contiene la información de los jugadores correspondientes a futbolistasP

void listPlantilla(futPlantilla** futbolistasP, int* nFutPlant, futbolista** playerData){

    for (int i = 0; i < (*nFutPlant); ++i) {
        printf("%s-%s Precio: %d\n", (*futbolistasP)[i].idFutbolista,(*playerData)[i].nombre, (*playerData)[i].precio);
    }
}

/// Crea los vectores axiliares localFutPlant y playerData, localizando los jugadores pertenecientes a la plantilla seleccionada
/// y sus correspondientes datos.
/// \param localFutPlant - Vector auxiliar de estructuras futPlantilla, que contiene los jugadores de la plantilla.
/// \param arrayFutPlantillas - Vector de estructuras futPlantilla.
/// \param userPlantillas - Vector que contiene los índices de las plantillas del usuario en arrayPlantillas.
/// \param playerData - Vector auxiliar de estructuras Futbolista con la información de localFutPlant.
/// \param futbolistas - Vector de estructuras Futbolista.
/// \param nFutP - Tamaño de arrayFutPlantillas
/// \param plantID - Identificador de la plantilla seleccionada.
/// \param arrayPlantillas - Array de estructuras Plantilla
/// \param input - Valor del índice de la plantilla seleccionada por el usuario en userPlantillas.
/// \param presupuesto - Puntero al presupuesto de la plantilla.
/// \param puntuacion - Puntero a la puntuación de la plantilla.
/// \return nFutPlant - Número de jugadores encontrados pertenecientes a la plantilla seleccionada.

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
    }

    bubbleSort(indexArray, (*nPlantillas));

    for (int i = 0; i < (*nPlantillas); ++i) {
        printf("[%d] %s - %s\n", (*arrayPlantilla)[indexArray[i][1]].puntuacion, (*arrayPlantilla)[indexArray[i][1]].idPlantilla, (*arrayPlantilla)[indexArray[i][1]].nombre);
    }

}

void bubbleSort(int arr[][2], int n) {
    int i, j;
    printf("%d\n", n);
    for (i = 0; i < n - 1; i++) {

        for (j = 0; j < n - i - 1; j++) {

            if (arr[j][0] < arr[j + 1][0]) {
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

    *indexA = *indexB;
    *indexB = temp2;
}