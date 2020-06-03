#include "tetris.h"

TetrisBlock getBlock1() {
    int block[FR_TETRIS_W][FR_TETRIS_H] = {
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 0}};

    return copyBlock(block);

}

TetrisBlock copyBlock(int block[FR_TETRIS_W][FR_TETRIS_H]) {
    TetrisBlock tetrisBlock;
    int i;
    for (i = 0; i < FR_TETRIS_W; i++) {
        int j;
        for (j = 0; j < FR_TETRIS_H; j++) {
            tetrisBlock.block[i][j] = block[i][j];
        }
    }
    return tetrisBlock;
}
