#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#include "sysTools.h"
//#include "workMan.h"
/*
	0：空地
	1：目的地 ☆
	2：墙壁 ■
	4：箱子 □
	8：玩家 ♂
	*/
enum _state{
	space = 0,
	destination = 1,
	wall = 2,
	box = 4,
	player = 8,

} state;

int iWLX;
int iWLY;
int stepBackforwards = 8;
int stepBacked = 0;
int steps = 0;//玩家移动的步数


int map[13][14] = {
	{ space, space, space, space, wall, wall, wall, wall, wall, wall, space, space, space, space },
	{ space, space, space, space, wall, space, space, space, space, wall, space, space, space, space },
	{ space, wall, wall, wall, wall, space, space, box, box, wall, wall, wall, wall, wall },
	{ space, wall, space, space, space, wall, space, space, space, wall, space, space, space, wall },
	{ space, wall, space, box, space, space, space, box, space, space, space, box, space, wall },
	{ space, wall, space, space, space, wall, wall, space, wall, wall, wall, wall, wall, wall },
	{ wall, wall, wall, wall, box, wall, wall, space, space, space, space, space, space, wall },
	{ wall, space, space, space, box, space, wall, space, space, space, player, space, space, wall },
	{ wall, space, box, space, box, space, wall, space, wall, wall, wall, wall, wall, wall },
	{ wall, wall, space, space, box, space, wall, space, wall, destination, destination, destination, wall, space },
	{ space, wall, space, wall, wall, space, space, space, space, destination, destination, destination, wall, space },
	{ space, wall, space, space, space, space, wall, wall, destination, destination, destination, destination, wall, space },
	{ space, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, wall, space }
};

void drawMap(int map[][14]);
void MoveLeft(int map[][14]);
void MoveRight(int map[][14]);
void MoveUp(int map[][14]);
void MoveDown(int map[][14]);
void MoveUpBox(int map[][14]);
void MoveDownBox(int map[][14]);
void MoveRightBox(int map[][14]);
void MoveLeftBox(int map[][14]);
void MoveSpace(int map[][14]);
void MoveBackwords(int map[][14]);
void IsVictory(int map[13][14]);//是否胜利


void main(){
	HideCursor();//隐藏光标
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
			if (map[iWLY - 1][iWLX] == box || map[iWLY - 1][iWLX] == box + destination)//如果是箱子
			{
				if (map[iWLY - 2][iWLX] != wall&&map[iWLY - 2][iWLX] != box){//且箱子后边不是墙或者箱子
					MoveUp(map);
					MoveUpBox(map);
				}
			}
			else {//不是箱子
				if (map[iWLY - 1][iWLX] != wall)//不是墙
				MoveUp(map);//上移
				
			}
			break;
		case 'A':
		case 'a':
			if (map[iWLY][iWLX - 1] == box || map[iWLY][iWLX - 1] == box + destination)
			{
				if (map[iWLY][iWLX - 2] != wall&&map[iWLY][iWLX - 2] != box){
					MoveLeft(map);
					MoveLeftBox(map);
				}
			}
			else
			{
				if (map[iWLY][iWLX - 1] != wall)
					MoveLeft(map);//左移
			}
			
			break;
		case 'S':
		case 's':
			if (map[iWLY + 1][iWLX] == box || map[iWLY + 1][iWLX] == box + destination)
			{
				if (map[iWLY + 2][iWLX] != wall&&map[iWLY + 2][iWLX] != box){
					MoveDown(map);
					MoveDownBox(map);
				}
			}
			else
			{
				if (map[iWLY + 1][iWLX] != wall)
					MoveDown(map);//下移
			}
			break;
		case 'D':
		case 'd':
			if (map[iWLY][iWLX + 1] == box || map[iWLY][iWLX + 1] == box + destination)
			{
				if (map[iWLY][iWLX + 2] != wall&&map[iWLY][iWLX + 2] != box){
					MoveRight(map);
					MoveRightBox(map);
				}
			}
			else
			{
				if (map[iWLY][iWLX + 1] != wall)
					MoveRight(map);//右移
			}
			break;
		default:
			break;
		}
		IsVictory(map);
	}
}
void MoveLeft(int map[][14]){
	map[iWLY][iWLX] -= player;
	gotoxy(2 * iWLX, iWLY);
	if (map[iWLY][iWLX]==destination){
		printf("☆");
	}
	else{
		printf("  ");
	}
	map[iWLY][iWLX - 1] += player;
	gotoxy(2 *(iWLX-1), iWLY);
	printf("♂");
	
}

