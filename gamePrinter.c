#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "gamePrinter.h"

#define FR_HEIGHT 14
#define FR_WIDTH 18

HANDLE hand;
int surface[FR_HEIGHT][FR_WIDTH] = {0};

void initGamePrinter() {
    hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);
}


void setCursorVisable(int v)
{
	CONSOLE_CURSOR_INFO cursor_info = {100, v};
	SetConsoleCursorInfo(hand, &cursor_info);
}

void printxy(char *str, int x, int y)
{
	gotoxy(x, y);
	printf("%s", str);
}

void gotoxy(int x, int y)
{
	COORD loc;
	loc.X = x;
	loc.Y = y;
	SetConsoleCursorPosition(hand, loc);
}

void print_surface()
{
	int x, y;
	for (x = 0; x < FR_WIDTH; x++)
	{
		for (y = 0; y < FR_HEIGHT; y++)
		{
			int row = y;
			int col = x;
			if (surface[row][col] == 0)
			{
				printxy("0", x, y);
			}
			else
			{
				printxy("1", x, y);
			}
		}
	}
}


void setColor(int color)
{
	SetConsoleTextAttribute(hand, color);
}


