#ifndef _CRONISTA_H_
#define _CRONISTA_H_

typedef struct futbolista
{
    char idFutbolista[3];
    char idEquipo[3];
    char nombre[21];
    int precio;
    int puntuacion;
} futbolista;


typedef struct equipo
{
    char idEquipo[3];
    char nombreEquipo[21];
}equipo;


void cronista(int *, equipo **, int *, futbolista **);

#endif