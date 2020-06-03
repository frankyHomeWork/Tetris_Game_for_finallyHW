#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

#define FR_HEIGHT 14
#define FR_WIDTH 18
#define FR_BOLCK_H 4
#define FR_BOLCK_W 4

#include "tetris.h"
#include <stdbool.h>
void setCursorVisable(int v);
void printxy(char *str, int x, int y);
void gotoxy(int x, int y);
void print_surface();
void setColor(int color);
void initGamePrinter();
void print_block(int block[][FR_BOLCK_W], int x, int y);
void print_tetris_block(TetrisBlock tetrisBlock, int x, int y);
void erase_block(int block[][FR_BOLCK_W], int x, int y);
void erase_tetris_block(TetrisBlock tetrisBlock, int x, int y);
void initGameFrame();

void setGameSurfaceToFill(int x, int y);
void setGameSurfaceToEmpty(int x, int y);
bool checkGameSurfaceIsFill(int x, int y);

#endif

