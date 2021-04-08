//
// Created by Clawz on 06/04/2021.
//

#ifndef LIGA_LOADER_H
#define LIGA_LOADER_H

#include "estructuras.h"

#ifndef LIGA_LOAD_H
#define LIGA_LOAD_H

void loadConfig(config**, int*);
void loadFutbolistas(futbolista**, int*);
void loadEquipos(equipo**, int*);
void loadUsuario(usuario**, int*);
void loadFutPlantillas(futPlantilla**, int*);
void loadPlantillas(plantilla**, int*);

void stringSplit(char* , char*[]);


#endif //LIGA_LOAD_H


#endif //LIGA_LOADER_H
