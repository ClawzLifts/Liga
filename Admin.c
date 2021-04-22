
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Cronista.h"
#include "Admin.h"
#include "loader.h"
#include "participante.h"



//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//=-=-=-=-=-=-=-=-=-=-=
//        MENÚS
//=-=-=-=-=-=-=-=-=-=-=

void m_equipo(int*, int*, int, equipo**, futbolista**, futPlantilla**, config**);
void m_usuario(int, int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);
void m_config(int, config**);
void m_admin(int, int*, int*, int*, int*, int*, int, equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

//=-=-=-=-=-=--=-=-=-=-=-=
//  FUNCIONES OPERATIVAS
//=-=-=-=-=-=--=-=-=-=-=-=

//--------------------
//   FUNCIÓN LISTAR
//--------------------

void listar_eq(int, equipo**);
void listar_jug(int, int, equipo**, futbolista**);
void listar_us(int, usuario**);
void listar_con(int, config**);

//-------------------
//    FUNCIÓN MOD
//-------------------

void mod_eq(int*, int, int, equipo**, futbolista**, futPlantilla**);
void mod_jug(int, int*, int, equipo**, futbolista**, futPlantilla**, config**);
void mod_us(int, int, usuario**);
void mod_con(int, config**);

//------------------------
//    FUNCIÓN ELIMINAR
//------------------------

void eliminar_eq(int, int, int, equipo**, futbolista**, futPlantilla**);
void eliminar_jug(int, int, int n_fpl, equipo**, futbolista**, futPlantilla**);
void eliminar_us(int, int, int, int, usuario**, plantilla**, futPlantilla**);

//----------------------
//    FUNCIÓN AÑADIR
//----------------------

void anadir_eq(int*, equipo**);
void anadir_jug(int, int*, equipo**, futbolista**, config**);
void anadir_us(char, int*, usuario**);

//-------------
//    OTRAS
//-------------

void gettot(char*, int*, config**);
int textest(char*);
int intest(char*);
int toint(char*);
void tostring(int, int, char*);
int pot(int, int);

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DEFINICIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//=-=-=-=-=-=-=-=-=-=-=
//        MENÚS
//=-=-=-=-=-=-=-=-=-=-=


//Cabecera: void m_equipo(int* n_eq, int* n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  fpl: relaciones futbolistas-plantillas
  con: campos de configuración
*/
//Postcondición: Muestra la interfaz de gestión de equipos. Permite Listar los equipos y modificar, crear o eliminar jugadores.
void m_equipo(int* n_eq, int* n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl, config** con)
{
    int n = 1;

    system("cls");

    do
    {
        if(n < 1 || n > 5)
        {
            system("pause");
            system("cls");
        }
        printf("\n\n  Gestion de equipos\n ====================\n\n 1.-Listar equipos\n 2.-Modificar equipos\n\n 3.-Listar jugadores\n"
               " 4.-Modificar jugadores\n\n 5.-Volver\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            listar_eq(*n_eq, eq);
            break;
        case 2:
            mod_eq(n_eq, *n_jug, n_fpl, eq, jug, fpl);
            break;
        case 3:
            listar_jug(*n_eq, *n_jug, eq, jug);
            break;
        case 4:
            mod_jug(*n_eq, n_jug, n_fpl, eq, jug, fpl, con);
        case 5:
            break;                  //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n !=5);
    system("cls");
}

//Cabecera: void m_usuario(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,
//                          plantilla** pl, futPlantilla** fpl, config** con)
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
//Postcondición: Muestra la interfaz de gestión de usuarios. Permite listar, modificar, crear y eliminar usuarios.

void m_usuario(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,
               plantilla** pl, futPlantilla** fpl, config** con)
{
    int n = 1, id = 0;
    char s[6];
    char c = 'u';           //IDENTIFICADOR DE LA FUNCIÓN

    system("cls");

    do
    {
        if(n < 1 || n > 5)
        {
            system("pause");
            system("cls");
        }

        printf("\n\n  Gestion de usuarios\n =====================\n"
               "\n 1.-Listar usuarios\n 2.-Modificar usuarios\n\n 3.-Gestion de plantillas\n\n 4.-Volver\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            listar_us(*n_us, us);
            break;
        case 2:
            system("cls");
            id = 0;
            do
            {
                if(n < 1 || n > 4)
                {
                    system("pause");
                    system("cls");
                }
                printf("\n\n  Modificacion de usuarios\n ==========================\n"
                       "\n 1.-Modificar cuentas\n 2.-A%cadir usuario\n 3.-Eliminar usuario\n\n 4.-Volver\n", 164);

                printf("\n Seleccion: ");
                scanf("%d",&n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    mod_us(idp, *n_us, us);
                    break;
                case 2:
                    anadir_us(c, n_us, us);
                    break;
                case 3:
                    eliminar_us(idp, *n_us, *n_pl, *n_fpl, us, pl, fpl);
                    break;
                case 4:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n != 4);
            system("cls");
            break;
        case 3:
            system("cls");

            do
            {
                if(n < 1 || n > 3)
                {
                    system("pause");
                    system("cls");
                }
                printf("\n Introduzca:\n 1.-Identificador de Usuario\n 2.-Nombre de cuenta\n\n 3.-Volver\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                id = 0;
                switch(n)
                {
                case 1:
                    system("cls");
                    printf("\n Introduzca identificador: ");
                    gets(s);
                    fflush(stdin);
                    strtok(s, "\n");
                    while(id >= 0 && id < *n_us && strcmp(s, (*us)[id].idUser) != 0 && strcmp((*us)[id].perfil, "Participante") != 0)
                        id++;
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduzca nombre de cuenta: ");
                    fgets(s, 6, stdin);
                    fflush(stdin);
                    strtok(s, "\n");
                    while(id >= 0 && id < *n_us && strcmp(s, (*us)[id].usuario) != 0 && strcmp((*us)[id].perfil, "Participante") != 0)
                        id++;
                    break;
                case 3:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n < 1 || n > 3);
            system("cls");
            if(n != 3)
            {
                if(id < 0 || id >= *n_us || strcmp((*us)[id].nombre, "\0") == 0 || strcmp((*us)[id].nombre, " ") == 0 || strcmp((*us)[id].perfil, "Participante") != 0)
                {
                    printf("\n\n=======================================================\n ERROR - USUARIO NO ENCONTRADO O NO ES UN PARTICIPANTE\n"
                           "=======================================================\n");
                    system("pause");
                } else
                    menuParticipante((*us)[id].idUser, (*us)[id].nombre, con, jug, eq, pl, fpl, n_pl, n_jug, n_eq, n_fpl);
            }
            system("cls");
            break;
        case 4:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    }
    while(n != 4);
    system("cls");
}

//Cabecera: void m_config(int n_con, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_con: número de campos de configuración de la aplicación

  Vector de estructuras:
  ----------------------
  con: campos de configuración
*/
//Postcondición: Muestra la interfaz de configuración de la aplicación. Permite ver y modificar la configuración.

void m_config(int n_con, config** con)
{
    int n = 1;

    system("cls");

    do
    {
        if(n < 1 || n > 3)
        {
            system("pause");
            system("cls");
        }
        printf("\n\n  Configuracion\n ================\n"
               "\n 1.-Ver configuracion actual\n 2.-Modificar configuracion\n\n 3.-Volver\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            listar_con(n_con, con);
            break;
        case 2:
            mod_con(n_con, con);
            break;
        case 3:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 3);
    system("cls");
}

//Cabecera: void m_admin(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,
//                       plantilla** pl, futPlantilla** fpl, config** con))
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
//Postcondición: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submenús de gestión de equipos, usuarios y configuración.

void m_admin(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us,         //INICIO DE ADMIN
             plantilla** pl, futPlantilla** fpl, config** con)
{
    int n;
    n = n_con;

    system("cls");

    gettot("", &n, con);            //Inicializa el valor de tam dentro de la función
    n = 1;

    printf("\n Bienvenido %s\n", (*us)[idp].nombre);
    do
    {
        if(n < 1 || n > 4)
        {
            system("pause");
            system("cls");
        }
        printf("\n\n Menu Administrador:\n ===================\n\n 1.-Equipos\n 2.-Usuario\n 3.-Configuracion\n\n 4.-Salir\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            m_equipo(n_eq, n_jug, *n_fpl, eq, jug, fpl, con);
            break;
        case 2:
            m_usuario(idp, n_eq, n_jug, n_us, n_pl, n_fpl, n_con, eq, jug, us, pl, fpl, con);
            break;
        case 3:
            m_config(n_con, con);
            break;
        case 4:     //VOLVER A LOG-IN
            system("cls");
            do
            {
                if(n != 1 && n != 2 && n != 4)
                {
                    system("pause");
                    system("cls");
                }
                printf("\n Seguro que quiere cerrar sesion?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    n = 4;
                    break;
                case 2:
                    break;
                case 4:
                    n = 0;
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            }
            while(n != 1 && n != 2 && n != 4);
            system("cls");
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    }
    while(n != 4);
    system("cls");
}

//=-=-=-=-=-=--=-=-=-=-=-=
//  FUNCIONES OPERATIVAS
//=-=-=-=-=-=--=-=-=-=-=-=

//--------------------
//   FUNCIÓN LISTAR
//--------------------

//Cabecera: void listar_eq(int n_eq, equipo** eq)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
*/
//Postcondición: Muestra listados todos los equipos

void listar_eq(int n_eq, equipo** eq)
{
    int n = 0, n0 = 0;

    system("cls");

    printf("\n  Equipos:\n ><><><><><\n");
    for(int id = 0; id < pot(10, sizeof((*eq)[0].idEquipo) - 1); id++)
    {
        n0 = 0;

        for(int i = 0; ((i == 0 && n_eq == 0) || i < n_eq) && n0 == 0; i++)
        {
            if(n_eq != 0)
            {
                if(toint((*eq)[i].idEquipo) == id && (*eq)[i].idEquipo[0] != '\0')
                {
                    printf("\n Equipo:\n =======\n ID: %s\n Nombre: %s\n", (*eq)[i].idEquipo, (*eq)[i].nombreEquipo);
                    n = 1;
                    n0 = 1;
                }
            }
        }
    }
    if(n == 0 || n_eq == 0)
        printf("\n================\n NO HAY EQUIPOS\n================\n");
    printf("\n=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=\n");

    printf("\n");
    system("pause");
    system("cls");
}

//Cabecera: void listar_jug(int n_eq, int n_jug, equipo** eq, futbolista** jug)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
*/
//Postcondición: Muestra listados todos los jugadores.

void listar_jug(int n_eq, int n_jug, equipo** eq, futbolista** jug)
{
    int n = 0, n0 = 0, ideq = 0;

    system("cls");

    printf("\n Jugadores:\n ==========\n");
    for(int id = 0; id < pot(10, sizeof((*jug)[0].idFutbolista) - 1); id++)
    {
        n0 = 0;
        for(int i = 0; ((i == 0 && n_jug == 0) || i < n_jug) && n0 == 0; i++)
        {
            if(n_jug != 0)
            {
                if(toint((*jug)[i].idFutbolista) == id && (*jug)[i].idFutbolista[0] != '\0')
                {
                    for(int j = 0; j < n_eq && n0 == 0; j++)
                    {
                        if(toint((*jug)[i].idEquipo) == toint((*eq)[j].idEquipo) && (*eq)[j].idEquipo[0] != '\0')
                        {
                            ideq = j;
                            n0 = 1;
                        }
                    }
                    printf("\n ID: %s\n Nombre: %s\n Equipo: %s\n Precio: %d\n Nota: %d\n", (*jug)[i].idFutbolista, (*jug)[i].nombre,
                           (*eq)[ideq].nombreEquipo, (*jug)[i].precio, (*jug)[i].puntuacion);
                    n = 1;
                    n0 = 1;
                }
            }
        }
    }
    if(n == 0 || n_jug == 0)
        printf("\n==================\n NO HAY JUGADORES\n==================\n");
    printf("\n=======================\n");

    printf("\n");
    system("pause");
    system("cls");
}

//Cabecera: void listar_us(int n_us, usuario** us)
//Precondición:
/*
  Variables:
  ----------
  n_us: número de usuarios en la aplicación

  Vector de estructuras:
  ----------------------
  us: usuarios
*/
//Postcondición: Muestra listados todos los usuarios.

void listar_us(int n_us, usuario** us)
{
    int n = 0, n0 = 0;

    system("cls");

    printf("\n Usuarios:\n><><>=<><><\n");
    for(int id = 0; id < pot(10, sizeof((*us)[0].idUser) - 1); id++)
    {
        n0 = 0;
        for(int i = 0; ((i == 0 && n_us == 0) || i < n_us) && n0 == 0; i++)
        {
            if(n_us != 0)
            {
                if(toint((*us)[i].idUser) == id && (*us)[i].idUser[0] != '\0')
                {
                    printf("\n ID: %s\n Nombre: %s\n Permisos: %s\n Nombre de usuario: %s\n Contrase%ca:", (*us)[i].idUser, (*us)[i].nombre, (*us)[i].perfil,
                           (*us)[i].usuario, 164);
                    if(strcmp((*us)[i].perfil, "Administrador") != 0)
                        printf(" %s\n", (*us)[i].password);
                    else
                        printf(" %s\n", "********");
                    n = 1;
                    n0 = 1;
                }
            }
        }
    }
    if(n == 0 || n_us == 0)
        printf("\n=================\n NO HAY USUARIOS\n=================\n");
    printf("\n");
    system("pause");
    system("cls");
}

//Cabecera: void listar_con(int n_con, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_con: número de campos de configuración de la aplicación

  Vector de estructuras:
  ----------------------
  con: campos de configuración
*/
//Postcondición: Muestra la configuración actual.

void listar_con(int n_con, config** con)
{
    system("cls");

    printf("\n Configuracion actual:\n ><><><><><><><><><><\n");
    for(int i = 0; i < n_con; i++)
        if(n_con != 0)
            printf("\n %s: %d\n", (*con)[i].data, (*con)[i].value);

    printf("\n");
    system("pause");
    system("cls");
}

//-------------------
//    FUNCIÓN MOD
//-------------------

//Cabecera: void mod_eq(int* n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  fpl: relaciones futbolistas-plantillas
*/
//Postcondición: Permite modificar las carácterísticas de cada equipo (nombre)

void mod_eq(int* n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
{
    int n = 1, id;
    char s[21];

    system("cls");

    do
    {
        if(n < 1 || n > 4)
        {
            system("pause");
            system("cls");
        }
        printf("\n Modificacion de equipo:\n=========================\n 1.-Cambiar nombre de equipo\n 2.-A%cadir equipo\n"
               " 3.-Eliminar equipo\n\n 4.-Volver\n\n Seleccion: ", 164);
        scanf("%d", &n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            id = 0;
            system("cls");
            do
            {
                printf("\n Introduzca:\n 1.-Identificador de equipo\n 2.-Nombre de equipo\n\n 3.-Volver\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    system("cls");
                    printf("\n Introduzca identificador: ");
                    gets(s);
                    fflush(stdin);
                    strtok(s, "\n");
                    system("cls");
                    while(id >= 0 && id < *n_eq && strcmp(s, (*eq)[id].idEquipo) != 0)
                        id++;
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduzca nombre de equipo: ");
                    fgets(s, 21, stdin);
                    fflush(stdin);
                    strtok(s, "\n");
                    system("cls");
                    while(id >= 0 && id < *n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                        id++;
                    break;
                case 3:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n < 1 || n > 3);
            system("cls");
            if(n != 3)
            {
                if(id < 0 || id >= *n_eq || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
                    printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                else
                {
                    do
                    {
                        system("cls");
                        printf("\n Nombre actual: %s\n Introduzca nuevo nombre de equipo: ", (*eq)[id].nombreEquipo);
                        fgets(s, 21, stdin);
                        fflush(stdin);
                        strtok(s, "\n");
                        system("cls");
                        if(textest(s) == 1)
                        {
                            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                            printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                        }
                        else
                        {
                            n = 0;
                            for(int j = 0; j < *n_eq && n == 0; j++)
                            {
                                if(strcmp(s, (*eq)[j].nombreEquipo) == 0 && id != j)
                                {
                                    system("cls");
                                    printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                                    n = 1;
                                    system("pause");
                                }
                            }
                        }
                        if(textest(s) == 0 && n == 0)
                        {
                            strcpy((*eq)[id].nombreEquipo, s);
                            printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                        }
                    } while(textest(s) == 1 || n == 1);
                }
                system("pause");
                system("cls");
            }
            break;
        case 2:
            anadir_eq(n_eq, eq);
            break;
        case 3:
            eliminar_eq(*n_eq, n_jug, n_fpl, eq, jug, fpl);
            break;
        case 4:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 4);
    system("cls");
}

//Cabecera: void mod_jug(int n_eq, int* n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  fpl: relaciones futbolistas-plantillas
  con: campos de configuración
*/
//Postcondición: Permite modificar las carácterísticas de cada jugador (nombre, precio, equipo al que pertenece).

void mod_jug(int n_eq, int* n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl, config** con)
{
    int n = 1, id, ideq, presu_base;
    char s[21];

    system("cls");

    gettot("presu_base", &presu_base, con);

    do
    {
        if(n < 1 || n > 4)
        {
            system("pause");
            system("cls");
        }
        printf("\n Modificacion de jugador:\n==========================\n 1.-Modificar jugador\n 2.-A%cadir jugador\n 3.-Eliminar jugador\n\n"
               " 4.-Volver\n\n Seleccion: ", 164);
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            system("cls");
            do
            {
                if(n < 1 || n > 3)
                {
                    system("pause");
                    system("cls");
                }
                printf("\n Introduzca:\n 1.-Identificador de jugador\n 2.-Nombre de jugador\n\n 3.-Volver\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    system("cls");
                    printf("\n Introduzca identificador: ");
                    gets(s);
                    fflush(stdin);
                    strtok(s, "\n");
                    while(id >= 0 && id < *n_jug && strcmp(s, (*jug)[id].idFutbolista) != 0)
                        id++;
                    break;
                case 2:
                    system("cls");
                    printf("\n Introduzca nombre de jugador: ");
                    fgets(s, 21, stdin);
                    fflush(stdin);
                    strtok(s, "\n");
                    id = 0;
                    while(id >= 0 && id < *n_jug && strcmp(s, (*jug)[id].nombre) != 0)
                        id++;
                    break;
                case 3:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n < 1 || n > 3);
            system("cls");
            if(n != 3)
            {
                ideq = 0;
                if(id < 0 || id >= *n_jug || strcmp((*jug)[id].nombre, "\0") == 0)
                {
                    printf("\n\n===============================\n ERROR - JUGADOR NO ENCONTRADO\n===============================\n");
                    system("pause");
                } else
                {
                    do
                    {
                        if(n < 1 || n > 5)
                        {
                            system("pause");
                            system("cls");
                        }
                        printf("\n Introduzca campo a modificar:\n ID: %s\n 1.-Nombre: %s\n 2.-Equipo: %s\n 3.-Precio: %d\n 4.-Nota: %d\n\n"
                               " 5.-Volver\n\n Seleccion: ", (*jug)[id].idFutbolista, (*jug)[id].nombre, (*eq)[toint((*jug)[id].idEquipo)].nombreEquipo,
                               (*jug)[id].precio, (*jug)[id].puntuacion);
                        scanf("%d", &n);
                        fflush(stdin);

                        switch(n)
                        {
                        case 1:

                            do
                            {
                                system("cls");
                                printf("\n Introduzca nuevo nombre de jugador: ");
                                fgets(s, 21, stdin);
                                fflush(stdin);
                                strtok(s, "\n");

                                if(textest(s) == 1)
                                {
                                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                    printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                                }
                                else
                                {
                                    n = 0;
                                    for(int j = 0; j < *n_jug && n == 0; j++)
                                    {
                                        if(strcmp(s, (*jug)[j].nombre) == 0 && id != j)
                                        {
                                            system("cls");
                                            printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                                            n = 1;
                                            system("pause");
                                        }
                                    }
                                }
                                if(textest(s) == 0 && n == 0)
                                {
                                    strcpy((*jug)[id].nombre, s);
                                    printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                                }
                            } while(textest(s) == 1 || n == 1);
                            system("pause");
                            system("cls");
                            break;
                        case 2:
                            system("cls");
                            ideq = 0;
                            do
                            {
                                if(n < 1 || n > 3)
                                {
                                    system("pause");
                                    system("cls");
                                }
                                printf("\n Introduzca:\n 1.-Identificador del nuevo equipo\n 2.-Nombre del nuevo equipo\n\n 3.-Volver\n\n Seleccion: ");
                                scanf("%d", &n);
                                fflush(stdin);

                                switch(n)
                                {
                                case 1:
                                    printf("\n Introduzca identificador: ");
                                    gets(s);
                                    fflush(stdin);
                                    strtok(s, "\n");
                                    while(ideq >= 0 && ideq < n_eq && strcmp(s, (*eq)[ideq].idEquipo) != 0)
                                        ideq++;
                                    break;
                                case 2:
                                    printf("\n Introduzca nombre del equipo: ");
                                    fgets(s, 21, stdin);
                                    fflush(stdin);
                                    strtok(s, "\n");

                                    ideq = 0;
                                    while(ideq >= 0 && ideq < n_eq && strcmp(s, (*eq)[ideq].nombreEquipo) != 0)
                                        ideq++;
                                    break;
                                case 3:
                                    break;
                                default:
                                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                }
                            } while(n < 1 || n > 4);
                            system("cls");
                            if(n == 1 || n == 2)
                            {
                                if(ideq < 0 || ideq >= n_eq || strcmp((*eq)[ideq].nombreEquipo, "\0") == 0)
                                    printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                                else
                                {
                                    tostring(ideq, sizeof (*jug)[id].idEquipo, (*jug)[id].idEquipo);
                                    printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                                }
                            }
                            n = 2;
                            system("pause");
                            system("cls");
                            break;
                        case 3:
                            do
                            {
                                system("cls");
                                printf("\n Introduzca nuevo precio de jugador: ");
                                scanf("%d", &(*jug)[id].precio);
                                fflush(stdin);

                                if((*jug)[id].precio <= 0 || (*jug)[id].precio > presu_base)
                                {
                                    printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                                           "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => %d\n\n", presu_base);
                                    system("pause");
                                }

                            } while((*jug)[id].precio <= 0 || (*jug)[id].precio > presu_base);
                            system("cls");
                            break;
                        case 4:
                            do
                            {
                                system("cls");
                                printf("\n Introduzca valoracion del jugador:\t");
                                scanf("%d", &n);
                                fflush(stdin);

                                if(n < 0 || n > 10)
                                {
                                    printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                                           "\n (PARA ESTE CAMPO)\n  MINIMO => 0\tMAXIMO => 10\n\n");
                                    system("pause");
                                }
                                else
                                {
                                    (*jug)[id].puntuacion = n;
                                    printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                                }


                            } while(n < 0 || n > 10);
                            system("pause");
                            system("cls");
                            break;
                        case 5:
                            break;
                        default:
                            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                        }
                    } while(n != 5);
                    n = 0;
                }
            }
            system("cls");
            break;
        case 2:
            anadir_jug(n_eq, n_jug, eq, jug, con);
            break;
        case 3:
            eliminar_jug(n_eq, *n_jug, n_fpl, eq, jug, fpl);
            break;
        case 4:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 4);
    system("cls");
}

//Cabecera: void mod_us(int idp, int n_us, usuario** us)
//Precondición:
/*
  Variables:
  ----------
  idp: identificador del usuario actual
  n_us: número de usuarios en la aplicación

  Vector de estructuras:
  ----------------------
  us: usuarios
*/
//Postcondición: Permite modificar las carácterísticas de cada usuario (permisos, contraseña, nombre).

void mod_us(int idp, int n_us, usuario** us)
{
    int n = 1, id, k = 0;
    char s[20], s1[6];

    system("cls");

    do
    {
        if(n < 1 || n > 3)
        {
            system("pause");
            system("cls");
        }
        printf("\n Introduzca:\n 1.-Identificador de Usuario\n 2.-Nombre de cuenta\n\n 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            while(id >= 0 && id < n_us && strcmp(s, (*us)[id].idUser) != 0 )
                id++;
            break;
        case 2:
            system("cls");
            printf("\n Introduzca nombre de cuenta: ");
            fgets(s, 6, stdin);
            fflush(stdin);
            strtok(s, "\n");

            id = 0;
            while(id >= 0 && id < n_us && strcmp(s, (*us)[id].usuario) != 0 )
                id++;
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 || n > 3);
    system("cls");
    if(n != 3)
    {
        if(id < 0 || id >= n_us || strcmp((*us)[id].nombre, "\0") == 0 || strcmp((*us)[id].nombre, " ") == 0)
        {
            printf("\n\n===============================\n ERROR - USUARIO NO ENCONTRADO\n===============================\n");
            system("pause");
        } else
        {
            if(strcmp((*us)[id].perfil, "Administrador") == 0)
            {
                printf("\n Introduzca contrase%ca: ", 164);
                gets(s);
                fflush(stdin);
                strtok(s, "\n");
                system("cls");
                if(strcmp((*us)[id].password, s) != 0)
                {
                    printf("\n\n=======================\n CONTRASE%cA INCORRECTA\n=======================\n", 165);
                    k = 1;
                } else
                {
                    printf("\n\n=====================\n CONTRASE%cA CORRECTA\n=====================\n", 165);
                    k = 0;
                }
                system("pause");
                system("cls");
            }
            if(k == 0)
            {
                system("cls");
                do
                {
                    if(n < 1 || n > 5)
                    {
                        system("pause");
                        system("cls");
                    }
                    printf("\n Elija campo a modificar: \n ID: %s\n 1.-Nombre: %s\n 2.-Permisos: %s\n 3.-Nombre de usuario: %s\n 4.-Contrase%ca: %s\n\n"
                           " 5.-Volver\n\n Seleccion: ", (*us)[id].idUser, (*us)[id].nombre, (*us)[id].perfil, (*us)[id].usuario, 164, (*us)[id].password);
                    scanf("%d", &n);
                    fflush(stdin);

                    switch(n)
                    {
                    case 1:
                        do
                        {
                            system("cls");
                            printf("\n Introduzca nuevo nombre: ");
                            fgets((*us)[id].nombre, 21, stdin);
                            fflush(stdin);
                            strtok((*us)[id].nombre, "\n");

                            if(textest((*us)[id].nombre) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                                system("pause");
                            }
                            else
                                printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                        } while(textest((*us)[id].nombre) == 1);
                        system("pause");
                        system("cls");
                        break;
                    case 2:
                        system("cls");
                        if(idp == toint((*us)[id].idUser))
                            printf("\n No puede modificar su propio nivel de permisos\n");
                        else
                        {
                            do
                            {

                                if(n < 1 || n > 3)
                                {
                                    system("pause");
                                    system("cls");
                                }
                                printf("\n Introduzca nuevos permisos:\n 1.-Administrador\n 2.-Cronista\n 3.-Participante\n\n Seleccion: ");
                                scanf("%d", &n);
                                fflush(stdin);

                                if(n == 1)
                                    strcpy((*us)[id].perfil, "Administrador");
                                else if(n == 2)
                                    strcpy((*us)[id].perfil, "Cronista");
                                else if(n == 3)
                                    strcpy((*us)[id].perfil, "Participante");
                            } while(n < 1 && n > 3);
                            printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                        }
                        system("pause");
                        system("cls");
                        break;
                    case 3:
                        do
                        {
                            system("cls");
                            printf("\n Introduzca nuevo nombre de usuario: ");
                            fgets(s1, 6, stdin);
                            fflush(stdin);
                            strtok(s1, "\n");

                            if(textest(s1) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                                system("pause");
                            }
                            else
                            {
                                n = 0;
                                for(int j = 0; j < n_us && n == 0; j++)
                                {
                                    if(strcmp(s1, (*us)[j].usuario) == 0 && id != j)
                                    {
                                        system("cls");
                                        printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                                        n = 1;
                                        system("pause");
                                    }
                                }
                            }
                            if(textest(s1) == 0 && n == 0)
                            {
                                strcpy((*us)[id].usuario, s1);
                                printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                            }
                        } while(textest(s1) == 1 || n == 1);
                        system("pause");
                        system("cls");
                        break;
                    case 4:
                        do
                        {
                            system("cls");
                            printf("\n Introduzca nueva contrase%ca: ", 164);
                            fgets((*us)[id].password, 9, stdin);
                            fflush(stdin);
                            strtok((*us)[id].password, "\n");

                            if(intest((*us)[id].password) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA O UN NUMERO\n");
                                system("pause");
                            }
                            else
                                printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                        } while(intest((*us)[id].password) == 1);
                        system("pause");
                        system("cls");
                        break;
                    case 5:
                        break;          //VOLVER
                    default:
                        printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                    }
                } while(n != 5);
            }
        }
    }
    system("cls");
}

//Cabecera: void mod_con(int n_con, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_con: número de campos de configuración de la aplicación

  Vector de estructuras:
  ----------------------
  con: campos de configuración
*/
//Postcondición: Permite modificar la configuración del programa.

void mod_con(int n_con, config** con)
{
    int n = 1, i = 0;
    char s[20];

    system("cls");

    printf("\n Elija campo a modificar: ");
    fgets(s, 20, stdin);
    fflush(stdin);
    strtok(s, "\n");
    while(i < n_con && strcmp(s, (*con)[i].data) != 0)
        i++;
    system("cls");
    if(i >= n_con)
    {
        printf("\n\n=============================\n ERROR - CAMPO NO ENCONTRADO\n=============================\n");
        system("pause");
    }
    else
    {
        do
        {
            system("cls");
            printf("\n\n Actualmente:\n   %s: %d\n\n", (*con)[i].data, (*con)[i].value);
            printf("\n Introduzca nuevo valor (""-1"" para cancelar): ");
            scanf("%d", &n);
            fflush(stdin);
            system("cls");
            if(n > 0 && n <= 999999999)
            {
                (*con)[i].value = n;
                printf("\n\n================\n CAMBIO EXITOSO\n================\n");
            }
            else if(n != -1)
            {

                printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                       "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => 999999999\n\n");
            }
            system("pause");
        } while(n < -1 || n == 0 || n > 999999999);
    }
    system("cls");
}

//------------------------
//    FUNCIÓN ELIMINAR
//------------------------

//Cabecera: void eliminar_eq(int n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  fpl: relaciones futbolistas-plantillas
*/
//Postcondición: Permite eliminar un equipo.

void eliminar_eq(int n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
{
    int n = 1, id;
    char s[20];

    system("cls");

    do
    {
        if(n < 1 || n > 3)
        {
            system("pause");
            system("cls");
        }

        printf("\n Eliminacion de equipo:\n ============================\n Introduzca:\n 1.-Identificador de equipo\n 2.-Nombre de equipo\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            system("cls");
            while(id >= 0 && id < n_eq && strcmp(s, (*eq)[id].idEquipo) != 0)
                id++;
            break;
        case 2:
            system("cls");
            printf("\n Introduzca nombre de equipo: ");
            fgets(s, 21, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                id++;
            system("cls");
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 || n > 3);
    system("cls");
    if(n != 3)
    {
        if(id < 0 || id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
            printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
        else
        {
            do
            {
                if(n < 1 || n > 2)
                {
                    system("pause");
                    system("cls");
                }
                printf("\n Equipo:\n =======\n ID: %s\n Nombre: %s\n\n Jugadores:\n ==========\n",(*eq)[id].idEquipo, (*eq)[id].nombreEquipo);
                n = 0;
                for(int j = 0; j < n_jug; j++)
                {
                    if((*jug)[j].nombre[0] != '\0' && toint((*jug)[j].idEquipo) == toint((*eq)[id].idEquipo) && (*jug)[j].idEquipo[0] != '\0')
                    {
                        printf("\n ID: %s\n Nombre: %s\n Equipo: %s\n Precio: %d\n Nota: %d\n",
                               (*jug)[j].idFutbolista, (*jug)[j].nombre, (*eq)[id].nombreEquipo, (*jug)[j].precio, (*jug)[j].puntuacion);
                        n = 1;
                    }
                    if(j == n_jug - 1 && n == 0)
                        printf("===================\n [SIN JUGADORES]\n===================");
                }
                printf("\n\n Desea eliminar este equipo? (Al eliminarlo todos los jugadores que tenga asignados tambien seran eliminados).\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            } while(n != 1 && n != 2);
            system("cls");
            if(n == 1)
            {
                for(int i = 0; i < n_jug; i++)
                {
                    if(toint((*eq)[id].idEquipo) == toint((*jug)[i].idEquipo) && (*jug)[i].idFutbolista[0] != '\0')
                    {
                        for(int j = 0; j < n_fpl; j++)
                        {
                            if(toint((*fpl)[j].idFutbolista) == toint((*jug)[i].idFutbolista) && (*jug)[j].idFutbolista[0] != '\0')
                            {
                                (*fpl)[j].idFutbolista[0] = '\0';
                                (*fpl)[j].idPlantilla[0] = '\0';
                            }
                        }
                        (*jug)[i].idEquipo[0] = '\0';
                        (*jug)[i].idFutbolista[0] = '\0';
                        (*jug)[i].nombre[0] = '\0';
                        (*jug)[i].precio = 0;
                        (*jug)[i].puntuacion = 0;
                    }
                }
                (*eq)[id].idEquipo[0] = '\0';
                (*eq)[id].nombreEquipo[0] = '\0';

                printf("\n>-----------------<\n EQUIPO ELIMINADO\n>-----------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
        }
    }
    system("pause");
    system("cls");
}

//Cabecera: void eliminar_jug(int n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  fpl: relaciones futbolistas-plantillas
*/
//Postcondición: Permite eliminar un jugador.

void eliminar_jug(int n_eq, int n_jug, int n_fpl, equipo** eq, futbolista** jug, futPlantilla** fpl)
{
    int n = 1, id = 0, n0 = 0, ideq = 0;
    char s[20];

    system("cls");

    do
    {
        if(n < 1 || n > 3)
        {
            system("pause");
            system("cls");
        }

        printf("\n Eliminacion de jugador:\n ============================\n Introduzca:\n 1.-Identificador de jugador\n 2.-Nombre de jugador\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            system("cls");
            while(id >= 0 && id < n_jug && strcmp(s, (*jug)[id].idFutbolista) != 0)
                id++;
            break;
        case 2:
            system("cls");
            printf("\n Introduzca nombre de jugador: ");
            fgets(s, 21, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_jug && strcmp(s, (*jug)[id].nombre) != 0)
                id++;
            system("cls");
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 || n > 3);
    system("cls");
    if(n != 3)
    {
        if(id < 0 || id >= n_jug || strcmp((*jug)[id].nombre, "\0") == 0)
            printf("\n\n===============================\n ERROR - JUGADOR NO ENCONTRADO\n===============================\n");
        else
        {
            n0 = 0;
            for(int j = 0; j < n_eq && n0 == 0; j++)
            {
                if(toint((*jug)[id].idEquipo) == toint((*eq)[j].idEquipo) && (*eq)[j].idEquipo[0] != '\0')
                {
                    ideq = j;
                    n0 = 1;
                }
            }
            n0 = 0;
            do
            {
                if(n < 1 || n > 2)
                {
                    system("pause");
                    system("cls");
                }

                printf("\n ID: %s\n Nombre: %s\n Equipo: %s\n Precio: %d\n Nota: %d\n", (*jug)[id].idFutbolista, (*jug)[id].nombre,
                       (*eq)[ideq].nombreEquipo, (*jug)[id].precio, (*jug)[id].puntuacion);

                printf("\n\n Desea eliminar este jugador?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                {
                    system("cls");
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n != 1 && n != 2);
            system("cls");
            if(n == 1)
            {
                for(int i = 0; i < n_fpl; i++)
                {
                    if(toint((*fpl)[i].idFutbolista) == toint((*jug)[id].idFutbolista))
                    {
                        (*fpl)[i].idFutbolista[0] = '\0';
                        (*fpl)[i].idPlantilla[0] = '\0';
                    }
                }
                (*jug)[id].idEquipo[0] = '\0';
                (*jug)[id].idFutbolista[0] = '\0';
                (*jug)[id].nombre[0] = '\0';
                (*jug)[id].precio = 0;
                (*jug)[id].puntuacion = 0;

                printf("\n>-------------------<\n JUGADOR ELIMINADO\n>-------------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
        }
    }
    system("pause");
    system("cls");
}

//Cabecera: void eliminar_us(int idp, int n_us, int n_pl, int n_fpl, usuario** us, plantilla** pl, futPlantilla** fpl)
//Precondición:
/*
  Variables:
  ----------
  idp: identificador del usuario actual
  n_us: número de usuarios en la aplicación
  n_pl: número de plantillas en la aplicación
  n_fpl: número de relaciones futbolista-plantilla en la aplicación

  Vector de estructuras:
  ----------------------
  us: usuarios
  pl: plantillas
  fpl: relaciones futbolistas-plantillas
*/
//Postcondición: Permite eliminar un usuario.

void eliminar_us(int idp, int n_us, int n_pl, int n_fpl, usuario** us, plantilla** pl, futPlantilla** fpl)
{
    int n = 1, id;
    char s[20];

    system("cls");

    do
    {
        if(n < 1 || n > 3)
        {
            system("pause");
            system("cls");
        }

        printf("\n Eliminacion de usuario:\n ============================\n\n Introduzca:\n 1.-Identificador de Usuario\n 2.-Nombre de cuenta\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            system("cls");
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            system("cls");
            while(id >= 0 && id < n_us && strcmp(s, (*us)[id].idUser) != 0 )
                id++;
            break;
        case 2:
            system("cls");
            printf("\n Introduzca nombre de cuenta: ");
            fgets(s, 6, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_us && strcmp(s, (*us)[id].usuario) != 0)
                id++;
            system("cls");
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 ||n > 3);
    system("cls");
    if(n != 3)
    {
        if(id < 0 || id >= n_us || id < 0 || strcmp((*us)[id].nombre, "\0") == 0)
            printf("\n\n===============================\n ERROR - USUARIO NO ENCONTRADO\n===============================\n");
        else if(id == idp)
            printf("\n\n======================================\n ERROR - NO PUEDE BORRARSE A SI MISMO\n======================================\n");
        else if(strcmp((*us)[id].perfil, "Administrador") == 0)
            printf("\n\n No es posible eliminar este usuario. Revoque sus permisos de administrador primero.\n\n");
        else
        {
            do
            {

                if(n < 1 || n > 2)
                {
                    system("pause");
                    system("cls");
                }

                printf("\n ID: %s\n Nombre: %s\n Permisos: %s\n Nombre de usuario: %s\n Contrase%ca: %s\n", (*us)[id].idUser, (*us)[id].nombre,
                       (*us)[id].perfil, (*us)[id].usuario, 164, (*us)[id].password);


                printf("\n\n Desea eliminar este usuario?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            } while(n != 1 && n != 2);
            system("cls");
            if(n == 1)
            {
                if(strcmp((*us)[id].perfil, "Participante") == 0)
                {
                    for(int i = 0; i < n_pl; i++)
                    {
                        if(toint((*pl)[i].idUsuario) == toint((*us)[id].idUser))
                        {
                            for(int j = 0; j < n_fpl; j++)
                            {
                                if(toint((*fpl)[j].idPlantilla) == toint((*pl)[i].idPlantilla))
                                {
                                    (*fpl)[j].idPlantilla[0] = '\0';
                                    (*fpl)[j].idFutbolista[0] = '\0';
                                }
                            }
                            (*pl)[i].idPlantilla[0] = '\0';
                            (*pl)[i].idUsuario[0] = '\0';
                            (*pl)[i].nombre[0] = '\0';
                            (*pl)[i].presupuesto = 0;
                            (*pl)[i].puntuacion = 0;
                        }
                    }
                }
                (*us)[id].idUser[0] = '\0';
                (*us)[id].nombre[0] = '\0';
                (*us)[id].perfil[0] = '\0';
                (*us)[id].usuario[0] = '\0';
                (*us)[id].password[0] = '\0';

                printf("\n>-----------------<\n USUARIO ELIMINADO\n>-----------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
        }
        system("pause");
        system("cls");
    }
}

//----------------------
//    FUNCIÓN AÑADIR
//----------------------

//Cabecera: void anadir_eq(int* n_eq, equipo** eq)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
*/
//Postcondición: Permite añadir un equipo.

void anadir_eq(int* n_eq, equipo** eq)
{
    int i = 0, n = 0, enc = 0, error = 0, k = 0;

    system("cls");

    while(i < *n_eq && (*eq)[i].idEquipo[0] != '\0')
        i++;
    if(i == *n_eq)
    {

        if(*n_eq + 1 <= pot(10, sizeof((*eq)[i].idEquipo) - 1))
        {
            if(((*eq) = (equipo*)realloc((*eq),(++(*n_eq))*sizeof(equipo))) == NULL)
            {
                printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA EQUIPOS\n\n");
                error = 1;
            }
        }
        else
        {
            printf("\n\n\tERROR - NUMERO DE IDENTIFICADOR MAXIMO ALCANZADO - SIN REGISTROS LIBRES\n\n");
            error = 1;
        }
    }
    if(error == 0)
    {
        (*eq)[i].idEquipo[0] = '\0';
        (*eq)[i].nombreEquipo[0] = '\0';

        enc = 0;
        for(int j = 0; j < pot(10, sizeof((*eq)[i].idEquipo) - 1) && enc == 0; j++)
        {
            n = 0;
            for(k = 0; k < *n_eq && n == 0; k++)
            {
                if(j == toint((*eq)[k].idEquipo) && (*eq)[k].idEquipo[0] != '\0')
                    n = 1;
            }
            if(k >= *n_eq && n == 0)
            {
                enc = 1;
                tostring(j, sizeof (*eq)[i].idEquipo, (*eq)[i].idEquipo);
            }
        }
        n = 0;
        do
        {
            printf("\n ID: %s\n", (*eq)[i].idEquipo);
            printf("\n Introduzca nombre de equipo:\t");
            fgets((*eq)[i].nombreEquipo, 21, stdin);
            fflush(stdin);
            strtok((*eq)[i].nombreEquipo, "\n");

            if(textest((*eq)[i].nombreEquipo) == 1)
            {
                system("cls");
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                system("pause");
            }
            else
            {
                n = 0;
                for(int j = 0; j < *n_eq && n == 0; j++)
                {
                    if(strcmp((*eq)[i].nombreEquipo, (*eq)[j].nombreEquipo) == 0 && i != j)
                    {
                        system("cls");
                        printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                        n = 1;
                        system("pause");
                    }
                }
            }
            system("cls");
        } while(textest((*eq)[i].nombreEquipo) == 1 || n == 1);

        printf("\n >--------------<\n  EQUIPO A%cADIDO\n >--------------<\n", 165);
    }
    system("pause");
    system("cls");
}

//Cabecera: void anadir_jug(int n_eq, int* n_jug, equipo** eq, futbolista** jug, config** con)
//Precondición:
/*
  Variables:
  ----------
  n_eq: número de equipos en la aplicación
  n_jug: número de futbolistas en la aplicación

  Vector de estructuras:
  ----------------------
  eq: equipos
  jug: futbolistas
  con: campos de configuración
*/
//Postcondición: Permite añadir un jugador.

void anadir_jug(int n_eq, int* n_jug, equipo** eq, futbolista** jug, config** con)
{
    int i = 0, n = 0, enc = 0, id, presu_base, error = 0, k = 0;
    char s[20];

    system("cls");

    gettot("presu_base", &presu_base, con);

    for(int i = 0; (i == 0 && n_eq == 0) || i < n_eq; i++)
    {
        if(n_eq != 0)
            if(strcmp((*eq)[i].idEquipo, "\0") != 0 && n_eq != 0)
                n = 1;
    }
    if(n == 1)
    {
        while(i < *n_jug && (*jug)[i].idFutbolista[0] != '\0')
            i++;
        if(i == *n_jug)
        {
            if(*n_jug + 1 <= pot(10, sizeof((*jug)[i].idFutbolista) - 1))
            {
                if(((*jug) = (futbolista*)realloc((*jug),(++(*n_jug))*sizeof(futbolista))) == NULL)
                {
                    printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA JUGADORES");
                    error = 1;
                }
            }
            else
            {
                printf("\n\n\tERROR - NUMERO DE IDENTIFICADOR MAXIMO ALCANZADO - SIN REGISTROS LIBRES\n\n");
                error = 1;
            }
        }
        if(error == 0)
        {
            (*jug)[i].idEquipo[0] = '\0';
            (*jug)[i].idFutbolista[0] = '\0';
            (*jug)[i].nombre[0] = '\0';
            (*jug)[i].precio = 0;
            (*jug)[i].puntuacion = 0;

            enc = 0;
            for(int j = 0; j < pot(10, sizeof((*jug)[i].idFutbolista) - 1) && enc == 0; j++)
            {
                n = 0;
                for(k = 0; k < *n_jug && n == 0; k++)
                {
                    if(j == toint((*jug)[k].idFutbolista) && (*jug)[k].idFutbolista[0] != '\0')
                        n = 1;
                }
                if(k >= *n_jug && n == 0)
                {
                    enc = 1;
                    tostring(j, sizeof (*jug)[i].idFutbolista, (*jug)[i].idFutbolista);
                }
            }
            n = 0;
            do
            {
                system("cls");
                printf("\n ID: %s\n", (*jug)[i].idFutbolista);
                printf("\n Introduzca nombre de jugador:\t");
                fgets((*jug)[i].nombre, 21, stdin);
                fflush(stdin);
                strtok((*jug)[i].nombre, "\n");

                if(textest((*jug)[i].nombre) == 1)
                {
                    system("cls");
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                    printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                    system("pause");
                }
                else
                {
                    n = 0;
                    for(int j = 0; j < *n_jug && n == 0; j++)
                    {
                        if(strcmp((*jug)[i].nombre, (*jug)[j].nombre) == 0 && i != j)
                        {
                            system("cls");
                            printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                            n = 1;
                            system("pause");
                        }
                    }
                }
            } while(textest((*jug)[i].nombre) == 1 || n == 1);
            system("cls");
            do
            {
                system("cls");
                printf("\n ID: %s\n Nombre: %s\n", (*jug)[i].idFutbolista, (*jug)[i].nombre);
                printf("\n Introduzca precio de jugador:\t");
                scanf("%d", &n);
                fflush(stdin);

                if(n <= 0 || n > presu_base)
                {
                    system("cls");
                    printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                           "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => %d\n\n", presu_base);
                    system("pause");
                }
                else
                    (*jug)[i].precio = n;
            } while(n <= 0 || n > presu_base);
            system("cls");
            do
            {
                system("cls");
                printf("\n ID: %s\n Nombre: %s\n Precio: %d\n", (*jug)[i].idFutbolista, (*jug)[i].nombre, (*jug)[i].precio);
                printf("\n Introduzca valoracion del jugador:\t");
                scanf("%d", &n);
                fflush(stdin);

                if(n < 0 || n > 10)
                {
                    system("cls");
                    printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                           "\n (PARA ESTE CAMPO)\n  MINIMO => 0\tMAXIMO => 10\n\n");
                    system("pause");
                }
                else
                    (*jug)[i].puntuacion = n;

            } while(n < 0 || n > 10);
            system("cls");
            n = 1;

            do
            {
                if(id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
                {
                    system("pause");
                    system("cls");
                }
                do
                {
                    if(n < 1 || n > 3)
                    {
                        system("pause");
                        system("cls");
                    }
                    printf("\n ID: %s\n Nombre: %s\n Precio: %d\n Nota: %d\n", (*jug)[i].idFutbolista, (*jug)[i].nombre, (*jug)[i].precio, (*jug)[i].puntuacion);
                    printf("\n A%cadir a un equipo:\n\n Introduzca:\n 1.-Listar equipos\n\n 2.-Identificador de equipo\n 3.-Nombre de equipo\n\n Seleccion: ", 164);
                    scanf("%d", &n);
                    fflush(stdin);

                    id = 0;
                    switch(n)
                    {
                    case 1:
                        listar_eq(n_eq, eq);
                        break;
                    case 2:
                        system("cls");
                        printf("\n Introduzca identificador: ");
                        gets(s);
                        fflush(stdin);
                        strtok(s, "\n");
                        system("cls");
                        while(id >= 0 && id < n_eq && strcmp(s, (*eq)[id].idEquipo) != 0)
                            id++;
                        break;
                    case 3:
                        system("cls");
                        printf("\n Introduzca nombre equipo al que pertenecera el jugador: ");
                        fgets(s, 21, stdin);
                        fflush(stdin);
                        strtok(s, "\n");

                        while(id < n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                            id++;
                        system("cls");
                        break;
                    default:
                        printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                    }
                } while(n < 2 || n > 3);
                system("cls");
                if(id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
                    printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                else
                {
                    strcpy((*jug)[i].idEquipo, (*eq)[id].idEquipo);
                    system("cls");
                    printf("\n >---------------<\n  JUGADOR A%cADIDO\n >---------------<\n", 165);
                }
            } while(id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0);
        }
    }
    else
        printf("\n PARA CREAR UN JUGADOR ES NECESARIO QUE EXISTA AL MENOS 1 EQUIPO\n\n");
    system("pause");
    system("cls");
}

//Cabecera: void anadir_us(char c, int* n_us, usuario** us)
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
//Postcondición: Permite añadir un usuario.

void anadir_us(char c, int* n_us, usuario** us)
{
    int i = 0, n = 1, enc = 0, error = 0, k = 0;

    system("cls");

    while(i < *n_us && (*us)[i].idUser[0] != '\0')
        i++;
    if(i == *n_us)
    {
        if(*n_us + 1 <= pot(10, sizeof((*us)[i].idUser) - 1))
        {
            if(((*us) = (usuario*)realloc((*us),(++(*n_us))*sizeof(usuario))) == NULL)
            {
                printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA JUGADORES");
                error = 1;
            }
        }
        else
        {
            printf("\n\n\tERROR - NUMERO DE IDENTIFICADOR MAXIMO ALCANZADO - SIN REGISTROS LIBRES\n\n");
            error = 1;
        }
    }
    if(error == 0)
    {

        (*us)[i].idUser[0] = '\0';
        (*us)[i].nombre[0] = '\0';
        (*us)[i].perfil[0] = '\0';
        (*us)[i].usuario[0] = '\0';
        (*us)[i].password[0] = '\0';

        enc = 0;
        for(int j = 0; j < pot(10, sizeof((*us)[i].idUser) - 1) && enc == 0; j++)
        {
            n = 0;
            for(k = 0; k < *n_us && n == 0; k++)
            {
                if(j == toint((*us)[k].idUser) && (*us)[k].idUser[0] != '\0')
                    n = 1;
            }
            if(k >= *n_us && n == 0)
            {
                enc = 1;
                tostring(j, sizeof (*us)[i].idUser, (*us)[i].idUser);
            }
        }
        n = 0;
        do
        {
            system("cls");
            if(c == 'u')
            {
                printf("\n ID: %s\n", (*us)[i].idUser);
            }
            printf("\n Introduzca nombre:\t");
            fgets((*us)[i].nombre, 21, stdin);
            fflush(stdin);
            strtok((*us)[i].nombre, "\n");

            if(textest((*us)[i].nombre) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                system("pause");
            }
        } while(textest((*us)[i].nombre) == 1);
        system("cls");
        if(c == 'u')            //Llamada desde menú de gestión de usuarios
        {
            do
            {
                if(n < 1 || n > 3)
                {
                    system("pause");
                    system("cls");
                }

                printf("\n ID: %s\n Nombre: %s\n", (*us)[i].idUser, (*us)[i].nombre);
                printf("\n Introduzca nuevos permisos:\n 1.-Administrador\n 2.-Cronista\n 3.-Participante\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                if(n == 1)
                    strcpy((*us)[i].perfil, "Administrador");
                else if(n == 2)
                    strcpy((*us)[i].perfil, "Cronista");
                else if(n == 3)
                    strcpy((*us)[i].perfil, "Participante");
            } while(n < 1 || n > 3);
        } else if(c == 'r')     //Llamada desde menú de registro de usuarios
            strcpy((*us)[i].perfil, "Participante");
        strtok((*us)[i].perfil, "\n");
        do
        {
            system("cls");

            if(c == 'u')
            {
                printf("\n ID: %s", (*us)[i].idUser);
            }
            printf("\n Nombre: %s\n Permisos: %s\n", (*us)[i].nombre, (*us)[i].perfil);
            printf("\n Introduzca nombre usuario:\t");
            fgets((*us)[i].usuario, 6, stdin);
            fflush(stdin);
            strtok((*us)[i].usuario, "\n");

            if(textest((*us)[i].usuario) == 1)
            {
                system("cls");
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                system("pause");
            }
            else
            {
                n = 0;
                for(int j = 0; j < *n_us && n == 0; j++)
                {
                    if(strcmp((*us)[i].usuario, (*us)[j].usuario) == 0 && i != j)
                    {
                        system("cls");
                        printf("\n\n NOMBRE INTRODUCIDO NO DISPONIBLE - PRUEBE OTRO NOMBRE\n\n");
                        n = 1;
                        system("pause");
                    }
                }
            }
        } while(textest((*us)[i].usuario) == 1 || n == 1);
        do
        {
            system("cls");
            if(c == 'u')
            {
                printf("\n ID: %s", (*us)[i].idUser);
            }
            printf("\n Nombre: %s\n Permisos: %s\n Nombre de usuario: %s\n", (*us)[i].nombre, (*us)[i].perfil, (*us)[i].usuario);
            printf("\n Introduzca contrase%ca:\t", 164);
            fgets((*us)[i].password, 9, stdin);
            fflush(stdin);
            strtok((*us)[i].password, "\n");

            if(intest((*us)[i].password) == 1)
            {
                system("cls");
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA O UN NUMERO\n");
                system("pause");
            }

        } while(intest((*us)[i].password) == 1);

        printf("\n >---------------<\n  USUARIO A%cADIDO\n >---------------<\n", 165);
    }
    system("pause");
    system("cls");
}

//-------------
//    OTRAS
//-------------

//Cabecera: void gettot(char* s, int* n, config** con)
//Precondición:
/*
  s: cadena a comparar
  n: salida de la función (excepto para la primera vez que es llamada, que se corresponderá con el número de campos de configuración)
  con: vector de estructuras correspondiente a la configuración
*/
//Postcondición: Calcula el valor deseado del campo indicado de la configuración.

void gettot(char* s, int* n, config** con)
{
    static int n0 = 1, tam;

    if(n0 == 0)
    {
        *n = 0;
        for(int i = 0; i < tam; i++)
            if(strcmp((*con)[i].data, s) == 0)
                *n = (*con)[i].value;
    }
    else
    {
        tam = *n;
        n0 = 0;
    }
}

//Cabecera: int textest(char *c)
//Precondición:
/*
  c: cadena de caracteres a verificar
*/
//Postcondición: comprueba si el primer elemento de la cadena es un caracter. Devolverá 0 si es un caracter, 1 si no lo es.

int textest(char* c)
{
    int n = 1;

    for(int i = (int)('a'); i <= (int)('z'); i++)
        if(c[0] == (char)i || c[0] == (char)(i - 32))
            n = 0;
    return(n);
}

//Cabecera: int intext(char *c)
//Precondición:
/*
  c: cadena de caracteres a verificar
*/
//Postcondición: comprueba si el primer elemento de la cadena es un caracter o un número. Devolverá 0 si es un caracter o un número, 1 si no lo es.

int intest(char* c)
{
    int n = 1;
    char s[2];
    s[0] = c[0];

    for(int i = 0; i < 10; i++)
        if(i == toint(s) && s[0] != '\n')
            n = 0;
    if(n == 1 && textest(c) == 0)
        n = 0;
    return(n);
}

//Cabecera: int toint(char *c)
//Precondición:
/*
  c: cadena de caracteres a convertir a entero
*/
//Postcondición: pasa el vector de caracteres dado a un entero.

int toint(char *c)
{
    char nat[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int res = 0;

    for(int i = strlen(c) - 1; i >= 0; i--)
    {
        for(int j = 0; j < 10; j++)
        {
            if(c[strlen(c) - 1 - i] == nat[j])
                res += j*pot(10, i);
        }
    }
    return(res);
}

//Cabecera: void tostring(int n, int tam, char *c)
//Precondición:
/*
  n: entero que se desea convertir a cadena de caracteres
  tam: tamaño del vector de caracteres destino
  c: cadena de caracteres se almacenará el resultado
*/
//Postcondición: pasa enteros a caracteres.

void tostring(int n, int tam, char* c)
{
    char nat[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int n0 = n, n1, k = 0;

    while(n0 > 0 || (n0 == 0 && k < 1))
    {
        n0 /= 10;
        k++;
    }
    if(n < 10 && tam > 2)
        k++;
    for(int i = k - 1; i >= 0; i--)
    {
        n1 = (n/pot(10, i) - (n/pot(10, (i + 1)))*10);

        for(int j = 0; j < 10; j++)
        {
            if(n1 == j)
                c[k - i - 1] = nat[j];
        }
    }
    c[k] = '\0';
}

//Cabecera: int pot(int n1, int n2)
//Precondición:
/*
  n1: base de la potencia
  n2: potencia a la que elevamos la base
*/
//Postcondición: devuelve la potencia de n1 elevada a n2

int pot(int n1, int n2)
{
    int res = 1;

    for(int i = 0; i < n2; i++)
        res *= n1;
    return(res);
}
