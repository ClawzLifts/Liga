#ifndef LOGIN_RES_H_INCLUDED
#define LOGIN_RES_H_INCLUDED


//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,
//                        plantilla** pl, futPlantilla** fpl, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_us: número de usuarios en la aplicación
  n_pl: número de plantillas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación
  n_con: número de campos de configuración de la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  us: usuarios
  pl: plantillas
  fpl: relaciones futbolistas-plantillas
  con: campos de configuración
*/
//Postcondición: Permite acceder a la aplicación o registrar en ella.

void loginres(int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

#endif // LOGIN_RES_H_INCLUDED
