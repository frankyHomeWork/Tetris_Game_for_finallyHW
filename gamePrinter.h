#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

void setCursorVisable(int v);
void printxy(char *str, int x, int y);
void gotoxy(int x, int y);
void print_surface();
void setColor(int color);
void initGamePrinter();

#endif




