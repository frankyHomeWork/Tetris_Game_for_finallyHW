#include "userControl.h"

#include <conio.h>
#include <time.h>

TetrisPoints control_Block0(TetrisPoints tetrisPoints) {
    
    time_t start_t, end_t;
    double diff_t;
    time(&start_t);
    
    int ch;
    while (1) {
        if (kbhit() != 0) {
            ch = getch();
            switch (ch) {
                case 80:  // down
                    return shiftTetrisPoints(tetrisPoints, 0, 1);
                    break;
                case 75:  // left
                    return shiftTetrisPoints(tetrisPoints, -1, 0);
                    break;
                case 77:  // right
                    return shiftTetrisPoints(tetrisPoints, 1, 0);
                    break;
            }
        }
        
        time(&end_t);
        diff_t = difftime(end_t, start_t);
        if(diff_t >= 0.2) {
            break;
        }
        
    }
}
