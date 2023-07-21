#include "RequiredLibraries.h";

#define BG_BLACK_WHITE_TEXT 07	//Dentro del menú y da color
#define BG_GRAY_BLACK_TEXT 128	//Dentro del menú y da color
#define TOTAL_OPTIONS_MENU 9	//La cantidad de datos
#define HELP_OPTION 6			//Opción 6 del menú
#define PRESS_MOVE_DOWN 80		//Presionar la tecla de abajo
#define PRESS_MOVE_UP	72		//Presionar la tecla de arriba
#define PRESS_ENTER 13			//Ingresar
#define PRESS_ESC 27			//Salir
#define PRESS_F1 59				//Ayuda


void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void color(int X) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), X);
}

//Menú
int menu() {
	char c;
	const char* fr[50] = { "INGRESAR PRIMER AUTO AL PARQUEADERO",
						   "INGRESAR AUTO AL INICIO DEL PARQUEADERO",
						   "INGRESAR AUTO AL FINAL DEL PARQUEADERO",
						   "INGRESAR AUTO ENTRE PARQUEADEROS",
						   "GUARDAR Y MOSTRAR LISTA DE AUTOS EN EL PARQUEADERO",
						   "AYUDA DEL PROGRAMA",
						   "IMAGEN DEL GRUPO",
						   "SALIR DEL PARQUEADERO",
						   "SALIR DEL SISTEMA",};

	system("cls");
	gotoxy(40, 1);
	cout << "MENU";
	int y = 2, n;
	for (int i = 1; i <= TOTAL_OPTIONS_MENU; i++) {
		if (i == 1) {
			color(BG_GRAY_BLACK_TEXT);
			gotoxy(20, y + 1);
			cout << fr[i - 1];
			color(BG_BLACK_WHITE_TEXT);
		}
		else {
			color(BG_BLACK_WHITE_TEXT);
			gotoxy(20, y + i);
			cout << fr[i - 1];
		}
	}
	do {
		c = _getch();
		gotoxy(20, y + 1);
		color(BG_BLACK_WHITE_TEXT);
		for (int i = y; i <= TOTAL_OPTIONS_MENU + 1; i++) {
			gotoxy(20, i + 1);
			cout << fr[i - 2];
		}

		if (c == -32) {
			c = _getch();
			if (c == PRESS_MOVE_UP) {
				if (y == 2) {
					y = TOTAL_OPTIONS_MENU + 1;
				}
				else {
					y--;
				}

			}
			if (c == PRESS_MOVE_DOWN) {
				if (y == TOTAL_OPTIONS_MENU + 1) {
					y = 2;
				}
				else {
					y++;
				}
			}
		}
		if (c == PRESS_ENTER) {
			n = y - 1;
			break;
		}
		if (c == PRESS_ESC) {
			return TOTAL_OPTIONS_MENU;
		}
		if (c == 59) {
			return HELP_OPTION;
		}
		else {
			gotoxy(20, y + 1);
			color(BG_GRAY_BLACK_TEXT);
			cout << fr[y - 2];
		}
	} while (1);
	return n;
}