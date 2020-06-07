#ifndef _GAME_CONTROLER_H
#define _GAME_CONTROLER_H
#include "tetris.h"
#include "gamePrinter.h"
#include "userControl.h"

void shiftAndShow(int x, int y);
void add_new_block(TetrisPoints tetrisPoints);
bool isAddingBlock();
TetrisPoints get_adding_block();
void set_adding_block(TetrisPoints tetrisPoints);
void deleteLinkLine();

#endif
