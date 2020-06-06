#include "gamePrinter.h"

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>


PointNode* createCanvas(int height, int width);
GameSurface createGameSurface(int height, int width);
void initHand();
void showCanvas(PointNode* pointNode);

HANDLE hand;
GameSurface gameSurface;
bool isGameSurfaceInit = false;

void initGameSurface() {
    initHand();
    gameSurface = createGameSurface(14, 18);
    isGameSurfaceInit = true;
}

void showGameSurface() {
    if(!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return;
    }
    
    PointNode *current = gameSurface.canvas;
    while(current != NULL) {
        if(current->p.val == 1) {
            printxy("O", current->p.x, current->p.y);
        } else {
            printxy(" ", current->p.x, current->p.y);
        }
        
        current = current->next;
    }
}

GameSurface createGameSurface(int height, int width) {
    GameSurface gameSurface;
    
    gameSurface.height = height;
    gameSurface.width = width;
    gameSurface.canvas = createCanvas(height, width);
    
    return gameSurface;
}



PointNode* createCanvas(int height, int width) {
    
    PointNode *firstPointNode = NULL;
    PointNode *preNode = NULL;
    
    bool firstTime = true;
    
    for(int x = 0 ; x < width ; x++ ) {
        for(int y = 0 ; y < height ; y++ ) {
            PointNode *pointNode_tmp = (PointNode*)malloc(sizeof(PointNode));
            
            Point point = createPoint(x, y , 0);
            pointNode_tmp->p = point;
            pointNode_tmp->next = NULL;
            
            if(firstTime) {
                firstPointNode = pointNode_tmp;
                firstTime = false;
            } else {
                preNode->next = pointNode_tmp;
            }
            preNode = pointNode_tmp;
        }
    }
    return firstPointNode;
}


void showCanvas(PointNode* pointNode) {
    PointNode *current = pointNode;
    while(current != NULL) {
        printf("TEST: x: %d, y: %d val: %d\n", current->p.x, current->p.y, current->p.val);
        current = current->next;
    }
}

void setCanvas(Point point) {
    
    if(!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return;
    }
    
    PointNode *current = gameSurface.canvas;
    while(current != NULL) {
        if(current->p.x == point.x && current->p.y == point.y && current->p.val != point.val) {
            current->p.val = point.val;
            return;
        }
        current = current->next;
    }
    
}

void set_tetris_block(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;
    
    for(int i = 0 ; i < tetrisPoints.size ; i++) {
        setCanvas(current->p);
        current = current->next;
    }
    
    
}


void print_tetris_block(TetrisBlock tetrisBlock, int x, int y) {
    int w, h;
    for (w = 0; w < FR_TETRIS_W; w++) {
        for (h = 0; h < FR_TETRIS_H; h++) {
            if (tetrisBlock.block[h][w] == 1) {
                printxy("O", x + w, y + h);
            }
        }
    }
}

void erase_tetris_block(TetrisBlock tetrisBlock, int x, int y) {
    int w, h;
    for (w = 0; w < FR_TETRIS_W; w++) {
        for (h = 0; h < FR_TETRIS_H; h++) {
            if (tetrisBlock.block[h][w] == 1) {
                printxy(" ", x + w, y + h);
            }
        }
    }
}

void initHand() {
    hand = GetStdHandle(STD_OUTPUT_HANDLE);
    setCursorVisable(1);
}

void setCursorVisable(int v) {
    CONSOLE_CURSOR_INFO cursor_info = {100, v};
    SetConsoleCursorInfo(hand, &cursor_info);
}

void printxy(char *str, int x, int y) {
    gotoxy(x, y);
    printf("%s", str);
}

void gotoxy(int x, int y) {
    COORD loc;
    loc.X = x;
    loc.Y = y;
    SetConsoleCursorPosition(hand, loc);
}

void setColor(int color) { SetConsoleTextAttribute(hand, color); }


#ifdef DEBUG
int main() {
    initGameSurface();
    showGameSurface();
    Sleep(1000);
    
    set_tetris_block(getTetrisPoints1());
    showGameSurface();
    
    
    
    system("pause");
    
    return 0;
}
#endif





