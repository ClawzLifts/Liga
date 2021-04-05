#include "participante.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LIGA_LOAD_H
#define LIGA_LOAD_H

void init();
void structLoad(char*);
void stringSplit(char*, char*[]);

futbolista createStructJugadores(char*[]);
usuario createStructUsuarios(char*[]);
config createStructConfig(char*[]);
futPlantilla createStructFutP(char*[]);
equipo createStructEquipos(char*[]);


futbolista  arrayFutbolistas[99];

equipo arrayEquipos[20];
usuario arrayUsuarios[10];
config arrayConfig[20];
futPlantilla arrayFutP[330];

#endif //LIGA_LOAD_H
