#ifndef LOGIN_RES_H_INCLUDED
#define LOGIN_RES_H_INCLUDED


//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACI�N DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,
//                        plantilla** pl, futPlantilla** fpl, config** con)
//Precondici�n:
/*
  Variables:
  ----------
  n_eq: n�mero de equipos en la aplicaci�n
  n_jug: n�mero de futbolistas en la aplicaci�n
  n_us: n�mero de usuarios en la aplicaci�n
  n_pl: n�mero de plantillas en la aplicaci�n
  n_fpl: n�mero de relaciones futbolista-plantilla en la aplicaci�n
  n_con: n�mero de campos de configuraci�n de la aplicaci�n

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  us: usuarios
  pl: plantillas
  fpl: relaciones futbolistas-plantillas
  con: campos de configuraci�n
*/
//Postcondici�n: Permite acceder a la aplicaci�n o registrar en ella.

void loginres(int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

#endif // LOGIN_RES_H_INCLUDED
