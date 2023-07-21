#pragma once
struct Nodo {
	char horaEntrada[11];
	char fechaEntrada[35];
	char horaSalida[11];
	char fechaSalida[35];
	long int numeroCedula;
	char modeloAuto[10];
	float tarifaPagar;
	char nombrePropietario[15];
	char placaAuto[10];
	struct Nodo* siguienteDireccion;
	struct Nodo* anteriorDireccion;
};
struct ListaParqueadero {
	char datos[75];
};
typedef struct ListaParqueadero autosDentro;
typedef struct Nodo* ListaDoble;
struct Placas {
	char letrasPlaca[3];
	char numerosPlaca[4];
};
typedef struct Placas placa;