#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "gamePrinter.h"

#define block_h 4
#define block_w 4
int Block0[block_h][block_w] = {
	{0, 0, 0, 0},
	{0, 1, 1, 0},
	{0, 1, 1, 0},
	{0, 0, 0, 0}};
void print_block(int block[][block_w], int x, int y)
{
	int w, h;
	for (w = 0; w < block_w; w++)
	{
		for (h = 0; h < block_h; h++)
		{
			if (block[h][w] == 1)
			{
				printxy("O", x + w, y + h);
			}
		}
	}
}

void erase_block(int block[][block_w], int x, int y)
{
	int w, h;
	for (w = 0; w < block_w; w++)
	{
		for (h = 0; h < block_h; h++)
		{
			if (block[h][w] == 1)
			{
				printxy(" ", x + w, y + h);
			}
		}
	}
}



void key_control()
{
	int ch;
	while (1)
	{
		if (kbhit() != 0)
		{
			ch = getch();

			switch (ch)
			{
			case 72: //up
				printf("ch: %d\n", ch);
				break;
			case 80: //down
				printf("ch: %d\n", ch);
				break;
			case 75: //left
				printf("ch: %d\n", ch);
				break;
			case 77: //right
				printf("ch: %d\n", ch);
				break;
			case 32: //space
				printf("ch: %d\n", ch);
				break;
			case 113: //q
				printf("ch: %d\n", ch);
				return;
				break;
			default:
				printf("other task: %d \n", ch);
			}
		}
	}
}

void control_Block0()
{
	int ch;
	int cur_x = 0;
	int cur_y = 0;
	while (1)
	{
		if (kbhit() != 0)
		{
			ch = getch();
			switch (ch)
			{
			case 72: //up
				erase_block(Block0, cur_x, cur_y);
				cur_y--;
				print_block(Block0, cur_x, cur_y);
				break;
			case 80: //down
				erase_block(Block0, cur_x, cur_y);
				cur_y++;
				print_block(Block0, cur_x, cur_y);
				break;
			case 75: //left
				erase_block(Block0, cur_x, cur_y);
				cur_x--;
				print_block(Block0, cur_x, cur_y);
				break;
			case 77: //right
				erase_block(Block0, cur_x, cur_y);
				cur_x++;
				print_block(Block0, cur_x, cur_y);
				break;
			case 113: //q
				printf("ch: %d\n", ch);
				return;
				break;
			}
		}
	}
}

int main()
{
	initGamePrinter();
	control_Block0();

	return 0;
}
