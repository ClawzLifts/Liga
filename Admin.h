#ifndef ADMIN_H
#define ADMIN_H


//#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#
//      DECLARACI�N DE ESTRUCTURAS
//#=#=#=#=#=#=#=#=#==#=#=#=#=#=#=#=#=#=#

typedef struct config
{
    char data[31];
    int value;

}config;

typedef struct usuario
{
    char idUser[3];
    char nombre[21];
    char perfil[14];
    char usuario[6];
    char password[9];
}usuario;

typedef struct plantilla{
    char idUsuario[3];
    char idPlantilla[4];
    char nombre[21];
    int presupuesto;
    int puntuacion;
}plantilla;

typedef struct futPlantilla {
    char idFutbolista[3];
    char idPlantilla[4];
}futPlantilla;

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACI�N DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void anadir_us(char c, int* n_us, usuario** us)
//Precondición:
/*
  Variables:
  ----------
  idp: identificador del usuario actual
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
//Postcondición: Permite añadir un usuario.

void anadir_us(char, int*, usuario**);

//Cabecera: void m_admin(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,         //INICIO DE ADMIN
//                       plantilla** pl, futPlantilla** fpl, config** con))
//Precondición:
/*
  Variables:
  ----------
  c: indicador del origen de la llamada ('u' ==> gestión de usuarios || 'r' ==> registro)
  n_us: número de usuarios en la aplicación

  Vector de estructuras:
  ----------------------
  us: usuarios
*/
//Postcondición: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submenús de gestión de equipos, usuarios y configuración.

void m_admin(int, int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

#endif
