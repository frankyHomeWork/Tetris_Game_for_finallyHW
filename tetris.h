#ifndef _TETRIS_H
#define _TETRIS_H

#define FR_TETRIS_W 4
#define FR_TETRIS_H 4

#include "Point.h"


typedef struct {
    PointNode *blocks;
    int size;
    int x;
    int y;
} TetrisPoints;

TetrisPoints tetrisRandomFactory();

TetrisPoints shiftTetrisPoints(TetrisPoints tetrisPoints, int x, int y);
TetrisPoints set_val_to_TetrisPoints(TetrisPoints tetrisPoints, int val);

static const struct
{
    TetrisPoints (* tetrisRandomFactory)();
    TetrisPoints (* shiftTetrisPoints)(TetrisPoints tetrisPoints, int x, int y);
    TetrisPoints (* set_val_to_TetrisPoints)(TetrisPoints tetrisPoints, int val);
    
} Trtris = {
    tetrisRandomFactory,
    shiftTetrisPoints,
    set_val_to_TetrisPoints
};

#endif
