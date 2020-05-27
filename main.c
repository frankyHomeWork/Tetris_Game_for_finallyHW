#include <stdio.h>
#include <windows.h>

#define HEIGHT 14
#define WIDTH 18

HANDLE hand;

void setCursorVisable(int v)
{
	CONSOLE_CURSOR_INFO cursor_info = {100, v};
	SetConsoleCursorInfo(hand, &cursor_info);
}
void gotoxy(int x, int y)
{
	COORD loc;
	loc.X = x;
	loc.Y = y;
	SetConsoleCursorPosition(hand, loc);
}

void printxy(char *str, int x, int y)
{
	gotoxy(x, y);
	printf("%s", str);
}


int surface[HEIGHT][WIDTH] = {0};
void print_surface()
{
	int x, y;
	for (x = 0; x < WIDTH; x++)
	{
		for (y = 0; y < HEIGHT; y++)
		{
			int row = y;
			int col = x;
			if (surface[row][col] == 0)
			{
				printxy("0", x, y);
			}
			else
			{
				printxy("1", x, y);
			}
		}
	}
}

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

void for_sleep(int max)
{
	int i;
	for (i = 0; i < max; i++)
	{
	}
}

void setColor(int color)
{
	SetConsoleTextAttribute(hand, color);
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
	hand = GetStdHandle(STD_OUTPUT_HANDLE);
	setCursorVisable(1);


	control_Block0();

	return 0;
}
