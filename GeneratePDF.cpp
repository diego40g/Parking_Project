#include "GeneratePDF.h";

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
		ShowInformation(TEXT("Generaci�n cancelada"));

	ShowInformation(TEXT("La generaci�n se realizo correctamente."));
}