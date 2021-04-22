//
// Created by Clawz on 06/04/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Headers/Cronista.h"
#include "Headers/Admin.h"
#include "Headers/loader.h"




futbolista createStructJugadores(char**);
usuario createStructUsuarios(char**);
config createStructConfig(char**);
futPlantilla createStructFutP(char**);
equipo createStructEquipos(char**);
plantilla createStructPlantilla(char**);


/// Carga los datos en el fichero Futbolistas_Plantillas.txt en un array de estructuras futPlantilla.
/// \param dynArray - Vector de punteros a estructuras futPlantilla a ser cargado.
/// \param n - Puntero a entero que recibe el número de estructuras cargadas en el array.
void loadFutPlantillas(futPlantilla **dynArray, int* n ) {

    FILE *file;
    file = fopen("DATA/Futbolistas_Plantillas.txt", "r");
    char buffer[35];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Futbolistas_Plantillas");
    }
    else {
        *n = 0;

        do {
            fgets(buffer, 100, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 50 == 0) {
                    *dynArray = realloc((futPlantilla *) (*dynArray), (*n + 50) * sizeof(futPlantilla));
                }
                (*dynArray)[*n] = createStructFutP(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);
    }

}

//Referimos al comentario de loadFutPlantillas() para todos los loadXXX(), ya que el comportamiento es equivalente.
void loadConfig(config **dynArray, int *n) {

    FILE *file;
    file = fopen("DATA/Configuracion.txt", "r");
    char buffer[35];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Configuracion");
    }
    else {
        *n = 0;

        do {
            fgets(buffer, 100, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 50 == 0) {
                    *dynArray = realloc((config *) (*dynArray), (*n + 10) * sizeof(config));
                }
                (*dynArray)[*n] = createStructConfig(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);
    }

}


void loadFutbolistas(futbolista **dynArray, int * n) {

    FILE *file;
    file = fopen("DATA/Futbolistas.txt", "r");
    char buffer[100];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Futbolistas");
    }
    else {
        *n=0;

        do {
            fgets(buffer, 1000, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 50 == 0) {
                    *dynArray = realloc((futbolista *) (*dynArray), (*n + 50) * sizeof(futbolista));
                }
                (*dynArray)[*n] = createStructJugadores(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);

    }

}


void loadEquipos(equipo **dynArray, int * n) {

    FILE *file;
    file = fopen("DATA/Equipos.txt", "r");
    char buffer[35];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Equipos");
    }
    else {
        *n = 0;

        do {
            fgets(buffer, 100, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 50 == 0) {
                    *dynArray = realloc((equipo *) (*dynArray), (*n + 50) * sizeof(equipo));
                }
                (*dynArray)[*n] = createStructEquipos(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);
    }

}


void loadUsuario(usuario **dynArray, int * n) {
    FILE *file;
    file = fopen("DATA/Usuarios.txt", "r");
    char buffer[35];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Futbolistas");
    }
    else {
        *n = 0;

        do {
            fgets(buffer, 100, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 10 == 0) {
                    *dynArray = realloc((usuario *) (*dynArray), (*n + 10) * sizeof(usuario));
                }
                (*dynArray)[*n] = createStructUsuarios(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);
    }

}


void loadPlantilla(plantilla **dynArray, int * n) {
    FILE *file;
    file = fopen("DATA/Plantillas.txt", "r");
    char buffer[35];
    char *fields[5];

    if (file == NULL) {
        printf("Error al abrir el fichero Plantillas");
    }
    else {
        *n = 0;

        do {
            fgets(buffer, 100, file);
            if(strlen(buffer) > 2) {
                stringSplit(buffer, fields);
                if (*n % 30 == 0) {
                    *dynArray = realloc((plantilla *) (*dynArray), (*n + 30) * sizeof(plantilla));
                }
                (*dynArray)[*n] = createStructPlantilla(fields);
                (*n)++;
            }

        } while (!feof(file));

        fclose(file);
    }

}

/// Recibe una string leida del fichero, la separa en tokens delimitados por '-' o '\n', y
/// devuelve por parámetro un array con los campos a ser utilizados para crear las estructuras.
/// \param string - String a tokenizar
/// \param fields - Parametro de salida por el que se otorga el valor a los campos.
void stringSplit(char *string, char **fields) {

    int counter = 0;

    for (char* token = strtok( string, "-,\n"); token != NULL; token = strtok( NULL, "-,\n"), counter++ ){

        fields[counter] = token;

    }

}

