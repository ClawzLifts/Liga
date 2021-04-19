
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Admin.h"
#include "Cronista.h"

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//=-=-=-=-=-=-=-=-=-=-=
//        MENÚS
//=-=-=-=-=-=-=-=-=-=-=

void m_equipo(int*, int*, equipos**, jugadores**, config**);
void m_usuario(int, int*, usuario**);
void m_config(int, config**);
void m_admin(int, int*, int*, int*, int*, int, equipos**, jugadores**, usuario**, config**);

//=-=-=-=-=-=--=-=-=-=-=-=
//  FUNCIONES OPERATIVAS
//=-=-=-=-=-=--=-=-=-=-=-=

//--------------------
//   FUNCIÓN LISTAR
//--------------------

void listar_eq(int, equipos**);
void listar_jug(int, equipos**, jugadores**);
void listar_us(int, usuario**);
void listar_con(int, config**);

//-------------------
//    FUNCIÓN MOD
//-------------------

void mod_eq(int*, int, equipos**, jugadores**);
void mod_jug(int, int*, equipos**, jugadores**, config**);
void mod_us(int, usuario**);
void mod_con(int, config**);

//------------------------
//    FUNCIÓN ELIMINAR
//------------------------

void eliminar_eq(int, int, equipos**, jugadores**);
void eliminar_jug(int, equipos**, jugadores**);
void eliminar_us(int, int, usuario**);

//----------------------
//    FUNCIÓN AÑADIR
//----------------------

void anadir_eq(int*, equipos**);
void anadir_jug(int, int*, equipos**, jugadores**, config**);
void anadir_us(char, int*, usuario**);

//-------------
//    OTRAS
//-------------

void gettot(char*, int*, config**);
int textest(char*);
int intest(char*);
int toint(char*);
void tostring(int, char*);
int pot(int, int);

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DEFINICIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//=-=-=-=-=-=-=-=-=-=-=
//        MENÚS
//=-=-=-=-=-=-=-=-=-=-=

//Cabecera: void m_equipo(int* n_eq, int* n_jug, equipos *eq, jugadores *jug, config* con)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//              con es el vector de registros de configuración.
//Postcondición: Muestra la interfaz de gestión de equipos. Permite Listar los equipos y modificar, crear o eliminar jugadores.

