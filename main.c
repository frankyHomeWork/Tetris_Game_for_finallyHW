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
    Sleep(1000);
    TetrisPoints T1 = getTetrisPoints1();
    TetrisPoints pre_T;

    bool firstTime = true;
    for (int i = 0; i < 50; i++) {
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

    return 0;
}
