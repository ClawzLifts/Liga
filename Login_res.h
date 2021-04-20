#ifndef LOGIN_RES_H_INCLUDED
#define LOGIN_RES_H_INCLUDED


//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us, config** con)
//Precondición: n_eq, n_juf, n_us, n_pl, n_fpl y n_con son los tamaños de sus respectivos vectores de registros. eq, jug, us, pl, fpl y con los
//              vectores de registros.
//Postcondición: Permite acceder a la aplicación o registrar en ella.

void loginres(int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

#endif // LOGIN_RES_H_INCLUDED
