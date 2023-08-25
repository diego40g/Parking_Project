#include "Validations.h";

void letras(char* val) {
	int c, i = 0;
	i = 0;
	while ((c = _getch()) != 13) {
		if ((c >= 65 && c <= 90) || c == 32) {
			*(val + i) = c;
			printf("%c", c);
			i++;
		}
		*(val + i) = '\0';
	}
	return;
}
void numeros(char* val) {
	int c, i = 0;
	i = 0;
	while ((c = _getch()) != 13) {
		if ((c >= 48 && c <= 57)) {

			*(val + i) = c;
			printf("%c", c);
			i++;
		}
		*(val + i) = '\0';
	}
}
void flotantes(char* val) {
	int c, i = 0;
	i = 0;
	while ((c = _getch()) != 13) {
		if ((c >= 48 && c <= 57) || c == 46) {

			*(val + i) = c;
			printf("%c", c);
			i++;
		}
		*(val + i) = '\0';
	}
}
char* cardId() {
	int cont = 0;
	char* ced = (char*)malloc(10 * sizeof(char));
	do {
		system("cls");
		cont = 0;
		cout << "Ingrese su cedula: " << endl;
		int c;
		while ((c = _getch()) != 13) {
			if ((c >= 48 && c <= 57)) {
				*(ced + cont) = c;
				cout << char(c);
				cont++;
			}
		}
	} while (cont > 10 || cont <= 9);
	return ced;
}
