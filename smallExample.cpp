// smallExample.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

void clrscr()
{
	system("cls");
}
void gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursorCoord;
	cursorCoord.X = x;
	cursorCoord.Y = y;
	SetConsoleCursorPosition(consoleHandle, cursorCoord);
}
void setTextColor(int textColor, int backColor = 0)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int colorAttribute = backColor << 4 | textColor;
	SetConsoleTextAttribute(consoleHandle, colorAttribute);
}
using namespace std;
int main()
{
	char ch; 
	cout << "hello";

	while(true)
	if (_kbhit())
	{
		ch = _getch();
		if (ch == 'n')
		{
			clrscr(); 
			gotoxy(10, 10);
			cout << "hello";
			gotoxy(10, 11);
			setTextColor(78,120);
			cout << "hello";
		}
		if (ch == 'q')
		{
			break;
		}
	}
    return 0;
}

