#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

/*
	0：空地
	1：目的地 ☆
	2：墙壁 ■
	4：箱子 □
	8：玩家 ♂
	*/
int cor = 0, row = 0;

int map[13][14] = {
	{ 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0 },
	{ 0, 0, 0, 0, 2, 0, 0, 0, 0, 2, 0, 0, 0, 0 },
	{ 0, 2, 2, 2, 2, 0, 0, 4, 4, 2, 2, 2, 2, 2 },
	{ 0, 2, 0, 0, 0, 2, 0, 0, 0, 2, 0, 0, 0, 2 },
	{ 0, 2, 0, 4, 0, 0, 0, 4, 0, 0, 0, 4, 0, 2 },
	{ 0, 2, 0, 0, 0, 2, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 2, 2, 4, 2, 2, 0, 0, 0, 0, 0, 0, 2 },
	{ 2, 0, 0, 0, 4, 0, 2, 0, 0, 0, 8, 0, 0, 2 },
	{ 2, 0, 4, 0, 4, 0, 2, 0, 2, 2, 2, 2, 2, 2 },
	{ 2, 2, 0, 0, 4, 0, 2, 0, 2, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 2, 2, 0, 0, 0, 0, 1, 1, 1, 2, 0 },
	{ 0, 2, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 2, 0 },
	{ 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0 }
};

void drawMap(int map[][14]);
void MoveLeft(int map[][14]);
void MoveRight(int map[][14]);
void MoveUp(int map[][14]);
void MoveDown(int map[][14]);

int main(){
	drawMap(map);
	int num = 0;
	char key = 0;
	while (true)
	{
		key = _getch();//暂停程序运行，等待用户键盘输入
		switch (key)
		{
		case 'W':
		case 'w':
			MoveUp(map);
			break;
		case 'A':
		case 'a':
			MoveLeft(map);//左移
			break;
		case 'S':
		case 's':
			MoveDown(map);
			break;
		case 'D':
		case 'd':
			MoveRight(map);//右移
			break;
		default:
			break;
		}
		system("cls");
		drawMap(map);
	}
	return 0;
}

void drawMap(int map[13][14]){
	int i = 0, j = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j  < 14; j ++)
		{
			switch (map[i][j])
			{
			case 0:
				printf("  ");
				break;
			case 1:
				printf("☆");
				break;
			case 2:
				printf("■");
				break;
			case 4:
				printf("□");
				break;
			case 8:
				printf("♂");
				cor = i;
				row = j;//记录玩家所在位置
				break;
			default:
				break;
			}
		}
		printf("\n");
	}

}

void MoveLeft(int map[][14]){
	map[cor][row] = 0;
	map[cor][row-1] = 8;
}

void MoveRight(int map[][14]){
	map[cor][row] = 0;
	map[cor][row + 1] = 8;
}
void MoveUp(int map[][14]){
	map[cor][row] = 0;
	map[cor-1][row] = 8;
}
void MoveDown(int map[][14]){
	map[cor][row] = 0;
	map[cor +1][row] = 8;
}


