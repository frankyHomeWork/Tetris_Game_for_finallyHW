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
} TetrisPoints;

TetrisPoints getTetrisPoints1();
TetrisPoints copy2TetrisPoints(int block[FR_TETRIS_W][FR_TETRIS_H]);

TetrisBlock getBlock1();
TetrisBlock copyBlock(int block[FR_TETRIS_W][FR_TETRIS_H]);

#endif
