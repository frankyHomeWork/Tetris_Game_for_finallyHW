#include "gamePrinter.h"

#include <stdio.h>
#include <windows.h>

HANDLE hand;

int game_surface[FR_HEIGHT][FR_WIDTH] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}, 
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};



void initGamePrinter() {
    hand = GetStdHandle(STD_OUTPUT_HANDLE);
    setCursorVisable(1);
}

void print_block(int block[][FR_BOLCK_W], int x, int y) {
    int w, h;
    for (w = 0; w < FR_BOLCK_W; w++) {
        for (h = 0; h < FR_BOLCK_H; h++) {
            if (block[h][w] == 1) {
                printxy("O", x + w, y + h);
            }
        }
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


void erase_block(int block[][FR_BOLCK_W], int x, int y) {
    int w, h;
    for (w = 0; w < FR_BOLCK_W; w++) {
        for (h = 0; h < FR_BOLCK_H; h++) {
            if (block[h][w] == 1) {
                printxy(" ", x + w, y + h);
            }
        }
    }
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

void print_surface(int surface[][FR_WIDTH]) {
    int x, y;
    for (x = 0; x < FR_WIDTH; x++) {
        for (y = 0; y < FR_HEIGHT; y++) {
            int row = y;
            int col = x;
            if (surface[row][col] == 0) {
                printxy(" ", x, y);
            } else {
                printxy("1", x, y);
            }
        }
    }
}

void initGameFrame() {
    print_surface(game_surface);
}

void setColor(int color) { SetConsoleTextAttribute(hand, color); }

void setGameSurfaceToFill(int x, int y) {
    if(y < FR_HEIGHT && y >= 0) {
        if(x < FR_WIDTH && x >= 0) {
            game_surface[y][x] = 1 ;
        }
    }

}

void setGameSurfaceToEmpty(int x, int y) {
    if(y < FR_HEIGHT && y >= 0) {
        if(x < FR_WIDTH && x >= 0) {
            game_surface[y][x] = 0 ;
        }
    }
}


bool checkGameSurfaceIsFill(int x, int y) {

    if(game_surface[y][x] == 1) {
        return true;
    } else {
        return false;
    }


}







