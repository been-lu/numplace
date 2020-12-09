#include"my.h"


void drawMap();//draw the map
void getKey();//the keyboard hit
void mainWindow();//the mainwindow frame,select degree
void gameWindow();//the gamewindow frame
void endWindow();//the end window frame


void main() {
	makeList();
	generate();
	initgraph(800, 600);
	system("pause");
}