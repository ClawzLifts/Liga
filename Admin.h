#ifndef ADMIN_H
#define ADMIN_H

#include "Cronista.h"

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACI�N DE ESTRUCTURAS
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

typedef struct
{
    char campo[20];
    int value;
} config;

typedef struct
{
    char idUser[10];
    char nombre[21];
    char permisos[15];
    char usuario[6];
    char password[9];
} usuario;

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACI�N DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void m_admin(int* n_eq, int* n_jug, int* n_us, int* n_pl, int n_con, equipos *eq, jugadores *jug, usuario *us, config *con)
//Precondici�n:
//Postcondici�n: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submen�s de gesti�n de equipos, usuarios y configuraci�n.

void m_admin(int, int*, int*, int*, int*, int, equipos**, jugadores**, usuario**, config**);

//Cabecera: void anadir_us(char c, int* n_us, usuario* us)
//Precondici�n: c es el indicador del origen de la llamada (gesti�n de usuarios o registro de usuarios). n_us es el tama�o del vector de
//              registros us, correspondientes a los usuarios.
//Postcondici�n: Permite a�adir un usuario.

void anadir_us(char, int*, usuario**);

#endif // ADMIN_H_INCLUDED
