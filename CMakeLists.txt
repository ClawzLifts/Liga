cmake_minimum_required(VERSION 3.17)
project(Liga)

set(CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")



include_directories(.)

add_executable(Liga
        DATA/Futbolistas.txt
        DATA/Configuracion.txt
        DATA/Equipos.txt
        DATA/Plantillas.txt
        DATA/Futbolistas.txt

        participante.c
        Headers/participante.h
        main.c
        loader.c
        Headers/loader.h
        Admin.c
        Headers/Admin.h
        Cronista.c
        Headers/Cronista.h
        Login_res.c
        Headers/Login_res.h
        )
