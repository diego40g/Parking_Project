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
