#include <iostream>
#include <windows.h>
#include <cstdio>

#include "Time.h"

using namespace std;

void Color(int text, int bg)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((bg<<4) | text));
}


void gotoxy(int x, int y)
{
    COORD scrn;
    HANDLE hOutPut = GetStdHandle(STD_OUTPUT_HANDLE);
    scrn.X = x;
    scrn.Y = y;
    SetConsoleCursorPosition(hOutPut, scrn);
}

int main()
{
    Color(5, 3);
    gotoxy(5, 5);

    printf("hello");

    Color(15, 0);

    return 0;
}
