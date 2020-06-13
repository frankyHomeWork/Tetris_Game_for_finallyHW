#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "gamePrinter.h"
#include "userControl.h"
#include "gameControler.h"
#include "tetris.h"

int main() {
    initGameSurface();
    showGameSurface();
    
    TetrisPoints nextBlock = Trtris.tetrisRandomFactory();
    
    bool first_time = true;
    while(1){
        if(first_time) {
            TetrisPoints first_block = Trtris.tetrisRandomFactory();
            add_new_block(first_block);
            first_time = false;
        }
        
        showNextBlock(nextBlock);
        if(isAddingBlock()) {
            control_Block0();
            shiftAndShow(0, 1);
            deleteLinkLine();
        } else{
            clearNextBlock(nextBlock);
            add_new_block(nextBlock);
            nextBlock = tetrisRandomFactory();
        }
    }

    system("pause");

    return 0;
}
