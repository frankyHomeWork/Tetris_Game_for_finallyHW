#include "gamePrinter.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

typedef struct {
    int height;
    int width;
    PointNode *canvas;
} GameSurface;

void initGameSurface();
void showGameSurface();

GameSurface createGameSurface(int height, int width);
void setBoundary(GameSurface gameSurface);
PointNode *createCanvas(int height, int width);


bool isSurfacehasFill(Point point);
bool isTouchStickSurfacehas(Point point);
bool isOverBoundary(Point point);
bool isTouchCeiling(Point point);
bool check_can_add_block(TetrisPoints tetrisPoints);
bool check_is_GameOver();
bool check_is_need_stop(TetrisPoints tetrisPoints);
bool check_is_LinkLine(int row);

void deleteLine(GameSurface gameSurface, int row);
void shiftDownSurfaceLine(int row);
void shiftDown(GameSurface gameSurface, int row);

void setCanvas(Point point, PointNode *pointNode);
void set_tetris_block(TetrisPoints tetrisPoints);
PointNode* getFixGameSurface_PointNode();

void initHand();
void setCursorVisable(int v);
void printxy(char *str, int x, int y);
void gotoxy(int x, int y);
void setColor(int color);

void showGameScore(int score);
void showNextBlock(TetrisPoints tetrisPoints);
void clearNextBlock(TetrisPoints tetrisPoints);

void showCanvas(PointNode *pointNode);//for test

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
        } else if (current->p.val == 2) { // for right left
            printxy("|", current->p.x, current->p.y);
        } else if (current->p.val == 3) { // for floor
            printxy("-", current->p.x, current->p.y);
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
    setBoundary(gameSurface);

    return gameSurface;
}

void setBoundary(GameSurface gameSurface) {
    PointNode *current = gameSurface.canvas;
    while (current != NULL) {
        if (current->p.y == FR_HEIGHT - 1) {
            current->p.val = 3;
        } else if (current->p.x == 0) {
            current->p.val = 2;
        } else if (current->p.x == FR_WIDTH - 1) {
            current->p.val = 2;
        }
        current = current->next;
    }
}



PointNode *createCanvas(int height, int width) {
    PointNode *firstPointNode = NULL;
    PointNode *preNode = NULL;

    bool firstTime = true;

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            PointNode *pointNode_tmp = (PointNode *)malloc(sizeof(PointNode));

            Point point = Point_Module.createPoint(x, y, 0);
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





bool isSurfacehasFill(Point point) {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return false;
    }

    PointNode *current = fixGameSurface.canvas;
    while (current != NULL) {
        if (current->p.x == point.x && current->p.y == point.y) {
            if (current->p.val >= 1) {
                return true;
            } else {
                return false;
            }
        }
        current = current->next;
    }
}

bool isTouchStickSurfacehas(Point point) {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return false;
    }

    PointNode *current = fixGameSurface.canvas;
    while (current != NULL) {
        if (current->p.x == point.x && current->p.y == point.y) {
            if (current->p.val == 1 || current->p.val == 3) {
                return true;
            } else {
                return false;
            }
        }
        current = current->next;
    }
}

bool isOverBoundary(Point point) {
    if (point.x <= 0 || point.x >= FR_WIDTH - 1) {
        return true;
    }
    if (point.y >= FR_HEIGHT - 1) {
        return true;
    }
    return false;
}

bool isTouchCeiling(Point point) {
    if (point.y < 0) {
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

        Point point = Point_Module.createPoint(x, y, val);
        bool is_fill = isSurfacehasFill(point);
        bool is_OverBoundary = isOverBoundary(point);

        if (is_fill || is_OverBoundary) {
            return false;
        }

        current = current->next;
    }
    return true;
}

bool check_is_GameOver() {
    PointNode *current = fixGameSurface.canvas;

    while (current != NULL) {
        int x = current->p.x;
        int y = current->p.y;
        int val = current->p.val;

        Point point = Point_Module.createPoint(x, y, val);
        bool is_TouchCeiling = isTouchCeiling(point);

        if (is_TouchCeiling) {
            printf("GameOver/n");
            system("pause");
            return true;
        } 
        current = current->next;
    }
    return false;
}


bool check_is_need_stop(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;

    for (int i = 0; i < tetrisPoints.size; i++) {
        int x = current->p.x + tetrisPoints.x;
        int y = current->p.y + tetrisPoints.y;
        int val = current->p.val;

        Point point = Point_Module.createPoint(x, y, val);
        bool is_Sticked = isTouchStickSurfacehas(point);

        if (is_Sticked) {
            return true;
        }

        current = current->next;
    }
    return false;
}

