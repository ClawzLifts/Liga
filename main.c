//
// Created by Clawz on 06/04/2021.
//

#include "loader.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    config *arrayConfig = (config*)malloc(50* sizeof(config));
    usuario *arrayUsuario = (usuario*)malloc(10* sizeof(usuario));
    futbolista *arrayFutbolista = (futbolista*)malloc(50* sizeof(futbolista));
    equipo *arrayEquipo = (equipo*)malloc(50* sizeof(equipo));
    futPlantilla *arrayFutP = (futPlantilla*)malloc(50*sizeof(futPlantilla));

    int nConfig, nUsuario, nFutbolista, nEquipo, nFutP;



    loadConfig(&arrayConfig, &nConfig);
    loadUsuario(&arrayUsuario, &nUsuario);
    loadFutbolistas(&arrayFutbolista, &nFutbolista);
    loadEquipos(&arrayEquipo, &nEquipo);
    loadFutPlantillas(&arrayFutP, &nFutP);


    return 0;
}

