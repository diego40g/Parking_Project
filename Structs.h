#pragma once
struct Node {
	char horaEntrada[11];
	char fechaEntrada[35];
	char horaSalida[11];
	char fechaSalida[35];
	long int numeroCedula;
	char modeloAuto[10];
	float tarifaPagar;
	char nombrePropietario[15];
	char placaAuto[10];
	struct Node* siguienteDireccion;
	struct Node* anteriorDireccion;
};
struct ParkingList {
	char datos[75];
};
typedef struct ParkingList CarsInside;
typedef struct Node* DoubleList;
struct LicensePlates {
	char letrasPlaca[3];
	char numerosPlaca[4];
};
typedef struct LicensePlates CarsLicense;

void insertFirstData(DoubleList&);
void insertLastPosition(DoubleList&);
void insertFirstPosition(DoubleList&);
void insertBetween(DoubleList&);
void printList(DoubleList);
void readList(DoubleList&, int);
int exitParking(DoubleList);
void fee(DoubleList);