bool check_is_LinkLine(int row) {
    
    int count = 0;
    PointNode *current = fixGameSurface.canvas;
    while(current != NULL) {
        
        if(current->p.x > 0 && current->p.x < 17) {
            if( current->p.y == row ){
                if(current->p.val == 1) {
                    count++;
                } else {
                    return false;
                }
            }
        }
        current = current->next;
    }
    if(count == FR_WIDTH - 2) {
        return true;
    } else {
        return false;
    }
    
}

void deleteSurfaceLine(int row) {
    deleteLine(gameSurface, row);
    deleteLine(fixGameSurface, row);
}

void deleteLine(GameSurface gameSurface, int row) {
    
    PointNode *current = gameSurface.canvas;
    while(current != NULL) {
        
        if(current->p.x > 0 && current->p.x < 17) {
            if( current->p.y == row ){
               current->p.val = 0;
            }
        }
        current = current->next;
    }
}


void shiftDownSurfaceLine(int row) {
    shiftDown(gameSurface, row);
    shiftDown(fixGameSurface, row);
}


void shiftDown(GameSurface gameSurface, int row) { // delete the row and shift down the uper row
    
    PointNode *current = gameSurface.canvas;
    while(current != NULL) {
        
        if(current->p.x > 0 && current->p.x < 17) {
            if( current->p.y < row ){
               current->p.y++;
            } else if(current->p.y == row) {
                current->p.val = 0;
                current->p.y = 0;
            }
        }
        current = current->next;
    }
}




void setCanvas(Point point, PointNode *pointNode) {
    if (!isGameSurfaceInit) {
        printf("isGameSurfaceInit is false\n");
        return;
    }

    PointNode *current = pointNode;
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

void set_tetris_block(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;

    for (int i = 0; i < tetrisPoints.size; i++) {
        int x = current->p.x + tetrisPoints.x;
        int y = current->p.y + tetrisPoints.y;
        int val = current->p.val;

        Point point = Point_Module.createPoint(x, y, val);
        setCanvas(point, gameSurface.canvas);
        current = current->next;
    }
}

PointNode* getFixGameSurface_PointNode() {
    return fixGameSurface.canvas;
}


void set_tetris_blockToFixSurface(TetrisPoints tetrisPoints) {
    PointNode *current = tetrisPoints.blocks;

    for (int i = 0; i < tetrisPoints.size; i++) {
        int x = current->p.x + tetrisPoints.x;
        int y = current->p.y + tetrisPoints.y;
        int val = current->p.val;

        Point point = Point_Module.createPoint(x, y, val);
        setCanvas(point, fixGameSurface.canvas);
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

void showCanvas(PointNode *pointNode) {
    PointNode *current = pointNode;
    while (current != NULL) {
        printf("TEST: x: %d, y: %d val: %d\n", current->p.x, current->p.y,
               current->p.val);
        current = current->next;
    }
}

void showGameScore(int score) {
    char score_str[10] = ""; 
    _itoa(score, score_str, 10);
    char score_txt[30];
    strcpy(score_txt, "Score: ");
    strcat(score_txt, score_str);
    printxy(score_txt, 20, 10);
}

void showNextBlock(TetrisPoints tetrisPoints) {
    printxy("..........", 19, 0);
    int left_row_i;
    for(left_row_i = 0 ; left_row_i <= 5 ; left_row_i++) {
        printxy(".", 19, left_row_i);
    }

    int right_row_i;
    for(right_row_i = 0 ; right_row_i <= 5 ; right_row_i++) {
        printxy(".", 28, right_row_i);
    }
    printxy("..........", 19, 5);
    
    
    PointNode *current = tetrisPoints.blocks;
    
    int shift_x = 22;
    int shift_y = 1;
    
    while (current != NULL) {
        if (current->p.val == 1) {
            printxy("O", current->p.x + shift_x, current->p.y + shift_y);
        }
        current = current->next;
    }
    
}

void clearNextBlock(TetrisPoints tetrisPoints) {
 
    PointNode *current = tetrisPoints.blocks;
    
    int shift_x = 22;
    int shift_y = 1;
    
    while (current != NULL) {
        if (current->p.val == 1) {
            printxy(" ", current->p.x + shift_x, current->p.y + shift_y);
        }
        current = current->next;
    }
    
}



#ifdef DEBUG
int main() {
    initGameSurface();
    showGameSurface();
    showGameScore(10);

    system("pause");

    return 0;
}
#endif
