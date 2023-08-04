#include "RequiredPrograms.h"

void imprimirCar(int x)
{
	system("cls");
	color(WHITE_TEXT);
	gotoxy(30, 5);
	cout << "INGRESO AL PARQUEADERO";
	color(BLUE_TEXT);
	gotoxy(x, 10);
	cout << "  //////////////////";
	gotoxy(x, 11);
	cout << " /////////////     //";
	gotoxy(x, 12);
	cout << "//////////////////////////";
	gotoxy(x, 13);
	cout << "/////////////////////////";
	gotoxy(x, 14);
	cout << "   (  )            (  )";
	color(WHITE_TEXT);
}
void carrito()
{
	int x = 2;

	for (int j = 0; j <= 54; j++)
	{
		imprimirCar(x);
		x++;
		if (x == 54)
		{
			x = 0;
		}
		Sleep(50);
	}
	system("cls");
	cout << "TOMAR EL TICK" << endl;
}