void MoveRight(int map[][14]){
	map[iWLY][iWLX] -= player;
	gotoxy(2 * iWLX, iWLY);
	if (map[iWLY][iWLX] == destination){
		printf("☆");
	}
	else{
		printf("  ");
	}
	map[iWLY][iWLX + 1] += player;
	gotoxy(2 * (iWLX + 1), iWLY);
	printf("♂");
}
void MoveUp(int map[][14]){
	map[iWLY][iWLX] -= player;
	gotoxy(2 * iWLX, iWLY);
	if (map[iWLY][iWLX] == destination){
		printf("☆");
	}
	else{
		printf("  ");
	}
	map[iWLY - 1][iWLX] += player;
	gotoxy(2 * iWLX, iWLY-1);
	printf("♂");
}
void MoveDown(int map[][14]){
	map[iWLY][iWLX] -= player;
	gotoxy(2 * iWLX, iWLY);
	if (map[iWLY][iWLX] == destination){
		printf("☆");
	}
	else{
		printf("  ");
	}
	map[iWLY + 1][iWLX] += player;
	gotoxy(2 * iWLX, iWLY+1);
	printf("♂");
}

void MoveLeftBox(int map[][14]){
	map[iWLY][iWLX - 2] += box;
	gotoxy(2 * (iWLX-2), iWLY);
	if (map[iWLY][iWLX - 2] == destination+box){
		printf("★");
	}
	else{
		printf("□");
	}
	map[iWLY][iWLX - 1] -= box;
}

void MoveRightBox(int map[][14]){
	map[iWLY][iWLX + 2] += box;
	gotoxy(2 * (iWLX + 2), iWLY);
	if (map[iWLY][iWLX + 2] == destination + box){
		printf("★");
	}
	else{
		printf("□");
	}
	map[iWLY][iWLX + 1] -= box;
}
void MoveUpBox(int map[][14]){
	map[iWLY - 2][iWLX] += box;
	gotoxy(2 * iWLX, iWLY-2);
	if (map[iWLY-2][iWLX] == destination + box){
		printf("★");
	}
	else{
		printf("□");
	}
	map[iWLY - 1][iWLX] -= box;
}
void MoveDownBox(int map[][14]){
	map[iWLY + 2][iWLX] += box;
	gotoxy(2 * iWLX, iWLY+2);
	if (map[iWLY+2][iWLX] == destination + box){
		printf("★");
	}
	else{
		printf("□");
	}
	map[iWLY + 1][iWLX] -= box;
}

//TODO
void MoveBackwords(int map[][14]){//回退功能

}



void drawMap(int map[13][14]){
	int i = 0, j = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 14; j++)
		{
			switch (map[i][j])
			{
			case space:
				printf("  ");
				break;
			case destination:
				printf("☆");
				break;
			case destination + box:
				printf("★");
				break;
			case wall:
				printf("■");
				break;
			case box:
				printf("□");
				break;
			case player:
			case player+destination:
				printf("♂");
				iWLX = j;//记录玩家所在位置
				iWLY = i;
				break;
			default:
				break;
			}
		}
		printf("\n");
	}
}

void IsVictory(int map[13][14]){
	int i = 0, j = 0;
	int isVictory = 0;
	for (i = 0; i < 13; i++)
	{
		for (j = 0; j < 14; j++)
		{
			switch (map[i][j])
			{
			case destination + box:
				isVictory++;
				break;
			case player:
			case player + destination:
				iWLX = j;//记录玩家所在位置
				iWLY = i;
				break;
			default:
				break;
			}
		}
	}
	if (isVictory == 10)
	{
		system("cls");
		printf("恭喜胜利!");
	}
}