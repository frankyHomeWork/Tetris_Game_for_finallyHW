#include "tetris.h"
#include <stdlib.h>
#include <stdbool.h>
#include<time.h> 

TetrisPoints copy2TetrisPoints(int block[FR_TETRIS_W][FR_TETRIS_H]);
TetrisPoints shiftTetrisPoints(TetrisPoints tetrisPoints, int x, int y);
TetrisPoints set_val_to_TetrisPoints(TetrisPoints tetrisPoints, int val);

TetrisPoints tetrisRandomFactory();

TetrisPoints getTetrisPoints1();
TetrisPoints getTetrisPoints2();
TetrisPoints getTetrisPoints3();
TetrisPoints getTetrisPoints4();
TetrisPoints getTetrisPoints5();


TetrisPoints tetrisRandomFactory() {
    static bool first_time = true;
    if(first_time) {
        srand(time(NULL));
        first_time = false;
    }
    
    int num = rand() % 5 + 1;
    switch(num) {
    case 1:
        return getTetrisPoints1();
        break;
    case 2:
        return getTetrisPoints2();
        break;
    case 3:
        return getTetrisPoints3();
        break;
    case 4:
        return getTetrisPoints4();
        break;
    case 5:
        return getTetrisPoints5();
        break;
    default:
        break;
    }   
}

TetrisPoints getTetrisPoints1() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 0}};

    TetrisPoints tetrisPoints = copy2TetrisPoints(block);
    return shiftTetrisPoints(tetrisPoints, 8, -4);
}


TetrisPoints getTetrisPoints2() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 0, 0, 0}, 
        {0, 1, 1, 0}, 
        {0, 1, 1, 0}, 
        {0, 0, 0, 0}};

    TetrisPoints tetrisPoints = copy2TetrisPoints(block);
    return shiftTetrisPoints(tetrisPoints, 8, -4);
}

TetrisPoints getTetrisPoints3() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 1, 0, 0}};

    TetrisPoints tetrisPoints = copy2TetrisPoints(block);
    return shiftTetrisPoints(tetrisPoints, 8, -4);
}

TetrisPoints getTetrisPoints4() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {1, 1, 1, 1}, 
        {0, 0, 0, 0}};

    TetrisPoints tetrisPoints = copy2TetrisPoints(block);
    return shiftTetrisPoints(tetrisPoints, 8, -4);
}

TetrisPoints getTetrisPoints5() {
    int block[FR_TETRIS_H][FR_TETRIS_W] = {
        {0, 0, 0, 0}, 
        {0, 1, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}};

    TetrisPoints tetrisPoints = copy2TetrisPoints(block);
    return shiftTetrisPoints(tetrisPoints, 8, -4);
}


TetrisPoints copy2TetrisPoints(int block[FR_TETRIS_W][FR_TETRIS_H]) {
    TetrisPoints tetrisPoints;
    
    tetrisPoints.blocks = NULL;
    tetrisPoints.size = 0;
    tetrisPoints.x = 0;
    tetrisPoints.y = 0;
    
    PointNode *firstPointNode = NULL;
    PointNode *preNode = NULL;
    
    bool firstTime = true;
    
    for (int h = 0; h < FR_TETRIS_H; h++) {
        for (int w = 0; w < FR_TETRIS_W ; w++) {
            if(block[h][w] == 1) {
                Point p = Point_Module.createPoint(w, h, 1); 
                
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



TetrisPoints shiftTetrisPoints(TetrisPoints tetrisPoints, int x, int y) {
    tetrisPoints.x += x; 
    tetrisPoints.y += y; 
    return tetrisPoints;     
}

TetrisPoints set_val_to_TetrisPoints(TetrisPoints tetrisPoints, int val) {
    
    PointNode *current = tetrisPoints.blocks;
    while(current != NULL) {
        current->p.val = val;
        current = current->next;
    }
    
    return tetrisPoints;     
}