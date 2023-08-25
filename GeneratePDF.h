#include"RequiredLibraries.h"

# ifndef GeneratePDF_H
# define GeneratePDF_H

void Outtextxy(HDC hdc, int x, int y, tstring Msg);
void ShowError(tstring strMsg);
void ShowInformation(tstring strText);
void PrintFile(tifstream& f);
# endif