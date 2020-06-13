#include "gameControler.h"
#include<stdio.h>
#include <windows.h>
#include <stdbool.h>


void deletePreBlock();
void shiftAndShow(int x, int y);
void shiftBlock(int x, int y);
bool isAddingBlock();
void add_new_block(TetrisPoints tetrisPoints);
TetrisPoints get_adding_block();
void set_adding_block(TetrisPoints tetrisPoints);


TetrisPoints pre_block;
bool has_pre_block = false;

TetrisPoints adding_block;
bool is_adding = false;

int gameScore = 0;

void shiftAndShow(int x, int y) {
    deletePreBlock();
    shiftBlock(x, y);
    GamePrinter.showGameSurface();
    Sleep(100);
}


void deleteLinkLine() {
    
    for(int i = 0 ; i <= 12 ; i++) {
        if(check_is_LinkLine(i)) {
            GamePrinter.deleteSurfaceLine(i);
            GamePrinter.shiftDownSurfaceLine(i);
            gameScore++;
        }    
    }
    GamePrinter.showGameScore(gameScore);
}


void shiftBlock(int x, int y) {
    
    if(is_adding == false) {
        return;
    }
    
    adding_block = Trtris.shiftTetrisPoints(adding_block, x, y);
    adding_block = Trtris.set_val_to_TetrisPoints(adding_block, 1);
    if( GamePrinter.check_can_add_block( adding_block ) ) {
        GamePrinter.set_tetris_block( adding_block );
        if(has_pre_block == false) {
            has_pre_block = true;
        } 
        pre_block = adding_block;
    } else {
        if(GamePrinter.check_is_need_stop(adding_block)) { // stop updata block
            adding_block = Trtris.shiftTetrisPoints(adding_block, -x, -y);
            // printf("y: %d\n", adding_block.y);system("pause");
            GamePrinter.set_tetris_block(adding_block);
            GamePrinter.set_tetris_blockToFixSurface(adding_block);
            is_adding = false; // until add new block, then it will true
            has_pre_block = false; 
        } else {
            adding_block = Trtris.shiftTetrisPoints(adding_block, -x, -y);
            GamePrinter.set_tetris_block(adding_block);
        }
        
    }
    
    
}

void deletePreBlock() {
    if(has_pre_block) {
        pre_block = Trtris.set_val_to_TetrisPoints(pre_block, 0);
        GamePrinter.set_tetris_block(pre_block);
    }
}

bool isAddingBlock() {
    return is_adding;
}


void add_new_block(TetrisPoints tetrisPoints) {
    adding_block = tetrisPoints;
    
    is_adding = true;
    has_pre_block = false;
}

TetrisPoints get_adding_block() {
    return adding_block;
}

void set_adding_block(TetrisPoints tetrisPoints) {
    adding_block = tetrisPoints;
}
