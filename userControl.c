#include "userControl.h"

#include <conio.h>
#include <time.h>

void control_Block0() {
    
    time_t start_t, end_t;
    double diff_t;
    time(&start_t);
    
    int ch;
    while (1) {
        if (kbhit() != 0) {
            ch = getch();
            switch (ch) {
                case 80:  // down
                    GameControler.shiftAndShow(0, 1);
                    return;
                    break;
                case 75:  // left
                    GameControler.shiftAndShow(-1, 0);
                    return;
                    break;
                case 77:  // right
                    GameControler.shiftAndShow(1, 0);
                    return;
                    break;
            }
        }
        
        time(&end_t);
        diff_t = difftime(end_t, start_t);
        if(diff_t >= 0.01) {
            break;
        }
        
    }
}
