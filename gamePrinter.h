#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

#define FR_HEIGHT 14
#define FR_WIDTH 18
#define FR_BOLCK_H 4
#define FR_BOLCK_W 4

void setCursorVisable(int v);
void printxy(char *str, int x, int y);
void gotoxy(int x, int y);
void print_surface();
void setColor(int color);
void initGamePrinter();
void print_block(int block[][FR_BOLCK_W], int x, int y);
void erase_block(int block[][FR_BOLCK_W], int x, int y);
void initGameFrame();

#endif

