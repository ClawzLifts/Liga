#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Cronista.h"

#include "Admin.h"
#include "participante.h"
#include "Admin.h"
#include "participante.h"

#include "Login_res.h"


//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DECLARACIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

void loginres(int*, int*, int*, int*, int*, int , equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);
void login(int*, int*, int*, int*, int*, int , equipo**, futbolista**, usuario**, plantilla**, futPlantilla**, config**);

//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#
//      DEFINICIÓN DE FUNCIONES
//#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#=#

//Cabecera: void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipos** eq, jugadores** jug, usuario** us, config** con)
//Precondición: n_eq, n_juf, n_us, n_pl, n_fpl y n_con son los tamaños de sus respectivos vectores de registros. eq, jug, us, pl, fpl y con los
//              vectores de registros.
//Postcondición: Permite acceder a la aplicación. Redirige al menú correspondiente según los permisos del usuario.

void loginres(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us, plantilla** pl, futPlantilla** fpl, config** con)
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
        printf("\n Elija una opcion de acceso:\n\n 1.-Log-in\n 2.-Registrarse\n\n 3.-Salir del programa\n\n Seleccion: ");
        scanf("%d", &n);
        fflush(stdin);

        switch(n)
        {
        case 1:
            login(n_eq, n_jug, n_us, n_pl, n_fpl, n_con, eq, jug, us, pl, fpl, con);
            break;
        case 2:
            anadir_us('r', n_us, us);
            break;
        case 3:
            break;
        default:
            printf("\n\n =-=-=-=-==-=-=-=-=\n  VALOR INCORRECTO\n =-=-=-=-==-=-=-=-=\n");
        }
    } while(n != 3);
    system("cls");
}

//Cabecera: void login(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipos** eq, jugadores** jug, usuario** us, config** con)
//Precondición: n_eq, n_juf, n_us, n_pl, n_fpl y n_con son los tamaños de sus respectivos vectores de registros. eq, jug, us, pl, fpl y con los
//              vectores de registros.
//Postcondición: Permite acceder a la aplicación. Redirige al menú correspondiente según los permisos del usuario.

void login(int* n_eq, int* n_jug, int* n_us, int* n_pl, int* n_fpl, int n_con, equipo** eq, futbolista** jug, usuario** us, plantilla** pl, futPlantilla** fpl, config** con)
{
    int n, i;
    char s[9];

    system("cls");

    printf("\n Introduca nombre de cuenta: ");
    fgets(s, 9, stdin);
    fflush(stdin);
    strtok(s, "\n");

    for(i = 0; i < *n_us && strcmp(s, (*us)[i].usuario) != 0; i++);

    if(i == *n_us)
    {
        printf("\n\n===============================\n ERROR - USUARIO NO ENCONTRADO\n===============================\n");
        system("pause");
    }
    else
    {
        n = 3;
        do
        {
            printf("\n Introduca contrase%ca: ", 164);
            fgets(s, 9, stdin);
            fflush(stdin);
            strtok(s, "\n");

            if(strcmp(s, (*us)[i].password) != 0)
            {
                printf("\n\n=======================\n CONTRASE%cA INCORRECTA\n=======================\n", 165);
                printf("\n\n %d Intentos restantes\n\n", --n);
                system("pause");
            }
            else
            {
                printf("\n\n=====================\n CONTRASE%cA CORRECTA\n=====================\n", 165);
                system("pause");

                if(strcmp((*us)[i].perfil, "Administrador") == 0)
                    m_admin(i, n_eq, n_jug, n_us, n_pl, n_fpl, n_con, eq, jug, us, pl, fpl, con);
                else if(strcmp((*us)[i].perfil, "Cronista") == 0)
                    cronista(n_eq, eq, n_jug, jug);
                else if(strcmp((*us)[i].perfil, "Participante") == 0) {
                    menuParticipante((*us)[i].idUser, (*us)[i].nombre, con, jug, eq, pl, fpl, n_pl, n_jug, n_eq, n_fpl);
                }
                else
                {
                    printf("\n\n=======\n ERROR\n=======\n\n");
                    system("pause");
                }
                n = 0;
            }
        } while(n > 0);
    }
    system("cls");
}

