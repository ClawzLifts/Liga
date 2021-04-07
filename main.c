//
// Created by Clawz on 06/04/2021.
//

#include "loader.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

 futbolista *arrayFutbolista = (futbolista*)malloc(50* sizeof(futbolista));

    if (arrayFutbolista != NULL){

        int n;
        loadFutbolistas(&arrayFutbolista,&n);

    }
    else
        exit(1);
    return 0;
}

