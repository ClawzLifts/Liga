#include "load.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void init(){

    structLoad("DATA/Futbolistas.txt");
    structLoad("DATA/Equipos.txt");
    structLoad("DATA/Configuracion.txt");
    structLoad("DATA/Usuarios.txt");
    structLoad("DATA/Futbolistas_Plantillas.txt");

}


void structLoad(char* fileName) {

    FILE *file;
    file = fopen(fileName, "r");
    char buffer[35];
    char *array[5];



    if (file == NULL) {
        printf("Error al abrir el fichero %s", fileName);
    }

    else {

        if (!strcmp(fileName, "DATA/Futbolistas.txt")) {
            int i = 0;

            do {
                fgets(buffer, 35, file);
                stringSplit(buffer, array);
                arrayFutbolistas[i] = createStructJugadores(array);
                i++;

            } while (!feof(file));

        }
        else {

            if (!strcmp(fileName, "DATA/Usuarios.txt")) {
                int i = 0;

                do {
                    fgets(buffer, 35, file);
                    stringSplit(buffer, array);
                    arrayUsuarios[i] = createStructUsuarios(array);
                    i++;


                } while (!feof(file));

            }

            else{

                if (!strcmp(fileName, "DATA/Configuracion.txt")){
                    int i = 0;

                    do {
                        fgets(buffer, 35, file);
                        stringSplit(buffer, array);
                        arrayConfig[i] = createStructConfig(array);
                        i++;

                    } while (!feof(file));

                }
                else{

                    if (!strcmp(fileName, "DATA/Equipos.txt")){
                        int i = 0;

                        do {
                            fgets(buffer, 35, file);
                            stringSplit(buffer, array);
                            arrayEquipos[i] = createStructEquipos(array);
                            i++;

                        } while (!feof(file));

                    }
                    else{

                        if (!strcmp(fileName, "DATA/Futbolistas_Plantillas.txt")){
                            int i = 0;

                            do {
                                fgets(buffer, 35, file);
                                stringSplit(buffer, array);
                                arrayFutP[i] = createStructFutP(array);
                                i++;

                            } while (!feof(file));

                        }
                    }
                }
            }
        }
    }
}



void stringSplit(char* string, char* fields[]) {

    int counter = 0;

    for (char* token = strtok( string, "-"); token != NULL; token = strtok( NULL, "-"), counter++ ){
   
        fields[counter] = token;
       
    }

}


futbolista  createStructJugadores(char* array[]){

    futbolista newStruct;

    strcpy(newStruct.idFutbolista,array[0]),
    strcpy(newStruct.idEquipo, array[1]),
    strcpy(newStruct.nombre, array[2]),
    newStruct.precio = atoi(array[3]),
    newStruct.puntuacion = atoi(array[4]);

    return newStruct;

}

usuario createStructUsuarios(char* array[]) {
    usuario newStruct;

    strcpy(newStruct.idUser,array[0]),
    strcpy(newStruct.nombre, array[1]),
    strcpy(newStruct.perfil, array[2]),
    strcpy(newStruct.usuario,array[3]),
    strcpy(newStruct.password, array[4]),

    return newStruct;
}

config createStructConfig(char* array[]) {
    config result;
    return result;
}

futPlantilla createStructFutP(char* array[]) {
    futPlantilla result;
    return result;
}

equipo createStructEquipos(char* array[]) {
    equipo result;
    return result;
}


