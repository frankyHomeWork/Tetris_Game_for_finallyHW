#ifndef _TETRIS_H
#define _TETRIS_H

#define FR_TETRIS_W 4
#define FR_TETRIS_H 4

#include "Point.h"

typedef struct {
    int block[FR_TETRIS_W][FR_TETRIS_H];
} TetrisBlock;

typedef struct {
    PointNode *blocks;
    int size;
    int x;
    int y;
} TetrisPoints;

TetrisPoints getTetrisPoints1();
TetrisPoints copy2TetrisPoints(int block[FR_TETRIS_W][FR_TETRIS_H]);
TetrisPoints shiftTetrisPoints(TetrisPoints tetrisPoints, int x, int y);
TetrisPoints set_val_to_TetrisPoints(TetrisPoints tetrisPoints, int val);
#endif
