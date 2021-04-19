#ifndef ADMIN_H
#define ADMIN_H

#include "Cronista.h"

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE ESTRUCTURAS
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
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void m_admin(int* n_eq, int* n_jug, int* n_us, int* n_pl, int n_con, equipos *eq, jugadores *jug, usuario *us, config *con)
//Precondición:
//Postcondición: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submenús de gestión de equipos, usuarios y configuración.

void m_admin(int, int*, int*, int*, int*, int, equipos**, jugadores**, usuario**, config**);

//Cabecera: void anadir_us(char c, int* n_us, usuario* us)
//Precondición: c es el indicador del origen de la llamada (gestión de usuarios o registro de usuarios). n_us es el tamaño del vector de
//              registros us, correspondientes a los usuarios.
//Postcondición: Permite añadir un usuario.

void anadir_us(char, int*, usuario**);

#endif // ADMIN_H_INCLUDED
