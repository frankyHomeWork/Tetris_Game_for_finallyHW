#include "userControl.h"

#include <conio.h>
#include <stdio.h>

TetrisPoints control_Block0(TetrisPoints tetrisPoints) {
    int ch;
    int cur_x = 0;
    int cur_y = 0;
    while (1) {
        if (kbhit() != 0) {
            ch = getch();
            switch (ch) {
                // case 72:  // up
                //     erase_block(Block0, cur_x, cur_y);
                //     cur_y--;
                //     print_block(Block0, cur_x, cur_y);
                //     break;
                case 80:  // down
                    return shiftTetrisPoints(tetrisPoints, 0, 1);
                    break;
                case 75:  // left
                    return shiftTetrisPoints(tetrisPoints, -1, 0);
                    break;
                case 77:  // right
                    return shiftTetrisPoints(tetrisPoints, 1, 0);
                    break;
                // case 113:  // q
                //     return;
                //     break;
            }
        }
    }
}
