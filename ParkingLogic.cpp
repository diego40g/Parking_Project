#include "RequiredPrograms.h";

void insertFirstData(DoubleList &list) {
	char* QR = (char*)malloc(50 * sizeof(char));
	char* cad1 = (char*)malloc(10 * sizeof(char));
	FILE* ticket;
	Node* aux = new Node();
	char* modeloAuto = (char*)malloc(10 * sizeof(char));
	char* nombrePropietario = (char*)malloc(15 * sizeof(char));
	char* placaAuto = (char*)malloc(10 * sizeof(char));
	char* letrasPlaca = (char*)malloc(3 * sizeof(char));
	char* numerosPlaca = (char*)malloc(4 * sizeof(char));
	if (list == NULL) {
		aux->numeroCedula = atoi(cardId());
		printf("\nINGRESE NOMBRE DEL PROPIETARIO:");
		letras(aux->nombrePropietario);
		printf("\nINGRESE PLACA");
		do {
			printf("\nINGRESE LETRAS DE LA PLACA:");
			letras(letrasPlaca);
		} while (strlen(letrasPlaca) < 3 || strlen(letrasPlaca) > 3);
		strcpy_s(aux->placaAuto, letrasPlaca);
		strcat_s(aux->placaAuto, "-");
		do {
			printf("\nINGRESE NUMEROS DE LA PLACA:");
			printf("\nSI SU PLACA TIENE TRES NUMEROS ANTEPONGA EL NUMERO 0\n");
			numeros(numerosPlaca);
		} while (strlen(numerosPlaca) < 4 || strlen(numerosPlaca) > 4);
		strcat_s(aux->placaAuto, numerosPlaca);
		printf("\nINGRESE MODELO DEL AUTO: ");
		letras(aux->modeloAuto);
		GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, NULL, NULL, aux->fechaEntrada, 35);
		GetTimeFormat(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, NULL, NULL, aux->horaEntrada, 11);
		aux->anteriorDireccion = aux->siguienteDireccion = NULL;
		list = aux;
		carrito();
		system("cls");
		/*fopen_s(&ticket, "TICKET DE ENTRADA.txt", "w");
		printf("*****************************************************");
		gotoxy(18, 1);
		printf("TICKET DE ENTRADA");
		gotoxy(0, 1);
		printf("*");
		gotoxy(52, 1);
		printf("*");
		gotoxy(0, 2);
		printf("* NOMBRE CLIENTE: %s", aux->nombrePropietario);
		gotoxy(52, 2);
		printf("*");
		gotoxy(0, 3);
		printf("* CEDULA DEL CLIENTE: %d", aux->numeroCedula);
		gotoxy(52, 3);
		printf("*");
		gotoxy(0, 4);
		printf("* FECHA DE ENTRADA: %s", aux->fechaEntrada);
		gotoxy(52, 4);
		printf("*");
		gotoxy(0, 5);
		printf("* HORA DE ENTRADA: %s", aux->horaEntrada);
		gotoxy(52, 5);
		printf("*");
		gotoxy(0, 6);
		printf("* PLACA DEL VEHICULO: %s", aux->placaAuto);
		gotoxy(52, 6);
		printf("*");
		gotoxy(0, 7);
		printf("* VEHICULO: %s", aux->modeloAuto);
		gotoxy(52, 7);
		printf("*");
		gotoxy(18, 8);
		printf("HORA O FRACCION");
		gotoxy(0, 8);
		printf("*");
		gotoxy(52, 8);
		printf("*");
		gotoxy(0, 9);
		printf("*****************************************************\n");
		fprintf(ticket, "*********************************************************");
		fprintf(ticket, "\n*\t\tTICKET DE ENTRADA\t\t\t*");
		fprintf(ticket, "\n* NOMBRE CLIENTE: %s\t\t\t*", aux->nombrePropietario);
		fprintf(ticket, "\n* CEDULA DEL CLIENTE: %d\t\t\t*", aux->numeroCedula);
		fprintf(ticket, "\n* FECHA DE ENTRADA: %s\t*", aux->fechaEntrada);
		fprintf(ticket, "\n* HORA DE ENTRADA: %s\t\t\t\t*", aux->horaEntrada);
		fprintf(ticket, "\n* PLACA DEL VEHICULO: %s\t\t\t\t*", aux->placaAuto);
		fprintf(ticket, "\n* VEHICULO: %s\t\t\t\t\t*", aux->modeloAuto);
		fprintf(ticket, "\n*\t\tHORA O FRACCION\t\t\t\t*");
		fprintf(ticket, "\n*********************************************************");
		fclose(ticket);
		
		strcpy_s(QR, aux->nombrePropietario);
		strcat_s(QR, "\n");
		_itoa(aux->numeroCedula, cad1, 10);
		strcat_s(QR, cad1);
		strcat_s(QR, "\n");
		strcat_s(QR, aux->fechaEntrada);
		strcat_s(QR, "\n");
		strcat_s(QR, aux->horaEntrada);
		strcat_s(QR, "\n");
		strcat_s(QR, aux->placaAuto);
		strcat_s(QR, "\n");
		strcat_s(QR, aux->modeloAuto);
		strcat_s(QR, "\nHORA O FRACCION");
		generarQr(QR);*/
	}else {
		printf("\nEL PRIMER VEHICULO YA ESTA EN EL PARQUEADERO\n");
	}
	return;
}
void insertLastPosition(DoubleList& list) {
	char* QR = (char*)malloc(50 * sizeof(char));
	char* cad1 = (char*)malloc(10 * sizeof(char));
	FILE* ticket;
	LicensePlates licensePlates;
	Node* auxList = list, * aux = new Node();
	char* letrasPlaca = (char*)malloc(3 * sizeof(char));
	char* numeroPlaca = (char*)malloc(4 * sizeof(char));
	char* fecha = (char*)malloc(50 * sizeof(char));
	char* hora = (char*)malloc(30 * sizeof(char));;
	if (list != NULL) {
		aux->numeroCedula = atoi(cardId());
		printf("\nINGRESE NOMBRE DEL PROPIETARIO:");
		letras(aux->nombrePropietario);
		printf("\nINGRESE PLACA");
		do {
			printf("\nINGRESE LETRAS DE LA PLACA:");
			letras(letrasPlaca);
		} while (strlen(letrasPlaca) < 3 || strlen(letrasPlaca) > 3);
		strcpy_s(aux->placaAuto, letrasPlaca);
		strcat_s(aux->placaAuto, "-");
		do {
			printf("\nINGRESE NUMEROS DE LA PLACA:");
			printf("\nSI SU PLACA TIENE TRES NUMEROS ANTEPONGA EL NUMERO 0\n");
			numeros(numeroPlaca);
		} while (strlen(numeroPlaca) < 4 || strlen(numeroPlaca) > 4);
		strcat_s(aux->placaAuto, numeroPlaca);
		if (list->siguienteDireccion == NULL) {
			if (strcmp(list->placaAuto, aux->placaAuto) == 0) {
				printf("\nEL AUTO NO PUEDE INGRESAR PUES YA ESTA DENTRO DEL PARQUEADERO");
				return;
			}
		}
		if (list->siguienteDireccion != NULL) {
			while (list->siguienteDireccion != NULL) {
				if (strcmp(list->placaAuto, aux->placaAuto) == 0) {
					printf("\nEL AUTO NO PUEDE INGRESAR PUES YA ESTA DENTRO DEL PARQUEADERO");
					while (list->anteriorDireccion != NULL) {
						list = list->anteriorDireccion;
					}
					return;
				}
				list = list->siguienteDireccion;
				if (list->siguienteDireccion == NULL) {
					if (strcmp(list->placaAuto, aux->placaAuto) == 0) {
						printf("\nEL AUTO NO PUEDE INGRESAR PUES YA ESTA DENTRO DEL PARQUEADERO");
						while (list->anteriorDireccion != NULL) {
							list = list->anteriorDireccion;
						}
						return;
					}
				}
			}
		}
		while (list->anteriorDireccion != NULL) {
			list = list->anteriorDireccion;
		}
		printf("\nINGRESE MODELO DEL AUTO: ");
		letras(aux->modeloAuto);
		GetDateFormat(LOCALE_USER_DEFAULT, DATE_LONGDATE, NULL, NULL, aux->fechaEntrada, 50);
		GetTimeFormat(LOCALE_USER_DEFAULT, TIME_FORCE24HOURFORMAT, NULL, NULL, aux->horaEntrada, 30);
		while (auxList->siguienteDireccion != NULL) {
			auxList = auxList->siguienteDireccion;
		}
		aux->siguienteDireccion = auxList->siguienteDireccion;
		auxList->siguienteDireccion = aux;
		aux->anteriorDireccion = auxList;
		carrito();
	}
	else {
		printf("\nDEBE INGRESAR EL PRIMER ELEMENTO!!\n");
	}
	return;
}
void insertFirstPosition(DoubleList& list) {

}
void insertBetween(DoubleList& list) {

}
void printList(DoubleList list) {
	ofstream datos(FILE_NAME);
	if (list == NULL) {
		printf("No hay elementos en la lista!\n\n");
		datos << "No hay elementos en la lista!\n\n" << endl;
	}
	else {
		while (list != NULL) {
			printf("%s", list->nombrePropietario);
			datos << list->nombrePropietario << endl;
			printf("\n%d", list->numeroCedula);
			datos << "\n" << list->numeroCedula << endl;
			printf("\n%s", list->fechaEntrada);
			datos << "\n" << list->fechaEntrada << endl;
			printf("\n%s", list->horaEntrada);
			datos << "\n" << list->horaEntrada << endl;
			printf("\n%s", list->placaAuto);
			datos << "\n" << list->placaAuto << endl;
			printf("\n%s", list->modeloAuto);
			datos << "\n" << list->modeloAuto << endl;
			printf("\n\n");
			datos << "\n\n" << endl;
			list = list->siguienteDireccion;
		}
		datos.close();
		system("pause");

		int imp;
		system("cls");
		imp = savePDF();
		if (imp == 1)
		{
			ofstream LeerDatos;
			LeerDatos.open(FILE_NAME, ios::out | ios::app);
			tifstream in(TEXT(FILE_NAME));
			PrintFile(in);
			openFile(PATH_PDF);
		}
		system("pause");
		_getch;
	}
	return;
}
void readList(DoubleList& list, int cont) {
	Node* auxList = new Node();
	CarsInside cars[50];
	FILE* parking;
	int count, index=0;
	char readLine[100];	

	if (fopen_s(&parking, FILE_NAME, "r") == 0){
		int i= 0;
		while (fgets(readLine, sizeof(readLine), parking) != nullptr) {
			fflush(stdin);
			cout << readLine << endl;
			strcpy_s(cars[i].datos, readLine);
			i++;
		}
		fclose(parking);
		while (index <= cont - 2) {
			if (index <= 14 && list == NULL) {
				strcpy_s(auxList->nombrePropietario, cars[index].datos);
				index += 2;
				auxList->numeroCedula = atoi(cars[index].datos);
				index += 2;
				strcpy_s(auxList->fechaEntrada, cars[index].datos);
				index += 2;
				strcpy_s(auxList->horaEntrada, cars[index].datos);
				index += 2;
				strcpy_s(auxList->placaAuto, cars[index].datos);
				index += 2;
				strcpy_s(auxList->modeloAuto, cars[index].datos);
				auxList->anteriorDireccion = auxList->siguienteDireccion = NULL;
				list = auxList;
				index += 4;
			}
			else {
				Node* newList = new Node();
				strcpy_s(newList->nombrePropietario, cars[index].datos);
				index += 2;
				newList->numeroCedula = atoi(cars[index].datos);
				index += 2;
				strcpy_s(newList->fechaEntrada, cars[index].datos);
				index += 2;
				strcpy_s(newList->horaEntrada, cars[index].datos);
				index += 2;
				strcpy_s(newList->placaAuto, cars[index].datos);
				index += 2;
				strcpy_s(newList->modeloAuto, cars[index].datos);
				newList->siguienteDireccion = list;
				newList->anteriorDireccion = list->anteriorDireccion;
				list->anteriorDireccion = newList;
				list = newList;
				index += 4;
				cout << "Else";
			}

			/*Agregar a auxList */
		}
		return;
	}else {
		cerr << "Error al abrir el archivo plano" << endl;
	}
}
int exitParking(DoubleList list) {
	return 0;
}
void fee(DoubleList list) {

}