/// Crea la estructura correspondiente, inicializando los campos mediante los valores contenidos en array[].
/// \param array - Contingente de los valores de los campos de la estructura.
/// \return La estructura inicializada para ser asignada a una posición del vector.
futbolista  createStructJugadores(char* array[]){
    futbolista newStruct;

    strcpy(newStruct.idFutbolista,array[0]),
    strcpy(newStruct.idEquipo,array[1]),
    strcpy(newStruct.nombre, array[2]),
    newStruct.precio = atoi(array[3]),
    newStruct.puntuacion = atoi(array[4]);

    return newStruct;

}

//Para todas las funciones createStructXXX(), referimos al comentario de createStructXXX() ya que poseen un comportamiento equivalente.
plantilla createStructPlantilla(char* array[]){
    plantilla newStruct;

    strcpy(newStruct.idUsuario,array[0]),
    strcpy(newStruct.idPlantilla,array[1]),
    strcpy(newStruct.nombre, array[2]),
    newStruct.presupuesto = atoi(array[3]),
    newStruct.puntuacion = atoi(array[4]);

    return newStruct;

}


usuario createStructUsuarios(char* array[]) {
    usuario newStruct;

    strcpy(newStruct.idUser,array[0]),
    strcpy(newStruct.nombre, array[1]),
    strcpy(newStruct.perfil, array[2]),
    strcpy(newStruct.usuario,array[3]),
    strcpy(newStruct.password, array[4]);

    return newStruct;
}


config createStructConfig(char* array[]) {
    config newStruct;

    strcpy(newStruct.data, array[0]);
    newStruct.value = atoi(array[1]);

    return newStruct;
}


futPlantilla createStructFutP(char* array[]) {
    futPlantilla newStruct;

    strcpy(newStruct.idFutbolista,array[0]),
    strcpy(newStruct.idPlantilla,array[1]);

    return newStruct;
}


equipo createStructEquipos(char* array[]) {
    equipo newStruct;

    strcpy(newStruct.idEquipo, array[0]),
    strcpy(newStruct.nombreEquipo, array[1]);

    return newStruct;
}

/// Recorre el vector de estructuras pasado por parámetro, y escribe en un fichero
/// los valores de los campos en el formato:
/// campo1-campo2-campo3-campo4...
/// \param arrayConfig - Array a ser recorrido
/// \param nConfig - Tamaño del array
void saveConfig(config** arrayConfig, int nConfig){
    FILE* file;
    file = fopen("DATA/Configuracion.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Configuracion.txt");
    }
    else{
        for (int i = 0; i < nConfig - 1; ++i) {
            if(strcmp((*arrayConfig)[i].data, "\0") != 0){
                fprintf(file, "%s-%d\n",
                        (*arrayConfig)[i].data,
                        (*arrayConfig)[i].value);
            }
        }
        if(strcmp((*arrayConfig)[nConfig-1].data, "\0") != 0){
            fprintf(file, "%s-%d",
                    (*arrayConfig)[nConfig-1].data,
                    (*arrayConfig)[nConfig-1].value);
        }
    }
}

//Para todas las funciones saveXXX(), referimos al comentario de saveConfig() ya que poseen un comportamiento equivalente.
void saveEquipos(equipo** arrayEquipos, int nEquipos){
    FILE* file;
    file = fopen("DATA/Equipos.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Equipos.txt");
    }
    else{
        for (int i = 0; i < nEquipos - 1; ++i) {
            if(strcmp((*arrayEquipos)[i].idEquipo, "\0") != 0){
                fprintf(file, "%s-%s\n",
                        (*arrayEquipos)[i].idEquipo,
                        (*arrayEquipos)[i].nombreEquipo);
            }
        }
        if(strcmp((*arrayEquipos)[nEquipos-1].idEquipo, "\0") != 0){
            fprintf(file, "%s-%s",
                    (*arrayEquipos)[nEquipos-1].idEquipo,
                    (*arrayEquipos)[nEquipos-1].nombreEquipo);
        }
    }
}

