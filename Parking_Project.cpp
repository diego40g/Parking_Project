#include "RequiredPrograms.h";

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	cout<<menu();

	
	carrito();

	char QR[50] = "";
	strcpy_s(QR, "Nombre estudiante\n");
	strcat_s(QR, "Estudiante\n");
	strcat_s(QR, "ISTPET\n");
	strcat_s(QR, "27/07/2023\n");
	generarQr(QR);

	Nodo* aux = new Nodo();
	printf("\nINGRESE NOMBRE DEL PROPIETARIO:");
	letras(aux->nombrePropietario);

    return 0;
}

