#ifndef _GAME_PRINTER_H
#define _GAME_PRINTER_H

#define FR_HEIGHT 14
#define FR_WIDTH 18

#include "tetris.h"
#include <stdbool.h>
#include "Point.h"

void initGameSurface();
void showGameSurface();
bool check_can_add_block(TetrisPoints tetrisPoints);
bool check_is_GameOver();
void set_tetris_block(TetrisPoints tetrisPoints);
void set_tetris_blockToFixSurface(TetrisPoints tetrisPoints);
PointNode* getFixGameSurface_PointNode();
bool check_is_need_stop(TetrisPoints tetrisPoints);
bool check_is_LinkLine(int row);
void deleteSurfaceLine(int row);
void shiftDownSurfaceLine(int row);

void showGameScore(int score);
void showNextBlock(TetrisPoints tetrisPoints);
void clearNextBlock(TetrisPoints tetrisPoints);

// for TEST
void showCanvas(PointNode *pointNode);

static const struct
{
    void (* initGameSurface)();
    void (* showGameSurface)();
    bool (* check_can_add_block)(TetrisPoints tetrisPoints);
    bool (* check_is_GameOver)();
    void (* set_tetris_block)(TetrisPoints tetrisPoints);
    void (* set_tetris_blockToFixSurface)(TetrisPoints tetrisPoints);
    PointNode* (* getFixGameSurface_PointNode)();
    bool (* check_is_need_stop)(TetrisPoints tetrisPoints);
    bool (* check_is_LinkLine)(int row);
    void (* deleteSurfaceLine)(int row);
    void (* shiftDownSurfaceLine)(int row);

    void (* showGameScore)(int score);
    void (* showNextBlock)(TetrisPoints tetrisPoints);
    void (* clearNextBlock)(TetrisPoints tetrisPoints);

    // for TEST
    void (* showCanvas)(PointNode *pointNode);
    
} GamePrinter = {
    initGameSurface,
    showGameSurface,
    check_can_add_block,
    check_is_GameOver,
    set_tetris_block,
    set_tetris_blockToFixSurface,
    getFixGameSurface_PointNode,
    check_is_need_stop,
    check_is_LinkLine,
    deleteSurfaceLine,
    shiftDownSurfaceLine,

    showGameScore,
    showNextBlock,
    clearNextBlock,

    // for TEST
    showCanvas
    
};
#endif

