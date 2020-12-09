#include"my.h"


void drawMap();//draw the map
void keyboard();//the keyboard hit
void mainWindow();//the mainwindow frame
void selectDegree();
void gameWindow();//the gamewindow frame
void endWindow();//the end window frame


void main() {
	//initgraph(800, 600);

	loadimage(&background,_T("D:\\repository\\numplace\\pic\\background.png"),800,600);
	

	makeUArea();
	resetMap();
	makeList();
	generate();
	makeMap();


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", solution[i][j]);
		printf("\n");
	}
	printf("\n\n");

	for (int i = 0; i < 30; i++)
		printf("%d %d \n", uArea[i][0], uArea[i][1]);
	printf("\n\n");

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			printf("%d ", map[i][j].num);
		printf("\n");
	}

	//mainWindow();
	system("pause");
}


void keyboard()
{
	if (_kbhit() == 1)
	{
		fflush(stdin);
		key = _getch();
		{
			if ((key == 'w' || key == 'W') && curPo_y > 0)
				curPo_y--;
			if ((key == 's' || key == 'S') && curPo_y < 8)
				curPo_y++;
			if ((key == 'a' || key == 'A') && curPo_x > 0)
				curPo_x--;
			if ((key == 'd' || key == 'D') && curPo_x < 8)
				curPo_x++;
			if (key > '0' && key <= '9' && !map[curPo_x][curPo_y].isBlack)
				map[curPo_x][curPo_y].num = key - 48;
			if (key == ' ')
				endWindow();
		}
		drawMap();
	}
}

void endWindow() {

}

void drawMap() {

}

void selectDegree() {
	int choose;
	while (1) {
		if (_kbhit() == 1)
		{
			fflush(stdin);
			choose = _getch();
			{
				if (choose != 49 && choose != 50 && choose != 51)
					continue;
				else
					break;
			}
		}
	}
	switch (choose)
	{
	case 49:degree = 1; break;
	case 50:degree = 2; break;
	case 51:degree = 3; break;
	default:
		break;
	}
	makeUArea();
	resetMap();
	makeList();
	generate();
	makeMap();
	gameWindow();

}

void mainWindow() {
	int choose;
	while (1) {
		if (_kbhit() == 1)
		{
			fflush(stdin);
			choose = _getch();
			{
				if (choose != 49 && choose != 50)
					continue;
				else
					break;
			}
		}
	}
	switch (choose)
	{
	case 49:selectDegree(); break;
	case 50:break;
	default:
		break;
	}
}

void gameWindow() {


}