#include "RequiredPrograms.h";

#define _CRT_SECURE_NO_WARNINGS

int main()
{
	//playSong("fondo.wav");

	DoubleList list = NULL;
	Node* auxList = new Node();
	int cont;
	cont = countLines();
	readList(list,cont);
	int opcionDelMenu, comp;
	inicio:
	opcionDelMenu = menu();
	switch (opcionDelMenu) {
		case 1: {
			system("cls");
			carrito();
			system("pause");
			goto inicio;
			break;
		}
		case 2: {
			system("cls");
			char QR[50] = "";
			strcpy_s(QR, "Nombre estudiante\n");
			strcat_s(QR, "Estudiante\n");
			strcat_s(QR, "ISTPET\n");
			strcat_s(QR, "27/07/2023\n");
			generarQr(QR);
			system("pause");
			goto inicio;
			break;
		}
		case 3: {
			system("cls");
			insertLastPosition(list);
			system("pause");
			goto inicio;
			break;
		}
		case 4: {
			system("cls");
			insertBetween(list);
			system("pause");
			goto inicio;
			break;
		}
		case 5: {
			system("cls");
			printList(list);
			system("pause");
			goto inicio;
			break;
		}
		case 6: {
			openFile("ayuda.chm");
			goto inicio;
			break;
		}
		case 7: {
			openFile("FotoGrupal.exe");
			goto inicio;
			break;
		}
		case 8: {
			comp = 0;
			system("cls");
			comp = exitParking(list);
			if (comp == 0) {
				printf("\nNO SE HA INGRESADO UN VEHICULO CON ESAS ESPECIFICACIONES!!!\n");
			}
			if (comp == 1) {
				list = NULL;
			}
			if (comp == 2) {
				auxList = list;
				list = list->siguienteDireccion;
				auxList->siguienteDireccion = auxList->anteriorDireccion = NULL;
				auxList = NULL;
				list->anteriorDireccion = NULL;
			}
			if (comp == 4) {
				while (list->siguienteDireccion != NULL) {
					list = list->siguienteDireccion;
				}
				list = list->anteriorDireccion;
				list->siguienteDireccion = NULL;
				comp = 0;
				while (list->anteriorDireccion != NULL) {
					list = list->anteriorDireccion;
				}
			}
			system("pause");
			goto inicio;
			break;
		}
		case 9: {
			return 0;
			break;
		}
	}
	/*cout << menu();

	diego.paz
	Us4bnh48-Rd!iX!
	
	carrito();

	char QR[50] = "";
	strcpy_s(QR, "Nombre estudiante\n");
	strcat_s(QR, "Estudiante\n");
	strcat_s(QR, "ISTPET\n");
	strcat_s(QR, "27/07/2023\n");
	generarQr(QR);

	Node* aux = new Node();
	printf("\nINGRESE NOMBRE DEL PROPIETARIO:");
	letras(aux->nombrePropietario);*/

    return 0;
}

