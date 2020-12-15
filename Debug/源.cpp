#include"my.h"


void drawMap();//draw the game map
bool keyboard();//the keyboard hit
void mainWindow();//the mainwindow frame
void selectDegree();
void gameWindow();//the gamewindow frame
void endWindow();//the end window frame


void main() {
	//loading images
	{
		loadimage(&background, _T("pic\\background.png"), 800, 600);
		loadimage(&mWindow, _T("pic\\mwindow.png"), 800, 600);
		loadimage(&sWindow, _T("pic\\swindow.png"), 800, 600);
		loadimage(&success, _T("pic\\success.png"), 800, 600);
		loadimage(&fail, _T("pic\\fail.png"), 800, 600);
		loadimage(&eWindow, _T("pic\\ewindow.png"), 800, 600);
		loadimage(&b1, _T("pic\\b1.png"), 40, 40);
		loadimage(&b2, _T("pic\\b2.png"), 40, 40);
		loadimage(&b3, _T("pic\\b3.png"), 40, 40);
		loadimage(&b4, _T("pic\\b4.png"), 40, 40);
		loadimage(&b5, _T("pic\\b5.png"), 40, 40);
		loadimage(&b6, _T("pic\\b6.png"), 40, 40);
		loadimage(&b7, _T("pic\\b7.png"), 40, 40);
		loadimage(&b8, _T("pic\\b8.png"), 40, 40);
		loadimage(&b9, _T("D:pic\\b9.png"), 40, 40);
		loadimage(&g1, _T("pic\\g1.png"), 40, 40);
		loadimage(&g2, _T("pic\\g2.png"), 40, 40);
		loadimage(&g3, _T("pic\\g3.png"), 40, 40);
		loadimage(&g4, _T("pic\\g4.png"), 40, 40);
		loadimage(&g5, _T("pic\\g5.png"), 40, 40);
		loadimage(&g6, _T("pic\\g6.png"), 40, 40);
		loadimage(&g7, _T("pic\\g7.png"), 40, 40);
		loadimage(&g8, _T("pic\\g8.png"), 40, 40);
		loadimage(&g9, _T("pic\\g9.png"), 40, 40);
		loadimage(&r1, _T("pic\\r1.png"), 40, 40);
		loadimage(&r2, _T("pic\\r2.png"), 40, 40);
		loadimage(&r3, _T("pic\\r3.png"), 40, 40);
		loadimage(&r4, _T("pic\\r4.png"), 40, 40);
		loadimage(&r5, _T("pic\\r5.png"), 40, 40);
		loadimage(&r6, _T("pic\\r6.png"), 40, 40);
		loadimage(&r7, _T("pic\\r7.png"), 40, 40);
		loadimage(&r8, _T("pic\\r8.png"), 40, 40);
		loadimage(&r9, _T("pic\\r9.png"), 40, 40);
		loadimage(&zero, _T("pic\\0.png"), 40, 40);
		loadimage(&s, _T("pic\\s.png"), 40, 40);
		loadimage(&pointer, _T("pic\\pointer.png"), 40, 2);
	}
	
	initgraph(800, 600);
	mainWindow();
	//system("pause");
}


bool keyboard()
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
				end_time = clock();
				endWindow();
				return false;
			}
		}
	}
	return true;
}

void endWindow() {

	cleardevice();
	if (checkAll())
		putimage(0, 0, &success);
	else
		putimage(0, 0, &fail);


	//timer
	int time = (int)((double)(end_time - start_time) / CLOCKS_PER_SEC);
	int length = 0;
	int times[20];
	//time = 22;
	while (time != 0) {
		times[length++] = time % 10;
		time = time / 10;
	}
	int right_p = 320 + length * 40;
	while (--length != -1) {
		if (times[length] == 0)
			putimage(right_p - length * 40, 400, &zero);
		if (times[length] == 1)
			putimage(right_p - length * 40, 400, &b1);
		if (times[length] == 2)
			putimage(right_p - length * 40, 400, &b2);
		if (times[length] == 3)
			putimage(right_p - length * 40, 400, &b3);
		if (times[length] == 4)
			putimage(right_p - length * 40, 400, &b4);
		if (times[length] == 5)
			putimage(right_p - length * 40, 400, &b5);
		if (times[length] == 6)
			putimage(right_p - length * 40, 400, &b6);
		if (times[length] == 7)
			putimage(right_p - length * 40, 400, &b7);
		if (times[length] == 8)
			putimage(right_p - length * 40, 400, &b8);
		if (times[length] == 9)
			putimage(right_p - length * 40, 400, &b9);
	}
	putimage(right_p + 40, 400, &s);

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
	case 50: break;
	default:
		break;
	}

}