void m_equipo(int* n_eq, int* n_jug, equipos** eq, jugadores** jug, config** con)
{
    int n;

    do
    {
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
            mod_eq(n_eq, *n_jug, eq, jug);
            break;
        case 3:
            listar_jug(*n_jug, eq, jug);
            break;
        case 4:
            mod_jug(*n_eq, n_jug, eq, jug, con);
        case 5:
            break;                  //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n !=5);
}

//Cabecera: void m_usuario(int* n_us, usuario* us)
//Precondición: n_us es el tamaño del vector de registros us, correspondientes a los usuarios.
//Postcondición: Muestra la interfaz de gestión de usuarios. Permite listar, modificar, crear y eliminar usuarios.

void m_usuario(int idp, int* n_us, usuario** us)
{
    int n;
    char c = 'u';           //IDENTIFICADOR DE LA FUNCIÓN

    do
    {
        printf("\n\n  Gestion de usuarios\n =====================\n"
               "\n 1.-Listar usuarios\n 2.-Modificar usuarios\n\n 3.-Mostrar plantillas\n 4.-Modificar plantillas\n\n 5.-Volver\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            listar_us(*n_us, us);
            break;
        case 2:
            do
            {
                printf("\n\n  Modificacion de usuarios\n ==========================\n"
                       "\n 1.-Modificar cuentas\n 2.-A%cadir usuario\n 3.-Eliminar usuario\n\n 4.-Volver\n", 164);

                printf("\n Seleccion: ");
                scanf("%d",&n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    mod_us(*n_us, us);
                    break;
                case 2:
                    anadir_us(c, n_us, us);
                    break;
                case 3:
                    eliminar_us(idp, *n_us, us);
                    break;
                case 4:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n != 4);
            break;
        case 3:
            //listar plantillas
            break;
        case 4:
            do
            {
                printf("\n\n  Modificacion de plantillas\n ============================\n"
                       "\n 1.-Modificar plantillas\n 2.-A%cadir plantilla\n 3.-Eliminar plantilla\n\n 4.-Volver\n", 164);

                printf("\n Seleccion: ");
                scanf("%d",&n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    //modificar plantillas
                    break;
                case 2:
                    //añadir plantilla
                    break;
                case 3:
                    //eliminar plantilla
                    break;
                case 4:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n != 4);
            break;
        case 5:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 5);
}

//Cabecera: void m_config(int n_con, config* con)
//Precondición: n_con es el tamaño del vector de registros con, correspondiente a la configuración.
//Postcondición: Muestra la interfaz de configuración de la aplicación. Permite ver y modificar la configuración.

void m_config(int n_con, config** con)
{
    int n;

    do
    {
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
}

//Cabecera: void m_admin(int* n_eq, int* n_jug, int* n_us, int* n_pl, int n_con, equipos *eq, jugadores *jug, usuario *us, config *con)
//Precondición:
//Postcondición: Muestra las opciones de trabajo del administrador. Permite "desplazarse" a los submenús de gestión de equipos, usuarios y configuración.

void m_admin(int idp, int* n_eq, int* n_jug, int* n_us, int* n_pl, int n_con, equipos** eq, jugadores** jug, usuario** us, config** con)        //INICIO DE ADMIN
{
    int n;
    n = n_con;

    gettot("", &n, con);            //Inicializa el valor de tam dentro de la función
    n = 0;

    printf("\n Bienvenido\n");
    do
    {

        printf("\n\n Menu Administrador:\n ===================\n\n 1.-Equipos\n 2.-Usuario\n 3.-Configuracion\n\n 4.-Salir\n");

        printf("\n Seleccion: ");
        scanf("%d",&n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            m_equipo(n_eq, n_jug, eq, jug, con);
            break;
        case 2:
            m_usuario(idp, n_us, us);
            break;
        case 3:
            m_config(n_con, con);
            break;
        case 4:
            do
            {
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
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            }
            while(n != 1 && n != 2 && n != 4);
            break;      //VOLVER A LOG-IN
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    }
    while(n != 4);
}

//=-=-=-=-=-=--=-=-=-=-=-=
//  FUNCIONES OPERATIVAS
//=-=-=-=-=-=--=-=-=-=-=-=

//--------------------
//   FUNCIÓN LISTAR
//--------------------

//Cabecera: void listar_eq(int n_eq, equipos* eq)
//Precondición: n_eq es el tamaño del vector de registros eq, correspondiente a los equipos.
//Postcondición: Muestra listados todos los equipos

void listar_eq(int n_eq, equipos** eq)
{
    int n = 0;
    printf("\n  Equipos:\n ><><><><><\n");
    for(int i = 0; (i == 0 && n_eq == 0) || i < n_eq; i++)
    {
        if(n_eq != 0)
        {
            if(strcmp((*eq)[i].id_equipo, "\0") != 0 && n_eq != 0)
            {
                printf("\n=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=\n");
                printf("\n Equipo:\n =======\n ID: %s\n Nombre: %s\n", (*eq)[i].id_equipo, (*eq)[i].nombreEquipo);
                n = 1;
            }
        }
        if((i == n_eq - 1 && n == 0) || n_eq == 0)
            printf("\n================\n NO HAY EQUIPOS\n================\n");
    }
    printf("\n=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=\n");

    printf("\n");
    system("pause");
}

//Cabecera: void listar_jug(int n_jug, equipos* eq, jugadores* jug)
//Precondición: n_jug es el tamaño del vector de registros jug, correspondiente a los jugadores. eq es el vector de registros de equipos.
//Postcondición: Muestra listados todos los jugadores.

void listar_jug(int n_jug, equipos** eq, jugadores** jug)
{
    int n = 0;
    printf("\n Jugadores:\n ==========\n");
    for(int i = 0; (i == 0 && n_jug == 0) || i < n_jug; i++)
    {   if(n_jug != 0)
        {
            if(strcmp((*jug)[i].id_jugador, "\0") != 0 && n_jug != 0)
            {
                printf("\n=======================\n");
                printf("\n ID: %s\n Nombre: %s\n Equipo: ", (*jug)[i].id_jugador, (*jug)[i].nombre);
                if(strcmp((*jug)[i].id_equipo, "\0") != 0)
                    printf("%s",(*eq)[toint((*jug)[i].id_equipo)].nombreEquipo);
                else
                    printf("%s", "[SIN EQUIPO]");
                printf("\n Precio: %d\n Nota: %d\n", (*jug)[i].valor, (*jug)[i].nota);
                n = 1;
            }
        }
        if((i == n_jug - 1 && n == 0) || n_jug == 0)
            printf("\n==================\n NO HAY JUGADORES\n==================\n");
    }
    printf("\n=======================\n");

    printf("\n");
    system("pause");
}

//Cabecera: void listar_us(int n_us, usuario* us)
//Precondición: n_us es el tamaño del vector de registros us, correspondiente a los usuarios.
//Postcondición: Muestra listados todos los usuarios.

void listar_us(int n_us, usuario** us)
{
    int n = 0;
    printf("\n Usuarios:\n><><>=<><><\n");
    for(int i = 0; (i == 0 && n_us == 0) || i < n_us; i++)
    {
        if(n_us != 0)
        {
            if(strcmp((*us)[i].idUser, "\0") != 0 && n_us != 0)
            {
                printf("\n ID: %s\n Nombre: %s\n Permisos: %s\n Nombre de usuario: %s\n Contrase%ca:", (*us)[i].idUser, (*us)[i].nombre, (*us)[i].permisos,
                       (*us)[i].usuario, 164);
                if(strcmp((*us)[i].permisos, "Administrador") != 0)
                    printf(" %s\n", (*us)[i].password);
                else
                    printf(" %s\n", "********");
                n = 1;
            }
        }
        if((i == n_us - 1 && n == 0) || n_us == 0)
            printf("\n=================\n NO HAY USUARIOS\n=================\n");
    }
    printf("\n");
    system("pause");
}

//Cabecera: void listar_con(int n_con, config* con)
//Precondición: n_con es el tamaño del vector de registros con, correspondiente a la configuración.
//Postcondición: Muestra la configuración actual.

void listar_con(int n_con, config** con)
{
    printf("\n Configuracion actual:\n ><><><><><><><><><><\n");
    for(int i = 0; i < n_con; i++)
        if(n_con != 0)
            printf("\n %s: %d\n", (*con)[i].campo, (*con)[i].value);

    printf("\n");
    system("pause");
}

//-------------------
//    FUNCIÓN MOD
//-------------------

//Cabecera: void mod_eq(int* n_eq, int n_jug, equipos* eq, jugadores* jug)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//Postcondición: Permite modificar las carácterísticas de cada equipo (nombre)

void mod_eq(int* n_eq, int n_jug, equipos** eq, jugadores** jug)
{
    int n, id;
    char s[21];
    do
    {
        printf("\n Modificacion de equipo:\n=========================\n 1.-Cambiar nombre de equipo\n 2.-A%cadir equipo\n 3.-Eliminar equipo\n\n 4.-Volver\n\n Seleccion: ", 164);
        scanf("%d", &n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            id = 0;
            do
            {
                printf("\n Introduzca:\n 1.-Identificador de equipo\n 2.-Nombre de equipo\n\n 3.-Volver\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    printf("\n Introduzca identificador: ");
                    gets(s);
                    fflush(stdin);
                    strtok(s, "\n");
                    id = toint(s);

                    break;
                case 2:
                    printf("\n Introduzca nombre de equipo: ");
                    fgets(s, 21, stdin);
                    fflush(stdin);
                    strtok(s, "\n");

                    while(id >= 0 && id < *n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                        id++;
                    break;
                case 3:
                    break;
                default:
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                }
            } while(n < 1 || n > 3);
            if(n != 3)
            {
                if(id < 0 || id >= *n_eq || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
                {
                    printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                    system("pause");
                }
                else
                {
                    do
                    {
                        printf("\n Introduzca nuevo nombre de equipo: ");
                        fgets(s, 21, stdin);
                        fflush(stdin);
                        strtok(s, "\n");

                        if(textest(s) == 1)
                        {
                            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                            printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                        }
                        else
                            strcpy((*eq)[id].nombreEquipo, s);

                    } while(textest((*eq)[id].nombreEquipo) == 1);
                }
            }
            break;
        case 2:
            anadir_eq(n_eq, eq);
            break;
        case 3:
            eliminar_eq(*n_eq, n_jug, eq, jug);
            break;
        case 4:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 4);
}

//Cabecera: void mod_jug(int n_eq, int* n_jug, equipos* eq, jugadores* jug, config* con)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//              con es el vector de registros de configuración.
//Postcondición: Permite modificar las carácterísticas de cada jugador (nombre, precio, equipo al que pertenece).

void mod_jug(int n_eq, int* n_jug, equipos** eq, jugadores** jug, config** con)
{
    int n, id, ideq, presu_base;
    char s[21];

    gettot("presu_base", &presu_base, con);

    do
    {
        printf("\n Modificacion de jugador:\n==========================\n 1.-Modificar jugador\n 2.-A%cadir jugador\n 3.-Eliminar jugador\n\n"
               " 4.-Volver\n\n Seleccion: ", 164);
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            do
            {
                printf("\n Introduzca:\n 1.-Identificador de jugador\n 2.-Nombre de jugador\n\n 3.-Volver\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                switch(n)
                {
                case 1:
                    printf("\n Introduzca identificador: ");
                    gets(s);
                    fflush(stdin);
                    strtok(s, "\n");
                    id = toint(s);
                    break;
                case 2:
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
                        printf("\n Introduzca campo a modificar:\n ID: %s\n 1.-Nombre: %s\n 2.-Equipo: ", (*jug)[id].id_jugador,
                               (*jug)[id].nombre);
                        if((*jug)[id].id_equipo[0] != '\0')
                            printf("%s", (*eq)[toint((*jug)[id].id_equipo)].nombreEquipo);
                        else
                            printf("[SIN EQUIPO]");
                        printf("\n 3.-Precio: %d\n 4.-Nota: %d\n\n 5.-Volver\n\n Seleccion: ", (*jug)[id].valor, (*jug)[id].nota);
                        scanf("%d", &n);
                        fflush(stdin);

                        switch(n)
                        {
                        case 1:
                            do
                            {
                                printf("\n Introduzca nuevo nombre de jugador: ");
                                fgets((*jug)[id].nombre, 21, stdin);
                                fflush(stdin);
                                strtok((*jug)[id].nombre, "\n");

                                if(textest((*jug)[id].nombre) == 1)
                                {
                                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                    printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                                }

                            } while(textest((*jug)[id].nombre) == 1);
                            break;
                        case 2:
                            do
                            {
                                printf("\n Introduzca:\n 1.-Identificador del nuevo equipo\n 2.-Nombre del nuevo equipo\n 3.-Quitar de equipo\n\n"
                                       " 4.-Volver\n\n Seleccion: ");
                                scanf("%d", &n);
                                fflush(stdin);

                                switch(n)
                                {
                                case 1:
                                    printf("\n Introduzca identificador: ");
                                    gets(s);
                                    fflush(stdin);
                                    strtok(s, "\n");
                                    ideq = toint(s);

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
                                    if(strcmp((*jug)[id].id_equipo, "\0") == 0)
                                        printf("\n=============================\n JUGADOR SIN EQUIPO ASIGNADO\n=============================\n\n");
                                    else
                                    {
                                        (*jug)[id].id_equipo[0] = '\0';
                                        printf("\n\n================\n CAMBIO EXITOSO\n================\n\n");
                                    }
                                    system("pause");
                                    break;
                                case 4:
                                    break;
                                default:
                                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                }
                            } while(n < 1 || n > 4);
                            if(n == 1 || n == 2)
                            {
                                if(ideq < 0 || ideq >= n_eq || strcmp((*eq)[ideq].nombreEquipo, "\0") == 0)
                                {
                                    printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                                    system("pause");
                                }
                                else
                                {
                                    tostring(ideq, (*jug)[id].id_equipo);
                                    printf("\n\n================\n CAMBIO EXITOSO\n================\n");
                                    system("pause");
                                }
                            }
                            n = 2;
                            break;
                        case 3:
                            do
                            {
                                printf("\n Introduzca nuevo precio de jugador: ");
                                scanf("%d", &(*jug)[id].valor);
                                fflush(stdin);

                                if((*jug)[id].valor <= 0 || (*jug)[id].valor > presu_base)
                                {
                                    printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                                           "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => %d\n\n", presu_base);
                                    system("pause");
                                }

                            } while((*jug)[id].valor <= 0 || (*jug)[id].valor > presu_base);
                            break;
                        case 4:
                            do
                            {
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
                                    (*jug)[id].nota = n;

                            } while(n < 0 || n > 10);
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
            break;
        case 2:
            anadir_jug(n_eq, n_jug, eq, jug, con);
            break;
        case 3:
            eliminar_jug(*n_jug, eq, jug);
            break;
        case 4:
            break;          //VOLVER AL MENÚ PRINCIPAL
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 4);
}

//Cabecera: void mod_us(int n_us, usuario* us)
//Precondición: n_us es el tamaño del vector de registros us, correspondientes a los usuarios.
//Postcondición: Permite modificar las carácterísticas de cada usuario (permisos, contraseña, nombre).

void mod_us(int n_us, usuario** us)
{
    int n, id, k = 0;
    char s[20];

    do
    {
        printf("\n Introduzca:\n 1.-Identificador de Usuario\n 2.-Nombre de cuenta\n\n 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            id = toint(s);
            break;
        case 2:
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
    if(n != 3)
    {
        if(id < 0 || id >= n_us || strcmp((*us)[id].nombre, "\0") == 0 || strcmp((*us)[id].nombre, " ") == 0)
        {
            printf("\n\n===============================\n ERROR - USUARIO NO ENCONTRADO\n===============================\n");
            system("pause");
        } else
        {
            if(strcmp((*us)[id].permisos, "Administrador") == 0)
            {
                printf("\n Introduzca contrase%ca: ", 164);
                gets(s);
                fflush(stdin);
                strtok(s, "\n");

                if(strcmp((*us)[id].password, s) != 0)
                {
                    printf("\n\n=======================\n CONTRASE%cA INCORRECTA\n=======================\n", 165);
                    k = 1;
                    system("pause");
                } else
                {
                    printf("\n\n=====================\n CONTRASE%cA CORRECTA\n=====================\n", 165);
                    k = 0;
                    system("pause");
                }
            }
            if(k == 0)
            {
                do
                {
                    printf("\n ID: %s\n 1.-Nombre: %s\n 2.-Permisos: %s\n 3.-Nombre de usuario: %s\n 4.-Contrase%ca: %s\n\n 5.-Volver\n", (*us)[id].idUser, (*us)[id].nombre,
                           (*us)[id].permisos, (*us)[id].usuario, 164, (*us)[id].password);

                    printf("\n Elija campo a modificar: ");
                    scanf("%d", &n);
                    fflush(stdin);

                    switch(n)
                    {
                    case 1:
                        do
                        {
                            printf("\n Introduzca nuevo nombre: ");
                            fgets((*us)[id].nombre, 21, stdin);
                            fflush(stdin);
                            strtok((*us)[id].nombre, "\n");

                            if(textest((*us)[id].nombre) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                            }

                        } while(textest((*us)[id].nombre) == 1);
                        break;
                    case 2:
                        do
                        {
                            printf("\n Introduzca nuevos permisos:\n 1.-Administrador\n 2.-Cronista\n 3.-Participante\n\n Seleccion: ");
                            scanf("%d", &n);
                            fflush(stdin);

                            if(n == 1)
                                strcpy((*us)[id].permisos, "Administrador");
                            else if(n == 2)
                                strcpy((*us)[id].permisos, "Cronista");
                            else if(n == 3)
                                strcpy((*us)[id].permisos, "Participante");
                        } while(n < 1 && n > 3);
                        break;
                    case 3:
                        do
                        {
                            printf("\n Introduzca nuevo nombre de usuario: ");
                            fgets((*us)[id].usuario, 6, stdin);
                            fflush(stdin);
                            strtok((*us)[id].usuario, "\n");

                            if(textest((*us)[id].usuario) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
                            }

                        } while(textest((*us)[id].usuario) == 1);
                        break;
                    case 4:
                        do
                        {
                            printf("\n Introduzca nueva contrase%ca: ", 164);
                            fgets((*us)[id].password, 9, stdin);
                            fflush(stdin);
                            strtok((*us)[id].password, "\n");

                            if(intest((*us)[id].password) == 1)
                            {
                                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                                printf("\n INICIE EL NOMBRE POR UNA LETRA O UN NUMERO\n");
                            }

                        } while(intest((*us)[id].password) == 1);
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
}

//Cabecera: void mod_us(int n_con, config* con)
//Precondición: n_con es el tamaño del vector de registros con, correspondiente a la configuración.
//Postcondición: Permite modificar la configuración del programa.

void mod_con(int n_con, config** con)
{
    int n, i = 0;
    char s[20];

    printf("\n Elija campo a modificar: ");
    fgets(s, 20, stdin);
    fflush(stdin);
    strtok(s, "\n");
    while(i < n_con && strcmp(s, (*con)[i].campo) != 0)
        i++;
    if(i >= n_con)
    {
        printf("\n\n=============================\n ERROR - CAMPO NO ENCONTRADO\n=============================\n");
        system("pause");
    }
    else
    {
        printf("\n\n Actualmente:\n   %s: %d\n\n", (*con)[i].campo, (*con)[i].value);
        do
        {
            printf("\n Introduzca nuevo valor (""-1"" para cancelar): ");
            scanf("%d", &n);
            fflush(stdin);
            if(n > 0 && n <= 999999999)
                (*con)[i].value = n;
            else if(n != -1)
            {
                printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                       "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => 999999999\n\n");
                system("pause");
            }
        } while(n < -1 || n == 0 || n > 999999999);
    }
}

//------------------------
//    FUNCIÓN ELIMINAR
//------------------------

//Cabecera: void eliminar_eq(int n_eq, int n_jug, equipos* eq, jugadores* jug)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//Postcondición: Permite eliminar un equipo.

void eliminar_eq(int n_eq, int n_jug, equipos** eq, jugadores** jug)
{
    int n, id;
    char s[20];
    do
    {
        printf("\n Eliminacion de equipo:\n ============================\n Introduzca:\n 1.-Identificador de equipo\n 2.-Nombre de equipo\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            id = toint(s);
            break;
        case 2:
            printf("\n Introduzca nombre de equipo: ");
            fgets(s, 21, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                id++;
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 || n > 3);
    if(n != 3)
    {
        if(id < 0 || id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
        {
            printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
            system("pause");
        } else
        {
            printf("\n Equipo:\n =======\n ID: %s\n Nombre: %s\n\n Jugadores:\n ==========\n",(*eq)[id].id_equipo, (*eq)[id].nombreEquipo);
            n = 0;
            for(int j = 0; j < n_jug; j++)
            {
                if(strcmp((*jug)[j].nombre, "\0") != 0 && strcmp((*jug)[j].id_equipo, (*eq)[id].id_equipo) == 0)
                {
                    printf("\n=======================\n ID: %s\n Nombre: %s\n Equipo: ", (*jug)[j].id_jugador, (*jug)[j].nombre);
                    if(strcmp((*jug)[j].id_equipo, "\0") != 0)
                        printf("%s", (*eq)[toint((*jug)[j].id_equipo)].nombreEquipo);
                    else
                        printf("%s", "[SIN EQUIPO]");
                    printf("\n Precio: %d\n Nota: %d\n\n=======================", (*jug)[j].valor, (*jug)[j].nota);
                    n = 1;
                }

                if(j == n_jug - 1 && n == 0)
                    printf("===================\n [SIN JUGADORES]\n===================");
            }
            do
            {
                printf("\n\n Desea eliminar este equipo?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            } while(n != 1 && n != 2);

            if(n == 1)
            {
                for(int i = 0; i < n_jug; i++)
                    if(toint((*eq)[id].id_equipo) == toint((*jug)[i].id_equipo))
                        (*jug)[i].id_equipo[0] = '\0';

                (*eq)[id].id_equipo[0] = '\0';
                (*eq)[id].nombreEquipo[0] = '\0';

                printf("\n>-----------------<\n EQUIPO ELIMINADO\n>-----------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
            system("pause");
        }
    }
}

//Cabecera: void eliminar_jug(int n_jug, equipos* eq, jugadores* jug)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//Postcondición: Permite eliminar un jugador.

void eliminar_jug(int n_jug, equipos** eq, jugadores** jug)
{
    int n, id = 0;
    char s[20];
    do
    {
        printf("\n Eliminacion de jugador:\n ============================\n Introduzca:\n 1.-Identificador de jugador\n 2.-Nombre de jugador\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            id = toint(s);
            break;
        case 2:
            printf("\n Introduzca nombre de jugador: ");
            fgets(s, 21, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_jug && strcmp(s, (*jug)[id].nombre) != 0)
                id++;
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 || n > 3);
    if(n != 3)
    {
        if(id < 0 || id >= n_jug || strcmp((*jug)[id].nombre, "\0") == 0)
        {
            printf("\n\n===============================\n ERROR - JUGADOR NO ENCONTRADO\n===============================\n");
            system("pause");
        } else
        {
            printf(" ID: %s\n Nombre: %s\n Equipo: ", (*jug)[id].id_jugador, (*jug)[id].nombre);
            if(strcmp((*jug)[id].id_equipo, "\0") != 0)
                printf("%s", (*eq)[toint((*jug)[id].id_equipo)].nombreEquipo);
            else
                printf("%s", "[SIN EQUIPO]");
            printf("\n Precio: %d\n Nota: %d\n\n=======================", (*jug)[id].valor, (*jug)[id].nota);
            do
            {
                printf("\n\n Desea eliminar este jugador?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            } while(n != 1 && n != 2);

            if(n == 1)
            {
                (*jug)[id].id_equipo[0] = '\0';
                (*jug)[id].id_jugador[0] = '\0';
                (*jug)[id].nombre[0] = '\0';
                (*jug)[id].valor = 0;
                (*jug)[id].nota = 0;

                printf("\n>-------------------<\n JUGADOR ELIMINADO\n>-------------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
            system("pause");
        }
    }
}

//Cabecera: void eliminar_us(int n_us, usuario* us)
//Precondición: n_us es el tamaño del vector de registros us, correspondientes a los usuarios.
//Postcondición: Permite eliminar un usuario.

void eliminar_us(int idp, int n_us, usuario** us)
{
    int n, id;
    char s[20];

    do
    {
        printf("\n Eliminacion de usuario:\n ============================\n\n Introduzca:\n 1.-Identificador de Usuario\n 2.-Nombre de cuenta\n\n"
               " 3.-Volver\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        id = 0;
        switch(n)
        {
        case 1:
            printf("\n Introduzca identificador: ");
            gets(s);
            fflush(stdin);
            strtok(s, "\n");
            id = toint(s);
            break;
        case 2:
            printf("\n Introduzca nombre de cuenta: ");
            fgets(s, 6, stdin);
            fflush(stdin);
            strtok(s, "\n");

            while(id >= 0 && id < n_us && strcmp(s, (*us)[id].usuario) != 0)
                id++;
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n < 1 ||n > 3);
    if(n != 3)
    {
        if(id < 0 || id >= n_us || id < 0 || strcmp((*us)[id].nombre, "\0") == 0)
            printf("\n\n===============================\n ERROR - USUARIO NO ENCONTRADO\n===============================\n");
        else if(id == idp)
            printf("\n\n======================================\n ERROR - NO PUEDE BORRARSE A SI MISMO\n======================================\n");
        else if(strcmp((*us)[id].permisos, "Administrador") == 0)
            printf("\n\n No es posible eliminar este usuario. Revoque sus permisos de administrador primero.\n\n");
        else
        {
            printf("\n ID: %s\n Nombre: %s\n Permisos: %s\n Nombre de usuario: %s\n Contrase%ca: %s\n", (*us)[id].idUser, (*us)[id].nombre,
                   (*us)[id].permisos, (*us)[id].usuario, 164, (*us)[id].password);

            do
            {
                printf("\n\n Desea eliminar este usuario?\n 1.-Si\n 2.-No\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);
                if(n != 1 && n != 2)
                    printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            } while(n != 1 && n != 2);

            if(n == 1)
            {
                (*us)[id].idUser[0] = '\0';
                (*us)[id].nombre[0] = '\0';
                (*us)[id].permisos[0] = '\0';
                (*us)[id].usuario[0] = '\0';
                (*us)[id].password[0] = '\0';

                printf("\n>-----------------<\n USUARIO ELIMINADO\n>-----------------<\n");
            } else if(n == 2)
                printf("\n>-----------------<\n PROCESO CANCELADO\n>-----------------<\n");
        }
        system("pause");
    }
}

//----------------------
//    FUNCIÓN AÑADIR
//----------------------

//Cabecera: void anadir_eq(int* n_eq, equipos* eq)
//Precondición: n_eq es el tamaño del vector de registros eq, correspondientes a los equipos.
//Postcondición: Permite añadir un equipo.

void anadir_eq(int* n_eq, equipos** eq)
{
    int i = 0, error = 0;

    while(i < *n_eq && (*eq)[i].id_equipo[0] != '\0')
        i++;

    if(i == *n_eq)
    {
        if(((equipos*)realloc((*eq),(++(*n_eq))*sizeof(equipos))) == NULL)
        {
            printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA EQUIPOS");
            error = 1;
        }
    }
    if(error == 0)
    {

        (*eq)[i].id_equipo[0] = '\0';
        (*eq)[i].nombreEquipo[0] = '\0';

        tostring(i, (*eq)[i].id_equipo);
        printf("\n ID: %s\n", (*eq)[i].id_equipo);
        do
        {
            printf("\n Introduzca nombre de equipo:\t");
            fgets((*eq)[i].nombreEquipo, 21, stdin);
            fflush(stdin);
            strtok((*eq)[i].nombreEquipo, "\n");

            if(textest((*eq)[i].nombreEquipo) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
            }

        } while(textest((*eq)[i].nombreEquipo) == 1);

        printf("\n >--------------<\n  EQUIPO A%cADIDO\n >--------------<\n", 165);
    }
    system("pause");
}

//Cabecera: void anadir_jug(int n_eq, int* n_jug, equipos* eq, jugadores* jug, config* con)
//Precondición: n_eq y n_jug son el tamaño de los respectivos vectores de registros eq y jug, correspondientes a los equipos y jugadores.
//              con es el vector de registros de configuración.
//Postcondición: Permite añadir un jugador.

void anadir_jug(int n_eq, int* n_jug, equipos** eq, jugadores** jug, config** con)
{
    int i = 0, n, id, presu_base, error = 0;
    char s[20];

    gettot("presu_base", &presu_base, con);

    while(i < *n_jug && (*jug)[i].id_jugador[0] != '\0')
        i++;
    if(i == *n_jug)
    {
        if(((*jug) = (jugadores*)realloc((*jug),(++(*n_jug))*sizeof(jugadores))) == NULL)
        {
            printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA JUGADORES");
            error = 1;
            system("pause");
        }
    }
    if(error == 0)
    {

        (*jug)[i].id_equipo[0] = '\0';
        (*jug)[i].id_jugador[0] = '\0';
        (*jug)[i].nombre[0] = '\0';
        (*jug)[i].valor = 0;
        (*jug)[i].nota = 0;

        tostring(i, (*jug)[i].id_jugador);
        printf("\n id: %s\n", (*jug)[i].id_jugador);

        do
        {
            printf("\n Introduzca nombre de jugador:\t");
            fgets((*jug)[i].nombre, 21, stdin);
            fflush(stdin);
            strtok((*jug)[i].nombre, "\n");

            if(textest((*jug)[i].nombre) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
            }

        } while(textest((*jug)[i].nombre) == 1);
        do
        {
            printf("\n Introduzca precio de jugador:\t");
            scanf("%d", &n);
            fflush(stdin);

            if(n <= 0 || n > presu_base)
            {
                printf("\n\n =-=-=-=-=-=-=-=\n  VALOR NO APTO\n =-=-=-=-=-=-=-=\n"
                       "\n (PARA ESTE CAMPO)\n  MINIMO => 1\tMAXIMO => %d\n\n", presu_base);
                system("pause");
            }
            else
                (*jug)[i].valor = n;

        } while(n <= 0 || n > presu_base);
        do
        {
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
                (*jug)[i].nota = n;

        } while(n < 0 || n > 10);

        printf("\n >---------------<\n  JUGADOR A%cADIDO\n >---------------<\n", 165);
        system("pause");
        n = 0;
        do
        {
            printf("\n Desea a%cadir el jugador a un equipo?\n 1.-Si\n 2.-No\n\n Seleccion: ", 164);
            scanf("%d", &n);
            fflush(stdin);
            switch(n)
            {
            case 1:
                do
                {
                    printf("\n Introduzca:\n 1.-Identificador de equipo\n 2.-Nombre de equipo\n\n 3.-Volver\n\n Seleccion: ");
                    scanf("%d", &n);
                    fflush(stdin);

                    switch(n)
                    {
                    case 1:
                        printf("\n Introduzca identificador: ");
                        gets(s);
                        fflush(stdin);
                        strtok(s, "\n");
                        id = toint(s);
                        break;
                    case 2:
                        printf("\n Introduzca nombre equipo al que pertenecera el jugador: ");
                        fgets(s, 21, stdin);
                        fflush(stdin);
                        strtok(s, "\n");

                        id = 0;
                        while(id < n_eq && strcmp(s, (*eq)[id].nombreEquipo) != 0)
                            id++;
                        break;
                    case 3:
                        break;
                    default:
                        printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                    }
                } while(n < 1 || n > 3);
                if(n != 3)
                {
                    if(id >= n_eq || id < 0 || strcmp((*eq)[id].nombreEquipo, "\0") == 0)
                        printf("\n\n==============================\n ERROR - EQUIPO NO ENCONTRADO\n==============================\n");
                    else
                    {
                        tostring(id, (*jug)[i].id_equipo);
                        printf("\n >-------<\n  A%cADIDO\n >-------<\n", 165);
                    }
                    system("pause");
                }
                n = 1;
                break;
            case 2:
                (*jug)[i].id_equipo[0] = '\0';
                break;
            default:
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
            }
        } while(n != 1 && n != 2);
    }
}

//Cabecera: void anadir_us(char c, int* n_us, usuario* us)
//Precondición: c es el indicador del origen de la llamada (gestión de usuarios o registro de usuarios). n_us es el tamaño del vector de
//              registros us, correspondientes a los usuarios.
//Postcondición: Permite añadir un usuario.

void anadir_us(char c, int* n_us, usuario** us)
{
    int i = 0, n, error = 0;

    while(i < *n_us && (*us)[i].idUser[0] != '\0')
        i++;
    if(i == *n_us)
    {
        if(((*us) = (usuario*)realloc((*us),(++(*n_us))*sizeof(usuario))) == NULL)
        {
            printf("\n\n\tERROR DE  RESERVA DE MEMORIA PARA JUGADORES");
            error = 1;
        }
    }
    if(error == 0)
    {

        (*us)[i].idUser[0] = '\0';
        (*us)[i].nombre[0] = '\0';
        (*us)[i].permisos[0] = '\0';
        (*us)[i].usuario[0] = '\0';
        (*us)[i].password[0] = '\0';

        tostring(i, (*us)[i].idUser);
        if(c == 'u')
            printf("\n id: %s\n", (*us)[i].idUser);
        do
        {
            printf("\n Introduzca nombre:\t");
            fgets((*us)[i].nombre, 21, stdin);
            fflush(stdin);
            strtok((*us)[i].nombre, "\n");

            if(textest((*us)[i].nombre) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
            }

        } while(textest((*us)[i].nombre) == 1);
        if(c == 'u')            //Llamada desde menú de gestión de usuarios
        {
            do
            {
                printf("\n Introduzca nuevos permisos:\n 1.-Administrador\n 2.-Cronista\n 3.-Participante\n\n Seleccion: ");
                scanf("%d", &n);
                fflush(stdin);

                if(n == 1)
                    strcpy((*us)[i].permisos, "Administrador");
                else if(n == 2)
                    strcpy((*us)[i].permisos, "Cronista");
                else if(n == 3)
                    strcpy((*us)[i].permisos, "Participante");
            } while(n < 1 && n > 3);
        } else if(c == 'r')     //Llamada desde menú de registro de usuarios
            strcpy((*us)[i].permisos, "Participante");
        strtok((*us)[i].permisos, "\n");
        do
        {
            printf("\n Introduzca nombre usuario:\t");
            fgets((*us)[i].usuario, 6, stdin);
            fflush(stdin);
            strtok((*us)[i].usuario, "\n");

            if(textest((*us)[i].usuario) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA\n");
            }

        } while(textest((*us)[i].usuario) == 1);
        do
        {
            printf("\n Introduzca contrase%ca:\t", 164);
            fgets((*us)[i].password, 9, stdin);
            fflush(stdin);
            strtok((*us)[i].password, "\n");

            if(intest((*us)[i].password) == 1)
            {
                printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
                printf("\n INICIE EL NOMBRE POR UNA LETRA O UN NUMERO\n");
            }

        } while(intest((*us)[i].password) == 1);

        printf("\n >---------------<\n  USUARIO A%cADIDO\n >---------------<\n", 165);
    }
    system("pause");
}

//-------------
//    OTRAS
//-------------

//Cabecera: void gettot(char* s, int* n, config* con)
//Precondición: s es la cadena a comparar, n es la variable donde se devolverá el resultado (para la primera vez que sea llamada,
//              n debe ser el tamaño del vector de registros con), y con el vector de registro donde se buscará la coincidencía
//              ente s y uno de sus campos.
//Postcondición: Calcula el número total de registros en un vector de ellos.

void gettot(char* s, int* n, config** con)
{
    static int n0 = 1, tam;

    if(n0 == 0)
    {
        *n = 0;
        for(int i = 0; i < tam; i++)
            if(strcmp((*con)[i].campo, s) == 0)
                *n = (*con)[i].value;
    }
    else
    {
        tam = *n;
        n0 = 0;
    }
}

//Cabecera: int textest(char *c)
//Precondición: el vector de caracteres será el objeto a comprobar.
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
//Precondición: el vector de caracteres será el objeto a comprobar.
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
//Precondición: el vector de caracteres será el objeto a convertir.
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

//Cabecera: int tostring(int n, char *c)
//Precondición: el valor a convertir es el entero, el vector es donde se devolverá el resultado.
//Postcondición: pasa caracteres a enteros.

void tostring(int n, char* c)
{
    char nat[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    int n0 = n, n1, k = 0;
    while(n0 > 0 || (n0 == 0 && k < 1))
    {
        n0 /= 10;
        k++;
    }
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
//Precondición: n1 y n2 deben estar inicializados. n1 corresponde a la base y n2 a la potencia
//Postcondición: devuelve la potencia de n1 elevada a n2

int pot(int n1, int n2)
{
    int res = 1;

    for(int i = 0; i < n2; i++)
        res *= n1;
    return(res);
}
