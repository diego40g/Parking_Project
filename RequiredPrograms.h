#include "RequiredLibraries.h";
#include "GenerateQR.h";
#include "GeneratePDF.h";
//#include "Structs.h";
#include "Validations.h";

#define WHITE_TEXT 7
#define BLUE_TEXT 9
#define BG_BLACK_WHITE_TEXT 07
#define BG_GRAY_BLACK_TEXT 128
#define TOTAL_OPTIONS_MENU 9
#define HELP_OPTION 6
#define PRESS_MOVE_DOWN 80
#define PRESS_MOVE_UP 72
#define PRESS_ENTER 13
#define PRESS_ESC 27
#define PRESS_F1 59

void gotoxy(int x, int y);
void color(int X);

int menu();

void imprimirCar(int x);
void carrito();

void printQr(const uint8_t qrcode[]);
void generarQr(char* loqueimprime);

void Outtextxy(HDC hdc, int x, int y, tstring Msg);
void ShowError(tstring strMsg);
void ShowInformation(tstring strText);
void PrintFile(tifstream& f);

