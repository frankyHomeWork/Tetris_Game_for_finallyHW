#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

#define FR_HEIGHT 14
#define FR_WIDTH 18
#define FR_BOLCK_H 4
#define FR_BOLCK_W 4

#include "tetris.h"
#include <stdbool.h>
#include "Point.h"



typedef struct {
    int height;
    int width;
    PointNode *canvas;
} GameSurface;


void setCursorVisable(int v);
void printxy(char *str, int x, int y);
void gotoxy(int x, int y);
void print_surface();
void setColor(int color);
void initGamePrinter();
void initGameFrame();

#endif