void draw() {
	cleardevice();
	putimage(0, 0, &background);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j].isBlack)
			{
				if (map[i][j].num == 1)
					putimage(220 + i * 40, 120 + j * 40, &b1);
				if (map[i][j].num == 2)
					putimage(220 + i * 40, 120 + j * 40, &b2);
				if (map[i][j].num == 3)
					putimage(220 + i * 40, 120 + j * 40, &b3);
				if (map[i][j].num == 4)
					putimage(220 + i * 40, 120 + j * 40, &b4);
				if (map[i][j].num == 5)
					putimage(220 + i * 40, 120 + j * 40, &b5);
				if (map[i][j].num == 6)
					putimage(220 + i * 40, 120 + j * 40, &b6);
				if (map[i][j].num == 7)
					putimage(220 + i * 40, 120 + j * 40, &b7);
				if (map[i][j].num == 8)
					putimage(220 + i * 40, 120 + j * 40, &b8);
				if (map[i][j].num == 9)
					putimage(220 + i * 40, 120 + j * 40, &b9);
			}
			else {
				if (degree != 3) {
					if (map[i][j].num == 0)
						putimage(220 + i * 40, 120 + j * 40, &zero);
					if (check(i, j)) {
						if (map[i][j].num == 1)
							putimage(220 + i * 40, 120 + j * 40, &g1);
						if (map[i][j].num == 2)
							putimage(220 + i * 40, 120 + j * 40, &g2);
						if (map[i][j].num == 3)
							putimage(220 + i * 40, 120 + j * 40, &g3);
						if (map[i][j].num == 4)
							putimage(220 + i * 40, 120 + j * 40, &g4);
						if (map[i][j].num == 5)
							putimage(220 + i * 40, 120 + j * 40, &g5);
						if (map[i][j].num == 6)
							putimage(220 + i * 40, 120 + j * 40, &g6);
						if (map[i][j].num == 7)
							putimage(220 + i * 40, 120 + j * 40, &g7);
						if (map[i][j].num == 8)
							putimage(220 + i * 40, 120 + j * 40, &g8);
						if (map[i][j].num == 9)
							putimage(220 + i * 40, 120 + j * 40, &g9);
					}
					else {
						if (map[i][j].num == 1)
							putimage(220 + i * 40, 120 + j * 40, &r1);
						if (map[i][j].num == 2)
							putimage(220 + i * 40, 120 + j * 40, &r2);
						if (map[i][j].num == 3)
							putimage(220 + i * 40, 120 + j * 40, &r3);
						if (map[i][j].num == 4)
							putimage(220 + i * 40, 120 + j * 40, &r4);
						if (map[i][j].num == 5)
							putimage(220 + i * 40, 120 + j * 40, &r5);
						if (map[i][j].num == 6)
							putimage(220 + i * 40, 120 + j * 40, &r6);
						if (map[i][j].num == 7)
							putimage(220 + i * 40, 120 + j * 40, &r7);
						if (map[i][j].num == 8)
							putimage(220 + i * 40, 120 + j * 40, &r8);
						if (map[i][j].num == 9)
							putimage(220 + i * 40, 120 + j * 40, &r9);
					}
				}
				if (degree == 3) {
					if (map[i][j].num == 0)
						putimage(220 + i * 40, 120 + j * 40, &zero);
					if (map[i][j].num == 1)
						putimage(220 + i * 40, 120 + j * 40, &g1);
					if (map[i][j].num == 2)
						putimage(220 + i * 40, 120 + j * 40, &g2);
					if (map[i][j].num == 3)
						putimage(220 + i * 40, 120 + j * 40, &g3);
					if (map[i][j].num == 4)
						putimage(220 + i * 40, 120 + j * 40, &g4);
					if (map[i][j].num == 5)
						putimage(220 + i * 40, 120 + j * 40, &g5);
					if (map[i][j].num == 6)
						putimage(220 + i * 40, 120 + j * 40, &g6);
					if (map[i][j].num == 7)
						putimage(220 + i * 40, 120 + j * 40, &g7);
					if (map[i][j].num == 8)
						putimage(220 + i * 40, 120 + j * 40, &g8);
					if (map[i][j].num == 9)
						putimage(220 + i * 40, 120 + j * 40, &g9);
				}
			}
		}
	}

	putimage(220 + curPo_x * 40, 160 + curPo_y * 40, &pointer);
	Sleep(50);

}

void selectDegree() {
	cleardevice();
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
	start_time = clock();
	gameWindow();
	

}

void mainWindow() {
	cleardevice();
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
	while (1) {
		draw();
		if (keyboard())
			continue;
		else
			break;
	}
	
}