void saveFutbolistas(futbolista** arrayFutbolistas, int nFutbolistas){
    FILE *file;
    file = fopen("DATA/Futbolistas.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Futbolistas.txt");
    }
    else{
        for (int i = 0; i < nFutbolistas-1; ++i) {
            if(strcmp((*arrayFutbolistas)[i].idFutbolista, "\0") != 0) {
                fprintf(file, "%s-%s-%s-%d-%d\n",
                        (*arrayFutbolistas)[i].idFutbolista,
                        (*arrayFutbolistas)[i].idEquipo,
                        (*arrayFutbolistas)[i].nombre,
                        (*arrayFutbolistas)[i].precio,
                        (*arrayFutbolistas)[i].puntuacion);
            }
        }
        if(strcmp((*arrayFutbolistas)[nFutbolistas-1].idFutbolista, "\0") != 0) {
            fprintf(file, "%s-%s-%s-%d-%d",
                    (*arrayFutbolistas)[nFutbolistas-1].idFutbolista,
                    (*arrayFutbolistas)[nFutbolistas-1].idEquipo,
                    (*arrayFutbolistas)[nFutbolistas-1].nombre,
                    (*arrayFutbolistas)[nFutbolistas-1].precio,
                    (*arrayFutbolistas)[nFutbolistas-1].puntuacion);
        }
    }
    fclose(file);


}

void savePlantillas(plantilla** arrayPlantillas, int nPlantillas){

    FILE *file;
    file = fopen("DATA/Plantillas.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Plantillas.txt");
    }
    else{
        for (int i = 0; i < nPlantillas-1; ++i) {
            if(strcmp((*arrayPlantillas)[i].idUsuario, "\0") != 0) {
                fprintf(file, "%s-%s-%s-%d-%d\n",
                        (*arrayPlantillas)[i].idUsuario,
                        (*arrayPlantillas)[i].idPlantilla,
                        (*arrayPlantillas)[i].nombre,
                        (*arrayPlantillas)[i].presupuesto,
                        (*arrayPlantillas)[i].puntuacion);
            }
        }
        if(strcmp((*arrayPlantillas)[nPlantillas-1].idUsuario, "\0") != 0) {
            fprintf(file, "%s-%s-%s-%d-%d",
                    (*arrayPlantillas)[nPlantillas-1].idUsuario,
                    (*arrayPlantillas)[nPlantillas-1].idPlantilla,
                    (*arrayPlantillas)[nPlantillas-1].nombre,
                    (*arrayPlantillas)[nPlantillas-1].presupuesto,
                    (*arrayPlantillas)[nPlantillas-1].puntuacion);
        }
    }
    fclose(file);
}

void saveFutP(futPlantilla** arrayFutPlan, int nFutP){
    FILE* file;
    file = fopen("DATA/Futbolistas_Plantillas.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Futbolistas_Plantillas.txt");
    }
    else{
        for (int i = 0; i < nFutP - 1; ++i) {
            if(strcmp((*arrayFutPlan)[i].idPlantilla, "\0") != 0){
                fprintf(file, "%s-%s\n",
                        (*arrayFutPlan)[i].idFutbolista,
                        (*arrayFutPlan)[i].idPlantilla);
            }
        }
        if(strcmp((*arrayFutPlan)[nFutP-1].idPlantilla, "\0") != 0){
            fprintf(file, "%s-%s",
                    (*arrayFutPlan)[nFutP-1].idFutbolista,
                    (*arrayFutPlan)[nFutP-1].idPlantilla);
        }
    }
}

void saveUsuarios(usuario** arrayUsuarios, int nUsuarios){
    FILE *file;
    file = fopen("DATA/Usuarios.txt", "w");
    if(file == NULL){
        puts("Error al abrir el archivo Usuarios.txt");
    }
    else{
        for (int i = 0; i < nUsuarios-1; ++i) {
            if(strcmp((*arrayUsuarios)[i].idUser, "\0") != 0) {
                fprintf(file, "%s-%s-%s-%s-%s\n",
                        (*arrayUsuarios)[i].idUser,
                        (*arrayUsuarios)[i].nombre,
                        (*arrayUsuarios)[i].perfil,
                        (*arrayUsuarios)[i].usuario,
                        (*arrayUsuarios)[i].password);
            }
        }
        if(strcmp((*arrayUsuarios)[nUsuarios-1].idUser, "\0") != 0) {
            fprintf(file, "%s-%s-%s-%s-%s",
                    (*arrayUsuarios)[nUsuarios-1].idUser,
                    (*arrayUsuarios)[nUsuarios-1].nombre,
                    (*arrayUsuarios)[nUsuarios-1].perfil,
                    (*arrayUsuarios)[nUsuarios-1].usuario,
                    (*arrayUsuarios)[nUsuarios-1].password);
        }
    }
    fclose(file);

}


