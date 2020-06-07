#include <conio.h>
#include <stdio.h>
#include <windows.h>

#include "gamePrinter.h"
#include "userControl.h"
#include "gameControler.h"
#include "tetris.h"

int main() {
    initGameSurface();
    showGameSurface();
    TetrisPoints T1 = getTetrisPoints1();
    add_new_block(T1);
    while(1){
        shiftAndShow(0, 1);
        
    }

    system("pause");

    return 0;
}
