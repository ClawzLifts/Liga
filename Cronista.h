#ifndef _CRONISTA_H_
#define _CRONISTA_H_

typedef struct{
	char id_equipo[10];
	char nombreEquipo[21];
}equipos;

typedef struct{
	char id_jugador[10];
	char id_equipo[10];
	char nombre[21];
	int valor;
	int nota;
}jugadores;

void cronista();
void listar_equipos();
void lista_jugadores();

#endif
