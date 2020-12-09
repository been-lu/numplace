#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>
#include<conio.h>
#include<graphics.h>

#define MAP_WIDTH 800
#define MAP_LENGTH 600

typedef struct Node {
	int num;
	bool isBlack;
}n;

int list[9] = { 1,2,3,4,5,6,7,8,9 };//number list

int solution[9][9] = { 0 };//the answer
n map[9][9] = { 0,false };
clock_t start_time, end_time;//time
int degree=0;
int key=0;
int uArea[20][2][2];//uncovered area
int curPo_x = 0, curPo_y = 0;

void makeList() {
	srand((unsigned)time(NULL));
	int tmp, tmp1, tmp2;
	for (int i = 0; i < 17; i++) {
		tmp1 = rand() % 9;
		tmp2 = rand() % 9;
		tmp = list[tmp1];
		list[tmp1] = list[tmp2];
		list[tmp2] = tmp;
	}
	for (int i = 0; i < 9; i++)
		printf("%d ", list[i]);
	printf("\n\n");
}

bool check(int a, int b) {

	//line
	for (int i = 0; i < 9; i++)
		if (solution[a][i] == solution[a][b] && a != i)
			return false;
	//row
	for (int i = 0; i < 9; i++)
		if (solution[i][b] == solution[a][b] && b != i)
			return false;
	
	//area
	//area 1
	if (a < 3 && b < 3)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;
			}

	//area 2
	if (a >= 3 && a < 6 && b < 3)
		for (int i = 3; i < 6; i++)
			for (int j = 0; j < 3; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 3
	if (a >= 6 && a < 9 && b < 3)
		for (int i = 6; i < 9; i++)
			for (int j = 0; j < 3; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 4
	if (a < 3 && b >= 3 && b < 6)
		for (int i = 0; i < 3; i++)
			for (int j = 3; j < 6; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 5
	if (a >= 3 && a < 6 && b >= 3 && b < 6)
		for (int i = 3; i < 6; i++)
			for (int j = 3; j < 6; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 6
	if (a >= 6 && a < 9 && b >= 3 && b < 6)
		for (int i = 6; i < 9; i++)
			for (int j = 3; j < 6; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 7
	if (a < 3 && b >= 6 && b < 9)
		for (int i = 0; i < 3; i++)
			for (int j = 6; j < 9; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area 8
	if (a >= 3 && a < 6 && b >= 6 && b < 9)
		for (int i = 3; i < 6; i++)
			for (int j = 6; j < 9; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;

	//area9
	if (a >= 6 && a < 9 && b >= 6 && b < 9)
		for (int i = 6; i < 9; i++)
			for (int j = 6; j < 9; j++)
				if (solution[i][j] == solution[a][b] &&
					!(a == i && b == j))
					return false;
	

	return true;
}

void generate() {

	//�ο�https://blog.csdn.net/silentic/article/details/78031364���㷨
	solution[0][4] = solution[1][1] = solution[2][7] = solution[3][3] = solution[4][0] = solution[5][6] = solution[6][5] = solution[7][2] = solution[8][8] = list[0];
	solution[0][5] = solution[1][2] = solution[2][8] = solution[3][4] = solution[4][1] = solution[5][7] = solution[6][3] = solution[7][0] = solution[8][6] = list[1];
	solution[0][3] = solution[1][0] = solution[2][6] = solution[3][5] = solution[4][2] = solution[5][8] = solution[6][4] = solution[7][1] = solution[8][7] = list[2];
	solution[0][7] = solution[1][4] = solution[2][1] = solution[3][6] = solution[4][3] = solution[5][0] = solution[6][8] = solution[7][5] = solution[8][2] = list[3];
	solution[0][8] = solution[1][5] = solution[2][2] = solution[3][7] = solution[4][4] = solution[5][1] = solution[6][6] = solution[7][3] = solution[8][0] = list[4];
	solution[0][6] = solution[1][3] = solution[2][0] = solution[3][8] = solution[4][5] = solution[5][2] = solution[6][7] = solution[7][4] = solution[8][1] = list[5];
	solution[0][1] = solution[1][7] = solution[2][4] = solution[3][0] = solution[4][6] = solution[5][3] = solution[6][2] = solution[7][8] = solution[8][5] = list[6];
	solution[0][2] = solution[1][8] = solution[2][5] = solution[3][1] = solution[4][7] = solution[5][4] = solution[6][0] = solution[7][6] = solution[8][3] = list[7];
	solution[0][0] = solution[1][6] = solution[2][3] = solution[3][2] = solution[4][8] = solution[5][5] = solution[6][1] = solution[7][7] = solution[8][4] = list[8];



	int tmp, tmp1, tmp2;
	for (int i = 0; i < 3; i++) {
		tmp1 = rand() % 3;
		tmp2 = rand() % 3;
		for (int j = 1; j < tmp1; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				tmp = solution[i * 3 + j][k];
				solution[i * 3 + j][k] = solution[i * 3][k];
				solution[i * 3][k] = tmp;
			}
		}
		for (int j = 1; j < tmp2; j++)
		{
			for (int k = 0; k < 9; k++)
			{
				tmp = solution[k][i * 3 + j];
				solution[k][i * 3 + j] = solution[k][i * 3];
				solution[k][i * 3] = tmp;
			}
		}
	}
}
