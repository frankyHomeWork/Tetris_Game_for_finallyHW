#include "tetris.h"
#include <stdlib.h>
#include <stdbool.h>

TetrisBlock getBlock1() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
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

TetrisPoints getTetrisPoints1(){
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 0}};

    return copy2TetrisPoints(block);
}


TetrisPoints copy2TetrisPoints(int block[FR_TETRIS_W][FR_TETRIS_H]) {
    TetrisPoints tetrisPoints;
    tetrisPoints.size = 0;
    tetrisPoints.blocks = NULL;
    
    PointNode *firstPointNode = NULL;
    PointNode *preNode = NULL;
    
    bool firstTime = true;
    
    for (int h = 0; h < FR_TETRIS_H; h++) {
        for (int w = 0; w < FR_TETRIS_W ; w++) {
            if(block[h][w] == 1) {
                Point p = createPoint(w, h, 1); 
                
                PointNode *pointNode_tmp = (PointNode*)malloc(sizeof(PointNode));
                pointNode_tmp->p = p;
                pointNode_tmp->next = NULL;
                
                if(firstTime) {
                    firstPointNode = pointNode_tmp;
                    firstTime = false;
                } else {
                    preNode->next = pointNode_tmp;
                }
                preNode = pointNode_tmp;
                tetrisPoints.size++;
            }
        }
    }
    tetrisPoints.blocks = firstPointNode;
    
    return tetrisPoints;
}