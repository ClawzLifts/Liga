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
//Precondici�n: c es el indicador del origen de la llamada (gesti�n de usuarios o registro de usuarios). n_us es el tama�o del vector de
//              registros us, correspondientes a los usuarios.
//Postcondici�n: Permite a�adir un usuario.

void anadir_us(char, int*, usuario**);

//Cabecera: void m_admin(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,         //INICIO DE ADMIN
//                       plantilla** pl, futPlantilla** fpl, config** con))
//Precondición: idp es la id del usuario actual. n_eq, n_juf, n_us, n_pl, n_fpl y n_con son los tamaños de sus respectivos vectores de registros.
//              eq, jug, us, pl, fpl y con los vectores de registros.
//Postcondición: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submenús de gestión de equipos, usuarios y configuración.

void m_admin(int, int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

#endif
