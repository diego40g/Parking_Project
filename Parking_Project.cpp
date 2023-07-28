#include "RequiredLibraries.h";
#include "Header.h";

int main()
{
   // menu();
    char QR[50] = " ";
    strcpy_s(QR, "Natsy");
    strcat_s(QR, "Dias");
    generarQR(QR);

    return 0;
}



