#ifndef _TETRIS_H
#define _TETRIS_H

#define FR_TETRIS_W 4
#define FR_TETRIS_H 4

typedef struct {
    int block[FR_TETRIS_W][FR_TETRIS_H];
} TetrisBlock;

TetrisBlock getBlock1();
TetrisBlock copyBlock(int block[FR_TETRIS_W][FR_TETRIS_H]);

#endif
