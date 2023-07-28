# ifndef REQUIREDLIBRARIES_H
# define REQUIREDLIBRARIES_H

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h> 
#include <string.h>
#include <string>
#include <MMsystem.h>
#include <ctype.h>
#include <fstream>
#include <iomanip>
#include <SDKDDKVer.h>
#include <tchar.h>
#define BG_BLACK_WHITE_TEXT 07
#define BG_GRAY_BLACK_TEXT 128
#define TOTAL_OPTIONS_MENU 9
#define HELP_OPTION 6
#define PRESS_MOVE_DOWN 80
#define PRESS_MOVE_UP 72
#define PRESS_ENTER 13
#define PRESS_ESC 27

using namespace std;
typedef std::basic_ifstream<TCHAR> tifstream;
typedef std::basic_string<TCHAR> tstring;
# define MAX 20

void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}
void color(int x) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
}
void Outtextxy(HDC hdc, int x, int y, tstring Msg) {
	TextOut(hdc, x, y, Msg.c_str(), static_cast<int>(Msg.length()));
}
void ShowError(tstring strMsg) {
	MessageBox(NULL, strMsg.c_str(), TEXT("Imprimir"), MB_ICONERROR);
	exit(1);
}
void ShowInformation(tstring strText) {
	MessageBox(NULL, strText.c_str(), TEXT("Imprimir"), MB_ICONINFORMATION);
}
void PrintFile(tifstream& f) {
	PRINTDLG pd;
	DOCINFO di;
	tstring strLine;
	int y = 300;

	memset(&pd, 0, sizeof(PRINTDLG));
	memset(&di, 0, sizeof(DOCINFO));

	di.cbSize = sizeof(DOCINFO);
	di.lpszDocName = TEXT("Generando");

	pd.lStructSize = sizeof(PRINTDLG);
	pd.Flags = PD_PAGENUMS | PD_RETURNDC;
	pd.nFromPage = 1;
	pd.nToPage = 1;
	pd.nMinPage = 1;
	pd.nMaxPage = 0xFFFF;
	if (f.fail()) {
		ShowError(TEXT("Error el archivo no se pudo abrir para lectura."));
	}


	if (PrintDlg(&pd)) {
		if (pd.hDC) {
			if (StartDoc(pd.hDC, &di) != SP_ERROR) {
				cout << "Generando...\nEspere un momento." << endl;
				StartPage(pd.hDC);
				while (!f.eof()) {
					std::getline(f, strLine);
					Outtextxy(pd.hDC, 500, y, strLine.c_str());
					y += 100;
				}
				EndPage(pd.hDC);
				EndDoc(pd.hDC);
			}
			else
				ShowError(TEXT("Error: No se pudo comenzar a generar."));

		}
		else
			ShowError(TEXT("Error: No se pudo crear el contexto de dispositivo."));

	}
	else
		ShowInformation(TEXT("Generación cancelada"));

	ShowInformation(TEXT("La generación se realizo correctamente."));
}

int menu() {
	char c;
	const char* fr[50] = { "INGRESAR PRIMER AUTO AL PARQUEADERO ",
						   "INGRESAR AUTO AL INICIO DEL PARQUEADERO ",
						   "INGRESAR AUTO AL FINAL DEL PARQUEADERO ",
						   "INGRESAR AUTO ENTRE PARQUEADEROS ",
						   "GUARDAR Y MOSTRAR LISTA DE AUTOS EN EL PARQUEADERO",
						   "AYUDA DEL PROGRAMA",
						   "IMAGEN DEL GRUPO",
						   "SALIR DEL PARQUEADERO",
						   "SALIR DEL SISTEMA ",
	};
	system("cls");
	gotoxy(40, 1);
	cout << "MENÚ";
	int y = 2, n;
	for (int i = 1; i <= TOTAL_OPTIONS_MENU; i++) {
		if (i == 1) {
			color(BG_GRAY_BLACK_TEXT);
			gotoxy(20, y + i);
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
		}
		if (c == PRESS_MOVE_DOWN) {
			if (y == TOTAL_OPTIONS_MENU + 1) {
				y = 2;
			}
			else {
				y++;
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
#endif
