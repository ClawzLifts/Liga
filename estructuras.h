//
// Created by Clawz on 06/04/2021.
//

#ifndef LIGA_ESTRUCTURAS_H
#define LIGA_ESTRUCTURAS_H

typedef struct plantilla{
    char idUsuario[2];
    char idPlantilla[3];
    char nombre[20];
    int presupuesto;
    int puntuacion;
}plantilla;


typedef struct jugPlantilla {
    char idFutbolista[2];
    char idPlantilla[3];
}futPlantilla;


typedef struct futbolista
{
    char idFutbolista[4];
    char idEquipo[3];
    char nombre[21];
    int precio;
    int puntuacion;
} futbolista;


typedef struct usuario
{
    char idUser[2];
    char nombre[20];
    char perfil[13];
    char usuario[5];
    char password[8];
}usuario;


typedef struct equipo
{
    char idEquipo[2];
    char nombreEquipo[20];
}equipo;


typedef struct config
{
    char data[20];
    int value;

}config;

#endif //LIGA_ESTRUCTURAS_H
