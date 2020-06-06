#include "userControl.h"

#include <conio.h>
#include <stdio.h>


// int Block0[FR_BOLCK_H][FR_BOLCK_W] = {
//     {0, 0, 0, 0}, 
//     {0, 1, 1, 0}, 
//     {0, 1, 1, 0}, 
//     {0, 0, 0, 0}};

// void control_Block0() {
//     int ch;
//     int cur_x = 0;
//     int cur_y = 0;
//     while (1) {
//         if (kbhit() != 0) {
//             ch = getch();
//             switch (ch) {
//                 case 72:  // up
//                     erase_block(Block0, cur_x, cur_y);
//                     cur_y--;
//                     print_block(Block0, cur_x, cur_y);
//                     break;
//                 case 80:  // down
//                     erase_block(Block0, cur_x, cur_y);
//                     cur_y++;
//                     print_block(Block0, cur_x, cur_y);
//                     break;
//                 case 75:  // left
//                     erase_block(Block0, cur_x, cur_y);
//                     cur_x--;
//                     print_block(Block0, cur_x, cur_y);
//                     break;
//                 case 77:  // right
//                     erase_block(Block0, cur_x, cur_y);
//                     cur_x++;
//                     print_block(Block0, cur_x, cur_y);
//                     break;
//                 case 113:  // q
//                     return;
//                     break;
//             }
//         }
//     }
// }
