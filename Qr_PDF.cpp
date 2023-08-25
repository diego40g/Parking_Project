#include "RequiredPrograms.h"

void printQr(const uint8_t qrcode[]) {
	int size = qrcodegen_getSize(qrcode);
	int border = 4;
	for (int y = -border; y < size + border; y++) {
		for (int x = -border; x < size + border; x++) {
			fputs((qrcodegen_getModule(qrcode, x, y) ? "\333\333" : "  "), stdout);
		}
		fputs("\n", stdout);
	}
}
void generarQr(char* loqueimprime)
{
	char* dato = loqueimprime;
	enum qrcodegen_Ecc errCorLvl = qrcodegen_Ecc_LOW;

	uint8_t qrcode[qrcodegen_BUFFER_LEN_MAX];
	uint8_t tempBuffer[qrcodegen_BUFFER_LEN_MAX];
	bool ok = qrcodegen_encodeText(dato, tempBuffer, qrcode, errCorLvl,
		qrcodegen_VERSION_MIN, qrcodegen_VERSION_MAX, qrcodegen_Mask_AUTO, true);
	if (ok)
		printQr(qrcode);
}

int countLines() {
	FILE* pf;
	int ch, num = 0;
	if (fopen_s(&pf, FILE_NAME, "r") == 0) {
		while ((ch = fgetc(pf)) != EOF) {
			if (ch == '\n') {
				num++;
			}
		}
	}
	else {
		return 0;
	}
	fclose(pf);
	return num;
}
int savePDF() {
	int x;
	int imp;
	printf("\nPresione Enter ");
	for (;; ) {
		x = _getch();
		if (x == 13)
		{
			imp = 1;
			printf("\nGenerando...");
			break;
		}
	}
	return imp;
}
