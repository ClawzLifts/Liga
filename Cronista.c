#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cronista.h"

void valorar_equipos();

void cronista() {
    int n;
    do
    {
        printf(" MENU CRONISTA\n"
               " 1.-Listar equipos\n"
               " 2.-Valorar equipos\n"
               " 3.-Salir del programa\n");

        do {
            scanf("%i",&n);
        }
        while(n<1 && n>3);

        switch(n) {
        case 1:
            listar_equipos();
            break;
        case 2:
            valorar_equipos();
            break;
        case 3:
            break;
        }
    } while(n != 3);
}

void listar_equipos()
{
}

void lista_jugadores()
{
}

void valorar_equipos()
{
}
