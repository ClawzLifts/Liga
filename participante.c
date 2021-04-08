#include "participante.h"
#include "estructuras.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define WELCOME "¡Bienvenido, participante! ¿Que operacion desea realizar?\n"
#define OPCIONES1 "1 -Crear plantilla\n2 -Configurar plantillas\n3 -Listar plantillas\n4 -Eliminar plantilla\n 5 -Ranking\n6 -Salir"

int loadPlantillas(char*, plantilla**,  plantilla**, const int*);
void listaPlantilla(int* , plantilla** );
void menuConfigurar();




void menuParticipante(char *userID, char *userName, config **config, futbolista **futbolistas, equipo **equipos,
                      plantilla **plantillas, futPlantilla **futPlantillas, int* nPlant, int* nFut, int* nEquipo, int* nFutP) {

    int input;
    int nPlantUser;
    plantilla*  userPlantillas[3];

    nPlantUser = loadPlantillas(userID, plantillas, userPlantillas, nPlant);

    puts(WELCOME);

    while (input != 6) {

        puts(OPCIONES1);
        scanf("%d", &input);

        switch (input) {

            case 1: {

                if (nPlantUser < 3) {

                    nuevaPlantilla();

                } else puts("Ha alcanzado el número maximo de plantillas. Elimine una antes de continuar\n");
            }
            break;

            case 2:{

                if (nPlantUser != 0){
                    menuConfigurar();
                }
                else
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
            }
            break;

            case 3: {

                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    listaPlantilla(nPlantUser, userPlantillas);
                }

            }
            break;

            case 4:{

                if (nPlantUser == 0) {
                    puts("No posee ninguna plantilla, por favor, cree una.\n");
                }
                else {
                    listaPlantilla(nPlantUser, userPlantillas);
                    eliminarPlantilla();
                }
            }

            break;

            case 5:{

                ranking();

            }
            break;

        }
    }
}

void menuConfigurar(){


}







int loadPlantillas(char* userID, plantilla** arrayPlantilla, plantilla** userArray, const int* nPlant){

    int count = 0;
    int countUser = 0;

    while(count <= (*nPlant)){

        if(!strcmp((*arrayPlantilla)[count].idUsuario, userID)){
            userArray[countUser] = (*arrayPlantilla)[count];
            countUser++;
            count++;
        }
        else
            count++;
    }
    return countUser;
}

void listaPlantilla(int *nPlantUser, plantilla** userPlantillas) {

    for (int i = 0; i < nPlantUser; ++i) {

        puts("Sus plantillas son:\n");
        printf("%s - %s - Puntuacion: %d\n", (*userPlantillas)[i].idPlantilla, (*userPlantillas[i]).nombre, (*userPlantillas)[i].puntuacion);
    }

