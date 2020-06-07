#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

#define FR_HEIGHT 14
#define FR_WIDTH 18

#include "tetris.h"
#include <stdbool.h>
#include "Point.h"

void initGameSurface();
void showGameSurface();
bool check_can_add_block(TetrisPoints tetrisPoints);
void set_tetris_block(TetrisPoints tetrisPoints);
void set_tetris_blockToFixSurface(TetrisPoints tetrisPoints);
bool check_is_need_stop(TetrisPoints tetrisPoints);

#endif

