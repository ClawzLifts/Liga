#ifndef LOGIN_RES_H_INCLUDED
#define LOGIN_RES_H_INCLUDED

#include "Admin.h"
#include "Cronista.h"

//Cabecera: void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int n_con, equipos** eq, jugadores** jug, usuario** us, config** con)
//Precondición:
//Postcondición: Permite acceder a la aplicación o registrar en ella.

void loginres(int*, int*, int*, int*, int, equipos**, jugadores**, usuario**, config**);

#endif // LOGIN_RES_H_INCLUDED
