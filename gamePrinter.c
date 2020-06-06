#include "gamePrinter.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

PointNode *createCanvas(int height, int width);
GameSurface createGameSurface(int height, int width);
void initHand();
void showCanvas(PointNode *pointNode);
bool isSurfacehasFill(Point point);
void setBoundary(GameSurface gameSurface);

HANDLE hand;
GameSurface gameSurface;
GameSurface fixGameSurface;
bool isGameSurfaceInit = false;

void initGameSurface() {
    initHand();
    gameSurface = createGameSurface(14, 18);
    fixGameSurface = createGameSurface(14, 18);

    isGameSurfaceInit = true;
}

void showGameSurface() {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return;
    }

    PointNode *current = gameSurface.canvas;
    while (current != NULL) {
        if (current->p.val == 1) {
            printxy("O", current->p.x, current->p.y);
        } else {
            printxy(" ", current->p.x, current->p.y);
        }

        current = current->next;
    }
}

void setBoundary(GameSurface gameSurface) {
    PointNode *current = gameSurface.canvas;
    while (current != NULL) {
        if (current->p.y == FR_HEIGHT - 1) {
            current->p.val = 1;
        } else if (current->p.x == 0) {
            current->p.val = 1;
        } else if (current->p.x == FR_WIDTH - 1) {
            current->p.val = 1;
        }
        current = current->next;
    }
}

GameSurface createGameSurface(int height, int width) {
    GameSurface gameSurface;

    gameSurface.height = height;
    gameSurface.width = width;
    gameSurface.canvas = createCanvas(height, width);
    setBoundary(gameSurface);

    return gameSurface;
}

PointNode *createCanvas(int height, int width) {
    PointNode *firstPointNode = NULL;
    PointNode *preNode = NULL;

    bool firstTime = true;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            PointNode *pointNode_tmp = (PointNode *)malloc(sizeof(PointNode));

            Point point = createPoint(x, y, 0);
            pointNode_tmp->p = point;
            pointNode_tmp->next = NULL;

            if (firstTime) {
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

void showCanvas(PointNode *pointNode) {
    PointNode *current = pointNode;
    while (current != NULL) {
        printf("TEST: x: %d, y: %d val: %d\n", current->p.x, current->p.y,
               current->p.val);
        current = current->next;
    }
}

void setCanvas(Point point) {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return;
    }

    PointNode *current = gameSurface.canvas;
    while (current != NULL) {
        if (current->p.x == point.x && current->p.y == point.y) {
            if (current->p.val != point.val) {
                current->p.val = point.val;
            }
            return;
        }
        current = current->next;
    }
}

bool isSurfacehasFill(Point point) {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return false;
    }

    PointNode *current = fixGameSurface.canvas;
    while (current != NULL) {
        if (current->p.x == point.x && current->p.y == point.y) {
            if (current->p.val == 1) {
                return true;
            } else {
                return false;
            }
        }
        current = current->next;
    }
}

bool isOverBoundary(Point point) {
    if (point.x < 0 || point.x > FR_WIDTH - 1) {
        return true;
    }
    if (point.y < 0 || point.y > FR_HEIGHT - 1) {
        return true;
    }
    return false;
}

bool check_can_add_block(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;

    for (int i = 0; i < tetrisPoints.size; i++) {
        int x = current->p.x + tetrisPoints.x;
        int y = current->p.y + tetrisPoints.y;
        int val = current->p.val;

        Point point = createPoint(x, y, val);
        bool is_fill = isSurfacehasFill(point);
        bool is_OverBoundary = isOverBoundary(point);

        if (is_fill || is_OverBoundary) {
            return false;
        }

        current = current->next;
    }
    return true;
}

void set_tetris_block(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;

    for (int i = 0; i < tetrisPoints.size; i++) {
        int x = current->p.x + tetrisPoints.x;
        int y = current->p.y + tetrisPoints.y;
        int val = current->p.val;

        Point point = createPoint(x, y, val);
        setCanvas(point);
        current = current->next;
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
    TetrisPoints T1 = getTetrisPoints1();
    TetrisPoints pre_T;

    bool firstTime = true;
    for (int i = 0; i < 25; i++) {
        T1 = shiftTetrisPoints(T1, 0, 1);
        if (check_can_add_block(T1)) {
            if (firstTime) {
                firstTime = false;
            } else {  // delete pre_T
                pre_T = set_val_to_TetrisPoints(pre_T, 0);
                set_tetris_block(pre_T);
                showGameSurface();
            }
            T1 = set_val_to_TetrisPoints(T1, 1);
            set_tetris_block(T1);
            showGameSurface();
            Sleep(1000);
            pre_T = T1;
        }
    }

    showGameSurface();

    system("pause");

    return 0;
}
#endif
