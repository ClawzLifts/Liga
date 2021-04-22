//
// Created by Clawz on 06/04/2021.
//
#include <stdlib.h>
#include "Headers/Cronista.h"
#include "Headers/Admin.h"
#include "Headers/loader.h"
#include "Headers/participante.h"
#include "Headers/Login_res.h"




int main() {

    config *arrayConfig = (config*) malloc(10* sizeof(config));
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
    loadPlantilla(&arrayPlantilla, &nPlantilla);


    loginres(&nEquipo, &nFutbolista, &nUsuario, &nPlantilla, &nFutP, nConfig, &arrayEquipo, &arrayFutbolista,
             &arrayUsuario, &arrayPlantilla, &arrayFutP, &arrayConfig);

    savePlantillas(&arrayPlantilla,nPlantilla);
    saveFutbolistas(&arrayFutbolista, nFutbolista);
    saveConfig(&arrayConfig, nConfig);
    saveUsuarios(&arrayUsuario, nUsuario);
    saveEquipos(&arrayEquipo, nEquipo);
    saveFutP(&arrayFutP, nFutP);


    free(arrayConfig);
    free(arrayUsuario);
    free(arrayFutbolista);
    free(arrayEquipo);
    free(arrayFutP);
    free(arrayPlantilla);



    return 0;
}

