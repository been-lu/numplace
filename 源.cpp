#include"my.h"


void drawMap();//draw the map
void keyboard();//the keyboard hit
void mainWindow();//the mainwindow frame,select degree
void gameWindow();//the gamewindow frame
void endWindow();//the end window frame


void main() {
	makeList();
	generate();
	initgraph(800, 600);
	system("pause");
}


void keyboard()
{

	if (_kbhit() == 1)
	{
		fflush(stdin);
		int key, death = 0;
		key = _getch();
			{
				if ((key == 'w' || key == 'W') && curPo_y > 0)
				{
					curPo_y--;
				}
				if ((key == 's' || key == 'S') && curPo_y < 8)
				{
					curPo_y++;
				}
				if ((key == 'a' || key == 'A') && curPo_x > 0)
				{
					curPo_x--;
				}
				if ((key == 'd' || key == 'D') && curPo_x < 8)
				{
					curPo_x++;
				}
				if (key > '0' && key <= '9' && !map[curPo_x][curPo_y].isBlack)
					map[curPo_x][curPo_y].num = key - 48;
			}
		}
}