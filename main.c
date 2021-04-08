//
// Created by Clawz on 06/04/2021.
//

#include "loader.h"
#include "participante.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    config *arrayConfig = (config*)malloc(10* sizeof(config));
    usuario *arrayUsuario = (usuario*)malloc(10* sizeof(usuario));
    futbolista *arrayFutbolista = (futbolista*)malloc(50* sizeof(futbolista));
    equipo *arrayEquipo = (equipo*)malloc(50* sizeof(equipo));
    futPlantilla *arrayFutP = (futPlantilla*)malloc(50*sizeof(futPlantilla));
    plantilla *arrayPlantilla = (plantilla*)malloc(30* sizeof(plantilla));

    int nConfig, nUsuario, nFutbolista, nEquipo, nFutP, nPlantilla;



    loadConfig(&arrayConfig, &nConfig);
    loadUsuario(&arrayUsuario, &nUsuario);
    loadFutbolistas(&arrayFutbolista, &nFutbolista);
    loadEquipos(&arrayEquipo, &nEquipo);
    loadFutPlantillas(&arrayFutP, &nFutP);
    loadPlantillas(&arrayPlantilla, &nPlantilla);


    menuParticipante("test", "test", &arrayConfig, &arrayFutbolista, &arrayEquipo, &arrayPlantilla, &arrayFutP,
                     &nPlantilla, &nFutbolista, &nEquipo, &nFutP);




    return 0;
}

