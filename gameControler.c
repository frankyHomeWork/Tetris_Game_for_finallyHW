#include "gameControler.h"
#include<stdio.h>
#include <windows.h>
#include <stdbool.h>


void deletePreBlock();
void shiftAndShow(int x, int y);
void shiftBlock(int x, int y);
bool isAddingBlock();
void add_new_block(TetrisPoints tetrisPoints);



TetrisPoints pre_block;
bool has_pre_block = false;

TetrisPoints adding_block;
bool is_adding = false;

void deletePreBlock() {
    if(has_pre_block) {
        pre_block = set_val_to_TetrisPoints(pre_block, 0);
        set_tetris_block(pre_block);
    }
}


void shiftAndShow(int x, int y) {
    
    deletePreBlock();
    showGameSurface();
    shiftBlock(x, y);
    showGameSurface();
    Sleep(500);
}


void shiftBlock(int x, int y) {
    
    adding_block = shiftTetrisPoints(adding_block, x, y);
    adding_block = set_val_to_TetrisPoints(adding_block, 1);
    if(check_can_add_block(adding_block)) {
        set_tetris_block(adding_block);
        if(has_pre_block == false) {
            has_pre_block = true;
        } 
        pre_block = adding_block;
    } else {
        adding_block = shiftTetrisPoints(adding_block, -x, -y);
        set_tetris_block(adding_block);
        has_pre_block = false; 
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



