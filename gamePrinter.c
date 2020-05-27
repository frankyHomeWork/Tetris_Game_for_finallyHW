#include "gamePrinter.h"

#include <stdio.h>
#include <windows.h>

HANDLE hand;
int surface[FR_HEIGHT][FR_WIDTH] = {0};

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

void print_surface() {
    int x, y;
    for (x = 0; x < FR_WIDTH; x++) {
        for (y = 0; y < FR_HEIGHT; y++) {
            int row = y;
            int col = x;
            if (surface[row][col] == 0) {
                printxy("0", x, y);
            } else {
                printxy("1", x, y);
            }
        }
    }
}

void setColor(int color) { SetConsoleTextAttribute(hand, color); }
