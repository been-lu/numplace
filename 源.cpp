#include"my.h"


void drawMap();//draw the map
void keyboard();//the keyboard hit
void mainWindow();//the mainwindow frame
void selectDegree();
void gameWindow();//the gamewindow frame
void endWindow();//the end window frame


void main() {
	

	loadimage(&background,_T("D:\\repository\\numplace\\pic\\background.png"),800,600);
	loadimage(&mWindow, _T("D:\\repository\\numplace\\pic\\mwindow.png"), 800, 600);
	loadimage(&sWindow, _T("D:\\repository\\numplace\\pic\\swindow.png"), 800, 600);
	loadimage(&success, _T("D:\\repository\\numplace\\pic\\success.png"), 800, 600);
	loadimage(&fail, _T("D:\\repository\\numplace\\pic\\fail.png"), 800, 600);
	loadimage(&eWindow, _T("D:\\repository\\numplace\\pic\\ewindow.png"), 800, 600);
	loadimage(&b1, _T("D:\\repository\\numplace\\pic\\b1.png"), 40, 40);
	loadimage(&b2, _T("D:\\repository\\numplace\\pic\\b2.png"), 40, 40);
	loadimage(&b3, _T("D:\\repository\\numplace\\pic\\b3.png"), 40, 40); 
	loadimage(&b4, _T("D:\\repository\\numplace\\pic\\b4.png"), 40, 40);
	loadimage(&b5, _T("D:\\repository\\numplace\\pic\\b5.png"), 40, 40); 
	loadimage(&b6, _T("D:\\repository\\numplace\\pic\\b6.png"), 40, 40);
	loadimage(&b7, _T("D:\\repository\\numplace\\pic\\b7.png"), 40, 40);
	loadimage(&b8, _T("D:\\repository\\numplace\\pic\\b8.png"), 40, 40);
	loadimage(&b9, _T("D:\\repository\\numplace\\pic\\b9.png"), 40, 40);
	loadimage(&g1, _T("D:\\repository\\numplace\\pic\\g1.png"), 40, 40);
	loadimage(&g2, _T("D:\\repository\\numplace\\pic\\g2.png"), 40, 40);
	loadimage(&g3, _T("D:\\repository\\numplace\\pic\\g3.png"), 40, 40);
	loadimage(&g4, _T("D:\\repository\\numplace\\pic\\g4.png"), 40, 40);
	loadimage(&g5, _T("D:\\repository\\numplace\\pic\\g5.png"), 40, 40);
	loadimage(&g6, _T("D:\\repository\\numplace\\pic\\g6.png"), 40, 40);
	loadimage(&g7, _T("D:\\repository\\numplace\\pic\\g7.png"), 40, 40);
	loadimage(&g8, _T("D:\\repository\\numplace\\pic\\g8.png"), 40, 40);
	loadimage(&g9, _T("D:\\repository\\numplace\\pic\\g9.png"), 40, 40);
	loadimage(&r1, _T("D:\\repository\\numplace\\pic\\r1.png"), 40, 40);
	loadimage(&r2, _T("D:\\repository\\numplace\\pic\\r2.png"), 40, 40);
	loadimage(&r3, _T("D:\\repository\\numplace\\pic\\r3.png"), 40, 40);
	loadimage(&r4, _T("D:\\repository\\numplace\\pic\\r4.png"), 40, 40);
	loadimage(&r5, _T("D:\\repository\\numplace\\pic\\r5.png"), 40, 40);
	loadimage(&r6, _T("D:\\repository\\numplace\\pic\\r6.png"), 40, 40);
	loadimage(&r7, _T("D:\\repository\\numplace\\pic\\r7.png"), 40, 40);
	loadimage(&r8, _T("D:\\repository\\numplace\\pic\\r8.png"), 40, 40);
	loadimage(&r9, _T("D:\\repository\\numplace\\pic\\r9.png"), 40, 40);
	loadimage(&s, _T("D:\\repository\\numplace\\pic\\s.png"), 40, 40);
	
	initgraph(800, 600);
	mainWindow();
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
			if (key == ' ') {
				end_time = clock_t();
				endWindow();
			}
		}
		drawMap();
	}
}

void endWindow() {
	if (checkAll())
		putimage(0, 0, &success);
	else
		putimage(0, 0, &fail);

	//time undone

	while (1) 
		if (_kbhit() == 1)
			break;
	putimage(0, 0, &eWindow);

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
	case 50:; break;
	default:
		break;
	}

}

void drawMap() {

}

void selectDegree() {
	putimage(0, 0, &sWindow);

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
	start_time = clock_t();

}

void mainWindow() {
	putimage(0, 0, &mWindow);
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