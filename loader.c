//
// Created by Clawz on 06/04/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cronista.h"
#include "Admin.h"
#include "loader.h"




futbolista createStructJugadores(char**);
usuario createStructUsuarios(char**);
config createStructConfig(char**);
futPlantilla createStructFutP(char**);
equipo createStructEquipos(char**);
plantilla createStructPlantilla(char**);



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
            stringSplit(buffer, fields);
            if (*n%50==0){
                *dynArray=realloc((futPlantilla*)(*dynArray), (*n+50)*sizeof(futPlantilla));
            }
            (*dynArray)[*n]=createStructFutP(fields);
            (*n)++;

        } while (!feof(file));

        fclose(file);
    }

}


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
            stringSplit(buffer, fields);
            if (*n%50==0){
                *dynArray =realloc((config*)(*dynArray), (*n+10)*sizeof(config));
            }
            (*dynArray)[*n]=createStructConfig(fields);
            (*n)++;

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
            stringSplit(buffer, fields);
            if (*n%50==0){
                *dynArray=realloc((futbolista*)(*dynArray), (*n+50)*sizeof(futbolista));
            }
            (*dynArray)[*n]=createStructJugadores(fields);
            (*n)++;

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
            stringSplit(buffer, fields);
            if (*n%50==0){
                *dynArray=realloc((equipo *)(*dynArray), (*n+50)*sizeof(equipo));
            }
            (*dynArray)[*n]=createStructEquipos(fields);
            (*n)++;

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
            stringSplit(buffer, fields);
            if (*n%10==0){
                *dynArray=realloc((usuario *)(*dynArray), (*n+10)*sizeof(usuario));
            }
            (*dynArray)[*n]=createStructUsuarios(fields);
            (*n)++;

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
            stringSplit(buffer, fields);
            if (*n%30==0){
                *dynArray=realloc((plantilla *)(*dynArray), (*n+30)*sizeof(plantilla));
            }
            (*dynArray)[*n]=createStructPlantilla(fields);
            (*n)++;

        } while (!feof(file));

        fclose(file);
    }

}


void stringSplit(char *string, char **fields) {

    int counter = 0;

    for (char* token = strtok( string, "-,\n"); token != NULL; token = strtok( NULL, "-,\n"), counter++ ){

        fields[counter] = token;

    }

}


futbolista  createStructJugadores(char* array[]){
    futbolista newStruct;

    strcpy(newStruct.idFutbolista,array[0]),
    strcpy(newStruct.idEquipo,array[1]),
    strcpy(newStruct.nombre, array[2]),
    newStruct.precio = atoi(array[3]),
    newStruct.puntuacion = atoi(array[4]);

    return newStruct;

}


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



