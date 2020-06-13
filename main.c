#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <stdbool.h>

#include "gamePrinter.h"
#include "userControl.h"
#include "gameControler.h"
#include "tetris.h"

int main() {
    GamePrinter.initGameSurface();
    GamePrinter.showGameSurface();
    
    TetrisPoints nextBlock = Trtris.tetrisRandomFactory();
    
    bool first_time = true;
    while(1){
        if(first_time) {
            TetrisPoints first_block = Trtris.tetrisRandomFactory();
            GameControler.add_new_block(first_block);
            first_time = false;
        }
        
        GamePrinter.showNextBlock(nextBlock);
        if(isAddingBlock()) {
            UserControl.control_Block0();
            GameControler.shiftAndShow(0, 1);
            GameControler.deleteLinkLine();
        } else{
            GamePrinter.clearNextBlock(nextBlock);
            GameControler.add_new_block(nextBlock);
            nextBlock = Trtris.tetrisRandomFactory();
        }
    }

    system("pause");

    return 0;
}
