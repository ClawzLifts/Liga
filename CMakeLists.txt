cmake_minimum_required(VERSION 3.17)
project(Liga)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Liga
        DATA/Futbolistas.txt
        DATA/Configuracion.txt
        DATA/Equipos.txt
        DATA/Plantillas.txt
        DATA/Futbolistas.txt

        participante.c
        participante.h
        main.c
        loader.c
        loader.h
        Admin.c
        Admin.h
        Cronista.c
        Cronista.h
        Login_res.c
        Login_res.h
        )
